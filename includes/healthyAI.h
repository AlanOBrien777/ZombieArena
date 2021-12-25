//
//  healthyAI.h
//
//

#ifndef healthyAI_hpp
#define healthyAI_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class healthyAI
{
private:
    // How fast is each ai?
    const float AI_SPEED = 65;

    // Make each AI vary its speed slightly
    const int MAX_VARIANCE = 30;
    const int OFFSET = 101 - MAX_VARIANCE;

    // Where is this AI?
    Vector2f m_Position;

    // A sprite for the AI
    Sprite m_Sprite;

    // How fast can this one run?
    float m_Speed{};

    // How much health has it got?
    float m_Health{};

    Time m_LastHit;

    // Is it still alive?
    bool m_Alive = true;

    // Public prototypes go here
public:

    // Find out if the AI is alive
    bool isAlive();

    // Spawn a new AI
    void spawn(float startX, float startY, int type, int seed);

    Time getLastHitTime();

    bool hit(Time timeHit);

    // Return a rectangle that is the position in the world
    FloatRect getPosition();

    // Get a copy of the sprite to draw
    Sprite getSprite();

    // Update the AI each frame
    void update(float elapsedTime, Vector2f playerLocation);
};
#endif /* healthyAI_hpp */


