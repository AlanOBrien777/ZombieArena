#include "Virus.h"
#include "textureHolder.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <ResourcePath.hpp>

void Virus::spawn(float startX, float startY, int type, int seed)
{
	switch (type)
	{
	case 0:
		// virus
		m_Sprite = Sprite(TextureHolder::GetTexture(resourcePath()+"graphics/infected.png"));
		m_Speed = VIRUS_SPEED;
		m_Health = VIRUS_HEALTH;
		break;
	}

	// Prevent virus from bunching
	srand((int)time(0) * seed);
	// Somewhere between 70 and 100
	float modifier = (rand() % MAX_VARIANCE) + OFFSET;
	// Express as a fraction of 1
	modifier /= 100; // Now equals between .7 and 1
	m_Speed *= modifier;

	m_Position.x = startX;
	m_Position.y = startY;

	m_Sprite.setOrigin(30, 30);
	m_Sprite.setPosition(m_Position);

}



bool Virus::isAlive()
{
	return m_Alive;
}

FloatRect Virus::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Virus::getSprite()
{
	return m_Sprite;
}

void Virus::update(float elapsedTime, Vector2f playerLocation)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;
    
    // Update the zombie position variables
    if (playerX > m_Position.x)
    {
        m_Position.x = m_Position.x + m_Speed * elapsedTime;
    }
    
    if (playerY > m_Position.y)
    {
        m_Position.y = m_Position.y + m_Speed * elapsedTime;
    }
    
    if (playerX < m_Position.x)
    {
        m_Position.x = m_Position.x - m_Speed * elapsedTime;
    }
    
    if (playerY < m_Position.y)
    {
        m_Position.y = m_Position.y - m_Speed * elapsedTime;
    }

	if (m_Position.x < 200 && m_Position.y < 99) {
		m_Position.y++;
	}

	if (m_Position.x > 250 && m_Position.y < 100 && m_Position.x < 260) {
		m_Position.x = 250;
	}

	if (m_Position.x > 149 && m_Position.y < 101 && m_Position.x < 200) {
		m_Position.y = 101;
	}

	if (m_Position.x < 151 && m_Position.y < 201) {
		m_Position.x = 151;
	}

	if (m_Position.x > 250 && m_Position.y < 100 && m_Position.x < 301) {
		m_Position.y = 100;
	}

	if (m_Position.x > 300 && m_Position.y < 199 && m_Position.x < 310) {
		m_Position.y-=.5;
	}

	if (m_Position.x > 300 && m_Position.y < 200 && m_Position.x < 351) {
		m_Position.y = 200;
	}

	if (m_Position.x < 353 && m_Position.y < 201 && m_Position.x > 340) {
		m_Position.y -= .5;
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

	if (m_Position.x > 699 && m_Position.y < 201 && m_Position.x < 720) {
		m_Position.y -= .5;
	}

	if (m_Position.x > 700 && m_Position.y < 200 && m_Position.x < 750) {
		m_Position.y = 200;
	}

	if (m_Position.x < 752 && m_Position.y < 201 && m_Position.x > 725) {
		m_Position.y -= .5;
	}

	if (m_Position.x > 750 && m_Position.y < 100 && m_Position.x < 800) {
		m_Position.y = 100;
	}

	if (m_Position.x < 802 && m_Position.y < 100 && m_Position.x > 790) {
		m_Position.x = 802;
	}

	if (m_Position.x > 850 && m_Position.y < 100 && m_Position.x < 860) {
		m_Position.x = 850;
	}

	if (m_Position.x > 851 && m_Position.y < 101 && m_Position.x < 900) {
		m_Position.y = 101;
	}

	if (m_Position.x > 899 && m_Position.y < 301) {
		m_Position.x = 899;
	}

	if (m_Position.x > 899 && m_Position.y < 303 && m_Position.x < 955) {
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
		m_Position.x -= .5;
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
		m_Position.x -= .5;
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

	if (m_Position.x < 100 && m_Position.y > 800 && m_Position.x > 90) {
		m_Position.x = 100;
	}

	if (m_Position.x > 95 && m_Position.y > 790 && m_Position.x < 251 && m_Position.y < 801) {
		m_Position.x += .5;
	}

	if (m_Position.x < 250 && m_Position.y > 700 && m_Position.x > 240 && m_Position.y < 800) {
		m_Position.x = 250;
	}

	if (m_Position.x > 100 && m_Position.y > 700 && m_Position.x < 251 && m_Position.y < 710) {
		m_Position.x += .5;
	}

	if (m_Position.x < 101 && m_Position.y > 650 && m_Position.x > 95 && m_Position.y < 702) {
		m_Position.x = 101;
	}

	if (m_Position.y > 650 && m_Position.x < 102 && m_Position.y < 658) {
		m_Position.y = 650;
	}

	if (m_Position.y > 590 && m_Position.x < 250 && m_Position.y < 600) {
		m_Position.x += .5;
	}

	if (m_Position.x < 250 && m_Position.y > 550 && m_Position.x > 95 && m_Position.y < 600) {
		m_Position.x = 250;
	}

	if (m_Position.y > 548 && m_Position.x < 250 && m_Position.y < 555) {
		m_Position.x += .5;
	}

	if (m_Position.y > 495 && m_Position.x < 200 && m_Position.y < 500) {
		m_Position.x += .5;
	}

	if (m_Position.x < 200 && m_Position.y > 400 && m_Position.x > 195 && m_Position.y < 501) {
		m_Position.x = 200;
	}

	if (m_Position.y > 400 && m_Position.x < 200 && m_Position.y < 405) {
		m_Position.x += .5;
	}

	if (m_Position.y > 195 && m_Position.x < 150 && m_Position.y < 203) {
		m_Position.y = 203;
	}

	//end of thee collision for the outer wall

	//collision for inner obstaces
	//square
	if (m_Position.x <= 700 && m_Position.y > 550 && m_Position.x >= 550 && m_Position.y < 560) {
		m_Position.x-=.5;
	}

	if (m_Position.x <= 700 && m_Position.y > 690 && m_Position.x >= 550 && m_Position.y < 700) {
		m_Position.x-= .5;
	}

	if (m_Position.x < 560 && m_Position.y >= 550 && m_Position.x > 550 && m_Position.y <= 700) {
		m_Position.y-= .5;
	}

	if (m_Position.x < 700 && m_Position.y >= 550 && m_Position.x > 690 && m_Position.y <= 700) {
		m_Position.y-= .5;
	}

	//end of square and start of L ish thing

	if (m_Position.x < 410 && m_Position.y >= 200 && m_Position.x > 400 && m_Position.y <= 450) {
		m_Position.y-=.5;
	}

	if (m_Position.x < 452 && m_Position.y >= 200 && m_Position.x > 440 && m_Position.y <= 350) {
		m_Position.y+=.5;
	}

	if (m_Position.x < 452 && m_Position.y >= 400 && m_Position.x > 440 && m_Position.y <= 450) {
		m_Position.y -= .5;
	}

	if (m_Position.x < 550 && m_Position.y >= 350 && m_Position.x > 540 && m_Position.y <= 400) {
		m_Position.y -= .5;
	}

	if (m_Position.x <= 450 && m_Position.y > 200 && m_Position.x >= 400 && m_Position.y < 220) {
		m_Position.x -= .5;
	}

	if (m_Position.x <= 450 && m_Position.y > 430 && m_Position.x >= 400 && m_Position.y < 450) {
		m_Position.x -= .5;
	}

	if (m_Position.x <= 550 && m_Position.y > 348 && m_Position.x >= 452 && m_Position.y < 375) {
		m_Position.x += .5;
	}

	if (m_Position.x <= 550 && m_Position.y > 375 && m_Position.x >= 452 && m_Position.y < 402) {
		m_Position.x += .5;
	}

	// end of L ish thing

	//start of the random rectangles

	if (m_Position.x < 265 && m_Position.y >= 300 && m_Position.x > 250 && m_Position.y <= 350) {
		m_Position.y -= .5;
	}

	if (m_Position.x < 350 && m_Position.y >= 300 && m_Position.x > 335 && m_Position.y <= 350) {
		m_Position.y -= .5;
	}

	if (m_Position.x <= 350 && m_Position.y > 300 && m_Position.x >= 250 && m_Position.y < 315) {
		m_Position.x -= .5;
	}

	if (m_Position.x <= 350 && m_Position.y > 335 && m_Position.x >= 250 && m_Position.y < 350) {
		m_Position.x -= .5;
	}




	if (m_Position.x < 765 && m_Position.y >= 400 && m_Position.x > 750 && m_Position.y <= 450) {
		m_Position.y -= .5;
	}

	if (m_Position.x < 850 && m_Position.y >= 400 && m_Position.x > 815 && m_Position.y <= 450) {
		m_Position.y -= .5;
	}

	if (m_Position.x <= 850 && m_Position.y > 400 && m_Position.x >= 750 && m_Position.y < 415) {
		m_Position.x -= .5;
	}

	if (m_Position.x <= 850 && m_Position.y > 435 && m_Position.x >= 750 && m_Position.y < 450) {
		m_Position.x -= .5;
	}





	if (m_Position.x < 675 && m_Position.y >= 250 && m_Position.x > 650 && m_Position.y <= 350) {
		m_Position.y -= .5;
	}

	if (m_Position.x < 700 && m_Position.y >= 250 && m_Position.x > 675 && m_Position.y <= 350) {
		m_Position.y -= .5;
	}

	if (m_Position.x <= 700 && m_Position.y > 248 && m_Position.x >= 650 && m_Position.y < 275) {
		m_Position.x -= .5;
	}

	if (m_Position.x <= 700 && m_Position.y > 320 && m_Position.x >= 650 && m_Position.y < 352) {
		m_Position.x -= .5;
	}


	if (m_Position.x < 375 && m_Position.y >= 650 && m_Position.x > 350 && m_Position.y <= 750) {
		m_Position.y -= .5;
	}

	if (m_Position.x < 400 && m_Position.y >= 650 && m_Position.x > 375 && m_Position.y <= 750) {
		m_Position.y -= .5;
	}

	if (m_Position.x <= 400 && m_Position.y > 648 && m_Position.x >= 350 && m_Position.y < 675) {
		m_Position.x -= .5;
	}

	if (m_Position.x <= 400 && m_Position.y > 720 && m_Position.x >= 350 && m_Position.y < 752) {
		m_Position.x -= .5;
	}
    
    // Move the sprite
    m_Sprite.setPosition(m_Position);
    
    // Face the sprite in the correct direction
    float angle = (atan2(playerY - m_Position.y,
                         playerX - m_Position.x)
                   * 180) / 3.141;
    
    m_Sprite.setRotation(angle);
    
}


