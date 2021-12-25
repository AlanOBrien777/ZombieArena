//
//  zombie.h
//  Zombie Arena
//
//

#ifndef virus_hpp
#define virus_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Virus
{
private:
    // How fast is each virus type?
    const float VIRUS_SPEED = 100;

    // How tough is each virus type
    const float VIRUS_HEALTH = 1;

    // Make each virus vary its speed slightly
    const int MAX_VARIANCE = 30;
    const int OFFSET = 101 - MAX_VARIANCE;

    // Where is this virus?
    Vector2f m_Position;

    // A sprite for the virus
    Sprite m_Sprite;

    // How fast can this one run?
    float m_Speed;

    // How much health has it got?
    float m_Health;

    // Is it still alive?
    bool m_Alive = true;

    // Public prototypes go here
public:

    // Find out if the virus is alive
    bool isAlive();

    // Spawn a new virus
    void spawn(float startX, float startY, int type, int seed);

    // Return a rectangle that is the position in the world
    FloatRect getPosition();

    // Get a copy of the sprite to draw
    Sprite getSprite();

    // Update the virus each frame
    void update(float elapsedTime, Vector2f playerLocation);
};

#endif /* virus_hpp */
