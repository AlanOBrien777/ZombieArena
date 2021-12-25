#include <ResourcePath.hpp>
#include "../includes/player.h"
#include "../includes/textureHolder.h"


Player::Player() {

    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;

    // Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(resourcePath()+"graphics/healthy.png"));


    // Set the origin of the sprite to the centre for smooth rotation
    m_Sprite.setOrigin(30, 30);

}


void Player::spawn(IntRect arena, Vector2f resolution, int tileSize) {

	// Place the player in the middle of the arena
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;

	// Copy the details of the arena to the player's m_Arena
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;

	m_Arena.height = arena.height;

	// Remember how big the tiles are in this arena
	m_TileSize = tileSize;

	// Store the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;

	/*for (int w = 0; w < m_Arena.width; w++) {
		for (int h = 0; h < m_Arena.height; h++) {
			
			if (map[(h * 20) + w] == 1) {
				
			}
		}
	}*/
}

void Player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
	m_Sprite = Sprite(TextureHolder::GetTexture(resourcePath()+"graphics/healthy.png"));
	m_Sprite.setOrigin(30, 30);
}

Time Player::getLastHitTime() {
	return m_LastHit;
}

bool Player::hit(Time timeHit) {
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200) {
		m_LastHit = timeHit;
		m_Health -= 10;
		m_Sprite = Sprite(TextureHolder::GetTexture(resourcePath()+"graphics/infected.png"));
		m_Sprite.setOrigin(30, 30);
		return true;
	}
	else {
		return false;
	}
}

