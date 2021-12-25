#include <SFML/Graphics.hpp>
#include "player.h"
#include "virusArena.h"
#include "textureHolder.h"
#include "healthyAI.h"
#include <sstream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <ResourcePath.hpp>

using namespace sf;



int main() {
	Time roundTime;

	bool infected = false;

	TextureHolder holder;

	// The game will always be in one of four states
	enum class State { PAUSED, ROUND_START, MAIN_MENU, PLAYING };

	// Start with the MAIN_MENU state
	State state = State::MAIN_MENU;

	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Infection", Style::Fullscreen);

	// Create an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));
	// Clock for timing everything
	Clock clock;
	// How long has the PLAYING state been active?
	Time gameTimeTotal;
	// Where is the mouse in relation to world coordinates?
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates?
	Vector2i mouseScreenPosition;

	// Create an instance of the Player class
	Player player;

	// The boundaries of the arena
	IntRect arena;// 

	// Create the background
	VertexArray background;

	// Load the texture for our background vertex array
	Texture textureBackground = TextureHolder::GetTexture(resourcePath()+"graphics/background_sheet.png");

	

	// Prepare for a horde of viruses
	int numViruses = 0; // Number at start of wave 
	Virus* viruses = nullptr;

	// Hide the mouse pointer
	window.setMouseCursorVisible(false);

	//about the game
	int score = 0;
	int AIScore = 0;
	int totalWins = 0;

	
	
	//For the Main Menu
	Sprite spriteMainMenu;
	Texture textureMainMenu = TextureHolder::GetTexture(resourcePath()+"graphics/MainScreen.png");
	spriteMainMenu.setTexture(textureMainMenu);
	spriteMainMenu.setPosition(0, 0);

	//For the Main Menu
	Sprite spriteRoundOver;
	Texture textureRoundOver = TextureHolder::GetTexture(resourcePath()+"graphics/RoundOver.png");
	spriteRoundOver.setTexture(textureRoundOver);
	spriteRoundOver.setPosition(0, 0);

	//ImageScaling
	spriteMainMenu.setScale(resolution.x / 1920, resolution.y / 1080);
	spriteRoundOver.setScale(resolution.x / 1920, resolution.y / 1080);

	//Create a view for the hud
	View hudView(FloatRect(0, 0, resolution.x, resolution.y));

	//Loading up font
	Font font;
	font.loadFromFile(resourcePath()+"fonts/zombiecontrol.ttf");

	//paused
	Text pausedText;
	pausedText.setFont(font);
	pausedText.setCharacterSize(155);
	pausedText.setFillColor(Color::White);
	pausedText.setString("Press Enter |nTo Continue");

	//place in the middle of screen
	FloatRect pausedRect = pausedText.getLocalBounds();
	pausedText.setOrigin(pausedRect.left + pausedRect.width / 2.0f, pausedRect.top + pausedRect.height / 2.0f);
	pausedText.setPosition(resolution.x / 2, resolution.y / 2);

	// Score
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 0);

	// Score for Round end
	Text roundEndScoreText;
	roundEndScoreText.setFont(font);
	roundEndScoreText.setCharacterSize(120);
	roundEndScoreText.setFillColor(Color::Green);
	roundEndScoreText.setPosition(500,350);

	//load the high Score from a text file
	std::ifstream inputFile(resourcePath()+"gamedata/scores.txt");
	if (inputFile.is_open()) {
		inputFile >> totalWins;
		inputFile.close();
	}

	// Total Wins
	Text totalWinsText;
	totalWinsText.setFont(font);
	totalWinsText.setCharacterSize(55);
	totalWinsText.setFillColor(Color::White);
	totalWinsText.setPosition(resolution.x - 400, 0);
	std::stringstream s;
	s << "Total Wins:" << totalWins;
	totalWinsText.setString(s.str());


	// Timer bar
	RectangleShape roundTimer;
	roundTimer.setFillColor(Color::Red);
	roundTimer.setPosition(resolution.x * 0.33, resolution.y - 200);

	//When did we last update the hud
	int framesSinceLastHUDUpdate = 0;
	//how many frame intervals for hud update
	int fpsMeasurementFrameInterval = 1000;

	//prepare the hit sound
	SoundBuffer hitBuffer;
	hitBuffer.loadFromFile(resourcePath()+"sound/hit.wav");
	Sound hit;
	hit.setBuffer(hitBuffer);

	//Decide How many rounds will be played per game
	int Rounds = 0;

	//keep track of how many rounds have been played
	int RoundsPlayed = 0;

	//The main game loop
	while (window.isOpen()) {

	/*
	************************************************
	Handle input
	************************************************
	*/

	// Handle events
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::KeyPressed) {
				
				// Pause a game while playing
				if (event.key.code == Keyboard::Return && state == State::PLAYING) {
					state = State::PAUSED;
				}
				
				// Restart while paused
				else if (event.key.code == Keyboard::Return && state == State::PAUSED) {

					state = State::PLAYING;
					// Reset the clock so there isn't a frame jump
					clock.restart();
				}

				// Start a new game while in MAIN_MENU state
				else if (event.key.code == Keyboard::Num1 && state == State::MAIN_MENU) {
					state = State::ROUND_START;
					Rounds = 1;
					score = 0;
					AIScore = 0;
					player.resetPlayerStats();
					infected = false;
				}
				else if (event.key.code == Keyboard::Num3 && state == State::MAIN_MENU) {
					state = State::ROUND_START;
					Rounds = 3;
					score = 0;
					AIScore = 0;
					player.resetPlayerStats();
					infected = false;
				}

				else if (event.key.code == Keyboard::Num5 && state == State::MAIN_MENU) {
					state = State::ROUND_START;
					Rounds = 5;
					score = 0;
					AIScore = 0;
					player.resetPlayerStats();
					infected = false;
				}

				else if (event.key.code == Keyboard::Num7 && state == State::MAIN_MENU) {
					state = State::ROUND_START;
					Rounds = 7;
					score = 0;
					AIScore = 0;
					player.resetPlayerStats();
					infected = false;
				}

				else if (event.key.code == Keyboard::Num9 && state == State::MAIN_MENU) {
					state = State::ROUND_START;
					Rounds = 9;
					score = 0;
					AIScore = 0;
					player.resetPlayerStats();
					infected = false;
				}

				if (state == State::PLAYING) {
					
				}
			} //End if (event.type == Event::KeyPressed)
		}// End event polling

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}


		// Handle controls while playing
		if (state == State::PLAYING) {
				
			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				player.moveUp();
			}
			else {
				player.stopUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				player.moveDown();
			}
			else {
				player.stopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::A)) {
				player.moveLeft();
			}
			else {
				player.stopLeft();
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				player.moveRight();
			}
			else {
				player.stopRight();
			}


		} // End WASD while playing

		// Handle the Round Start state
		if (state == State::ROUND_START) {
			// Handle the player Starting the round
			if (event.key.code == Keyboard::Return) {
				infected = false;
				state = State::PLAYING;
			}
			if (state == State::PLAYING) {
				arena.width = 1000;
				arena.height = 1000;
				arena.left = 0;
				arena.top = 0;

				// Pass the vertex array by reference to the createBackground function
				int tileSize = createBackground(background, arena);

				// Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);


				// Create a horde of Viruses
				numViruses = 1;
				

				// Delete the previously allocated memory (if it exists)
				delete[] viruses;  // Note use of delete[] – should use [] when deleting arrays from heap. 
				viruses = createHorde(numViruses, arena);
				// Reset the clock so there isn't a frame jump
				clock.restart();
			}
		}// End levelling up

		/*
		************************************************
		UPDATE THE FRAME
		************************************************
		*/
		
		if (state == State::PLAYING) {

			// Update the delta time
			Time dt = clock.restart();
			// Update the total game time
			gameTimeTotal += dt;
			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();

			// Find the mouse pointer
			mouseScreenPosition = Mouse::getPosition(window);

			// Convert mouse position to world coordinates of mainView
			mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

			// Update the player
			player.update(dtAsSeconds, Mouse::getPosition());

			// Make a note of the players new position
			Vector2f playerPosition(player.getCenter());

			// Make the view centre around the player 
			mainView.setCenter(player.getCenter());

			// Loop through each virus and update them if alive
			for (int i = 0; i < numViruses; i++) {
				if (viruses[i].isAlive()) {
					viruses[i].update(dt.asSeconds(), playerPosition);
				}
			}


			if (Rounds == 1 && (score == 1 || AIScore == 1)) {
				if (score == 1) {
					totalWins++;
				}
				state = State::MAIN_MENU;
				std::ofstream outputFile(resourcePath()+"gamedata/scores.txt");
				outputFile << totalWins;
				outputFile.close();
			}
			else if (Rounds == 3 && (score == 2 || AIScore == 2)) {
				if (score == 2) {
					totalWins++;
				}
				state = State::MAIN_MENU;
				std::ofstream outputFile(resourcePath()+"gamedata/scores.txt");
				outputFile << totalWins;
				outputFile.close();
			}
			else if (Rounds == 5 && (score == 3 || AIScore == 3)) {
				if (score == 3) {
					totalWins++;
				}
				state = State::MAIN_MENU;
				std::ofstream outputFile(resourcePath()+"gamedata/scores.txt");
				outputFile << totalWins;
				outputFile.close();
			}
			else if (Rounds == 7 && (score == 4 || AIScore == 4)) {
				if (score == 4) {
					totalWins++;
				}
				state = State::MAIN_MENU;
				std::ofstream outputFile(resourcePath()+"gamedata/scores.txt");
				outputFile << totalWins;
				outputFile.close();
			}
			else if (Rounds == 9 && (score == 5 || AIScore == 5)) {
				if (score == 5) {
					totalWins++;
				}
				state = State::MAIN_MENU;
				std::ofstream outputFile(resourcePath()+"gamedata/scores.txt");
				outputFile << totalWins;
				outputFile.close();
			}

			// Have any viruses touched the player or healthy ai?
			for (int i = 0; i < numViruses; i++)
			{
				if (player.getPosition().intersects
				(viruses[i].getPosition()) && viruses[i].isAlive())
				{

					if (player.hit(gameTimeTotal))
					{
						infected = true;
						hit.play();
					}

				}
				
			}// End player touched


			//if 60 seconds have passed end the current round
			if (gameTimeTotal.asSeconds() >= 60 && !infected) {
				score+=1;
				state = State::ROUND_START;
				clock.restart();
				player.resetPlayerStats();
				
			}

			if (infected) {
				clock.restart();
				if (gameTimeTotal.asSeconds() >= 5) {
					AIScore++;
					player.resetPlayerStats();
					state = State::ROUND_START;
				}
			}

			roundTimer.setSize(Vector2f(gameTimeTotal.asSeconds()*4, 70));

			//increment the number of frames since the last hud calculation
			framesSinceLastHUDUpdate++;

			//calculate fps every fpsMeasurementFrameInterval frames
			if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval) {
				std::stringstream ssScore;
				std::stringstream ssAIScore;
				std::stringstream ssRoundEndScore;
				std::stringstream ssTotalWins;

				//update the score text
				ssScore << "AI: " << AIScore<<" - Player: "<< score;
				scoreText.setString(ssScore.str());

				//update the round end score text
				ssRoundEndScore << "AI: " << AIScore << " - Player: " << score;
				roundEndScoreText.setString(ssRoundEndScore.str());

				//update the total wins text
				ssTotalWins << "Total wins: " << totalWins;
				totalWinsText.setString(ssTotalWins.str());

				framesSinceLastHUDUpdate = 0;
			}//end hud update

		}// End updating the scene

	/*
	******************************************
	Draw the scene
	******************************************
	*/

		if (state == State::PLAYING) {
			window.clear();

			// set the mainView to be displayed in the window
			// And draw everything related to it
			window.setView(mainView);
			
			// Draw the background
			window.draw(background, &textureBackground);

			// Draw the viruses
			for (int i = 0; i < numViruses; i++) {
				window.draw(viruses[i].getSprite());
			}

			// Draw the player
			window.draw(player.getSprite());

			window.setView(hudView);
			window.draw(scoreText);
			window.draw(totalWinsText);
			window.draw(roundTimer);

			window.display();

			

		}

		if (state == State::ROUND_START) {
			window.draw(spriteRoundOver);
			window.draw(roundEndScoreText);
			window.display();
		}

		if (state == State::PAUSED) {
			window.draw(pausedText);
			window.display();
		}

		if (state == State::MAIN_MENU) {
			window.draw(spriteMainMenu);
			window.draw(scoreText);
			window.draw(totalWinsText);
			window.display();
		}


	}

	// Delete the previously allocated memory (if it exists)
	delete[] viruses;


	return 0;
}