FloatRect Player::getPosition() {
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter() {
	return m_Position;
}

float Player::getRotation() {
	return m_Sprite.getRotation();
}

Sprite Player::getSprite() {
	return m_Sprite;
}

int Player::getHealth() {
	return m_Health;
}

void Player::moveLeft() {
	m_LeftPressed = true;
}

void Player::moveRight() {
	m_RightPressed = true;
}
void Player::moveUp() {
	m_UpPressed = true;
}

void Player::moveDown() {
	m_DownPressed = true;
}

void Player::stopLeft() {
	m_LeftPressed = false;
}
void Player::stopRight() {
	m_RightPressed = false;
}
void Player::stopUp() {
	m_UpPressed = false;
}
void Player::stopDown() {
	m_DownPressed = false;
}





void Player::update(float elapsedTime, Vector2i mousePosition) {

	if (m_UpPressed) {
		m_Position.y -= m_Speed * elapsedTime;
	}

	if (m_DownPressed) {
		m_Position.y += m_Speed * elapsedTime;
	}

	if (m_RightPressed) {
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed) {
		m_Position.x -= m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);

	// Keep the player in the arena
	if (m_Position.x > m_Arena.width - m_TileSize) {
		m_Position.x = m_Arena.width - m_TileSize;
	}						
							
	if (m_Position.x < m_Arena.left + m_TileSize) {
		m_Position.x = m_Arena.left + m_TileSize;
	}						
	if (m_Position.y > m_Arena.height - m_TileSize) {
		m_Position.y = m_Arena.height - m_TileSize;
	}						
							
	if (m_Position.y < m_Arena.top + m_TileSize) {
		m_Position.y = m_Arena.top + m_TileSize;
	}

	if (m_Position.x < 200 && m_Position.y < 99) {
		m_Position.x = 200;
	}

	if (m_Position.x >250 && m_Position.y < 100 && m_Position.x < 260) {
		m_Position.x = 250;
	} 

	if (m_Position.x > 149 && m_Position.y < 101 && m_Position.x < 200) {
		m_Position.y = 101;
	}

	if (m_Position.x < 151 && m_Position.y < 201) {
		m_Position.x = 151;
	}

	if (m_Position.x > 250 && m_Position.y < 100 && m_Position.x < 301) {
		m_Position.y=100;
	}

	if (m_Position.x > 300 && m_Position.y < 199 && m_Position.x < 310) {
		m_Position.x = 300;
	}

	if (m_Position.x > 300 && m_Position.y < 200 && m_Position.x < 351) {
		m_Position.y = 200;
	}

	if (m_Position.x < 353 && m_Position.y < 201 && m_Position.x > 350) {
		m_Position.x = 353;
	}

	if (m_Position.x > 350 && m_Position.y < 101 && m_Position.x < 550) {
		m_Position.y = 101;
	}

	if (m_Position.x < 552 && m_Position.y < 102 && m_Position.x > 540) {
		m_Position.x = 552;
	}

	if (m_Position.x > 600 && m_Position.y < 102 && m_Position.x < 610) {
		m_Position.x = 600;
	}

	if (m_Position.x > 601 && m_Position.y < 101 && m_Position.x < 700) {
		m_Position.y = 101;
	}
	
	if (m_Position.x > 699 && m_Position.y < 201 && m_Position.x <720) {
		m_Position.x = 699;
	}

	if (m_Position.x > 700 && m_Position.y < 200 && m_Position.x < 750) {
		m_Position.y = 200;
	}

	if (m_Position.x < 752 && m_Position.y < 201 && m_Position.x > 725) {
		m_Position.x = 752;
	}

	if (m_Position.x > 750 && m_Position.y < 100 && m_Position.x < 800) {
		m_Position.y = 100;
	}

	if (m_Position.x < 802 && m_Position.y < 100&& m_Position.x > 790) {
		m_Position.x = 802;
	}

	if (m_Position.x >850 && m_Position.y < 100 && m_Position.x < 860) {
		m_Position.x = 850;
	}

	if (m_Position.x > 851 && m_Position.y < 101 && m_Position.x< 900) {
		m_Position.y = 101;
	}

	if (m_Position.x > 899 && m_Position.y < 301) {
		m_Position.x = 899;
	}

	if (m_Position.x > 899 && m_Position.y < 303  && m_Position.x < 955) {
		m_Position.y = 303;
	}

	if (m_Position.x > 899 && m_Position.y > 350 && m_Position.x < 955 && m_Position.y < 360) {
		m_Position.y = 350;
	}

	if (m_Position.x > 899 && m_Position.y < 500 && m_Position.y > 351) {
		m_Position.x = 899;
	}

	if (m_Position.x > 899 && m_Position.y < 502 && m_Position.x < 955 && m_Position.y > 495) {
		m_Position.y = 502;
	}

	if (m_Position.x > 800 && m_Position.y > 550 && m_Position.x < 955 && m_Position.y < 556) {
		m_Position.y = 550;
	}

	if (m_Position.x > 800 && m_Position.y > 551 && m_Position.x < 850 && m_Position.y < 601) {
		m_Position.x = 800;
	}

	if (m_Position.x > 800 && m_Position.y < 603 && m_Position.x < 850 && m_Position.y > 595) {
		m_Position.y = 603;
	}

	if (m_Position.x > 848 && m_Position.y > 599 && m_Position.x < 855 && m_Position.y < 652) {
		m_Position.x = 848;
	}

	if (m_Position.x > 800 && m_Position.y > 650 && m_Position.x < 850 && m_Position.y < 660) {
		m_Position.y = 650;
	}

	if (m_Position.x > 800 && m_Position.y > 651 && m_Position.x < 810 && m_Position.y < 701) {
		m_Position.x = 800;
	}

	if (m_Position.x > 800 && m_Position.y > 690 && m_Position.x < 902 && m_Position.y < 700) {
		m_Position.y = 700;
	}

	if (m_Position.x > 898 && m_Position.y >= 700 && m_Position.x < 910) {
		m_Position.x = 898;
	}

	if (m_Position.x > 650 && m_Position.y > 900 && m_Position.x < 899 && m_Position.y < 960) {
		m_Position.y = 900;
	}

	if (m_Position.x > 647 && m_Position.y > 900 && m_Position.x < 659) {
		m_Position.x = 647;
	}

	if (m_Position.x > 595 && m_Position.y > 900 && m_Position.x < 600) {
		m_Position.x = 600;
	}

	if (m_Position.x > 350 && m_Position.y > 900 && m_Position.x < 600 && m_Position.y < 911) {
		m_Position.y = 900;
	}

	if (m_Position.x > 350 && m_Position.y > 900 && m_Position.x < 358) {
		m_Position.x = 350;
	}

	if (m_Position.x > 290 && m_Position.y > 900 && m_Position.x < 301) {
		m_Position.x = 301;
	}

	if (m_Position.x > 150 && m_Position.y < 910 && m_Position.x < 300 && m_Position.y > 899) {
		m_Position.y = 899;
	}

	if (m_Position.x > 149 && m_Position.y > 900 && m_Position.x < 160) {
		m_Position.x = 149;
	}

	if (m_Position.x <100 && m_Position.y > 800 && m_Position.x > 90) {
		m_Position.x = 100;
	}

	if (m_Position.x > 95 && m_Position.y > 790 && m_Position.x < 251 && m_Position.y < 801) {
		m_Position.y = 801;
	}

	if (m_Position.x < 250 && m_Position.y > 700 && m_Position.x > 240 && m_Position.y <800) {
		m_Position.x = 250;
	}

	if (m_Position.x > 100 && m_Position.y > 700 && m_Position.x < 251 && m_Position.y < 710) {
		m_Position.y = 700;
	}

	if (m_Position.x < 101 && m_Position.y > 650 && m_Position.x > 95 && m_Position.y < 702) {
		m_Position.x = 101;
	}

	if (m_Position.y > 650 && m_Position.x < 102 && m_Position.y < 658) {
		m_Position.y = 650;
	}

	if (m_Position.y > 590 && m_Position.x < 250 && m_Position.y < 600) {
		m_Position.y = 600;
	}

	if (m_Position.x < 250 && m_Position.y > 550 && m_Position.x > 95 && m_Position.y < 600) {
		m_Position.x = 250;
	}

	if (m_Position.y > 548 && m_Position.x < 250 && m_Position.y < 555) {
		m_Position.y = 548;
	}

	if (m_Position.y > 495 && m_Position.x < 200 && m_Position.y < 500) {
		m_Position.y = 500;
	}

	if (m_Position.x < 200 && m_Position.y > 400 && m_Position.x > 195 && m_Position.y < 501) {
		m_Position.x = 200;
	}

	if (m_Position.y > 400 && m_Position.x < 200 && m_Position.y < 405) {
		m_Position.y = 400;
	}

	if (m_Position.y > 195 && m_Position.x < 150 && m_Position.y < 203) {
		m_Position.y = 203;
	}

	//end of thee collision for the outer wall

	//collision for inner obstaces
	//square
	if (m_Position.x <= 700 && m_Position.y > 550 && m_Position.x >=550  && m_Position.y < 560) {
		m_Position.y = 550;
	}

	if (m_Position.x <= 700 && m_Position.y > 690 && m_Position.x >= 550 && m_Position.y < 700) {
		m_Position.y = 700;
	}

	if (m_Position.x < 560 && m_Position.y >= 550 && m_Position.x > 550 && m_Position.y <= 700) {
		m_Position.x = 550;
	}

	if (m_Position.x < 700 && m_Position.y >= 550 && m_Position.x > 690 && m_Position.y <= 700) {
		m_Position.x = 700;
	}

	//end of square and start of L ish thing

	if (m_Position.x < 410 && m_Position.y >= 200 && m_Position.x > 400 && m_Position.y <= 450) {
		m_Position.x = 400;
	}

	if (m_Position.x < 452 && m_Position.y >= 200 && m_Position.x > 440 && m_Position.y <= 350) {
		m_Position.x = 452;
	}

	if (m_Position.x < 452 && m_Position.y >= 400 && m_Position.x > 440 && m_Position.y <= 450) {
		m_Position.x = 452;
	}

	if (m_Position.x < 550 && m_Position.y >= 350 && m_Position.x > 540 && m_Position.y <= 400) {
		m_Position.x = 550;
	}

	if (m_Position.x <= 450 && m_Position.y > 200 && m_Position.x >= 400 && m_Position.y < 220) {
		m_Position.y = 200;
	}

	if (m_Position.x <= 450 && m_Position.y > 430 && m_Position.x >= 400 && m_Position.y < 450) {
		m_Position.y = 450;
	}

	if (m_Position.x <= 550 && m_Position.y > 348 && m_Position.x >= 452 && m_Position.y < 375) {
		m_Position.y = 348;
	}

	if (m_Position.x <= 550 && m_Position.y > 375 && m_Position.x >= 452 && m_Position.y < 402) {
		m_Position.y = 402;
	}

	// end of L ish thing

	//start of the random rectangles

	if (m_Position.x < 265 && m_Position.y >= 300 && m_Position.x > 250 && m_Position.y <= 350) {
		m_Position.x = 250;
	}

	if (m_Position.x < 350 && m_Position.y >= 300 && m_Position.x > 335 && m_Position.y <= 350) {
		m_Position.x = 350;
	}

	if (m_Position.x <= 350 && m_Position.y > 300 && m_Position.x >= 250 && m_Position.y < 315) {
		m_Position.y = 300;
	}

	if (m_Position.x <= 350 && m_Position.y > 335 && m_Position.x >= 250 && m_Position.y < 350) {
		m_Position.y = 350;
	}




	if (m_Position.x < 765 && m_Position.y >= 400 && m_Position.x > 750 && m_Position.y <= 450) {
		m_Position.x = 750;
	}

	if (m_Position.x < 850 && m_Position.y >= 400 && m_Position.x > 815 && m_Position.y <= 450) {
		m_Position.x = 850;
	}

	if (m_Position.x <= 850 && m_Position.y > 400 && m_Position.x >= 750 && m_Position.y < 415) {
		m_Position.y = 400;
	}

	if (m_Position.x <= 850 && m_Position.y > 435 && m_Position.x >= 750 && m_Position.y < 450) {
		m_Position.y = 450;
	}





	if (m_Position.x < 675 && m_Position.y >= 250 && m_Position.x > 650 && m_Position.y <= 350) {
		m_Position.x = 650;
	}

	if (m_Position.x < 700 && m_Position.y >= 250 && m_Position.x > 675 && m_Position.y <= 350) {
		m_Position.x = 700;
	}

	if (m_Position.x <= 700 && m_Position.y > 248 && m_Position.x >= 650 && m_Position.y < 275) {
		m_Position.y = 248;
	}

	if (m_Position.x <= 700 && m_Position.y > 320 && m_Position.x >= 650 && m_Position.y < 352) {
		m_Position.y = 352;
	}


	if (m_Position.x < 375 && m_Position.y >= 650 && m_Position.x > 350 && m_Position.y <= 750) {
		m_Position.x = 350;
	}

	if (m_Position.x < 400 && m_Position.y >= 650 && m_Position.x > 375 && m_Position.y <= 750) {
		m_Position.x = 400;
	}

	if (m_Position.x <= 400 && m_Position.y > 648 && m_Position.x >= 350 && m_Position.y < 675) {
		m_Position.y = 648;
	}

	if (m_Position.x <= 400 && m_Position.y > 720 && m_Position.x >= 350 && m_Position.y < 752) {
		m_Position.y = 752;
	}


	//------------------------------------------------------HERE IS WHERE YOU EDITED--------------------------------------------------------------------------------
	//int playerX = static_cast<int>(m_Position.x);
	//int playerY = static_cast<int>(m_Position.y);
							
	//int playerX{ m_Position.x };
	//int playerY{ m_Position.y };
							
	/*int playerX = (int)m_Position.x;
	int playerY = (int)m_Position.y;
							
	if (map[(playerY * 20) + playerX] == 1) {
		m_Position.y = m_Position.y;
		m_Position.x = m_Position.x;
	}*/



	

	// Calculate the angle the player is facing
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
		mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;

	m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed()
{
	// 20% speed upgrade
	m_Speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	// 20% max health upgrade
	m_MaxHealth += (START_HEALTH * .2);

}

void Player::increaseHealthLevel(int amount)
{
	m_Health += amount;

	// But not beyond the maximum
	if (m_Health > m_MaxHealth) {
		m_Health = m_MaxHealth;
	}
}