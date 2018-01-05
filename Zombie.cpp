#include "Zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>
#include <cmath>


void Zombie::spawn(float startX, float startY, int type, int seed)
{
    switch(type)
    {
        case 0:
        {
            m_Sprtie = sf::Sprite(TextureHolder::GetTexture("graphics/bloater.png"));
            m_Speed = 40;
            m_Health = 5;
            
            break;
        }
        case 1:
        {
            m_Sprtie = sf::Sprite(TextureHolder::GetTexture("graphics/chaser.png"));
            m_Speed = 70;
            m_Health = 1;
            
            break;
        }
        case 2:
        {
            m_Sprtie = sf::Sprite(TextureHolder::GetTexture("graphics/crawler.png"));
            m_Speed = 20;
            m_Health = 3;
            
            
            break;
        }
    }
    
    srand((int)time(0) * seed);
    
    float modifier = (rand() % MAX_VARIANCE) + OFFSET;
    
    modifier /= 100;
    
    m_Speed *= modifier;
    
    m_Position.x = startX;
    m_Position.y = startY;
    
    m_Sprtie.setOrigin(25,25);
    
    m_Sprtie.setPosition(m_Position);
    
    
}

bool Zombie::hit()
{
    --m_Health;
    
    if(m_Health < 0)
    {
        m_isAlive = false;
        m_Sprtie.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
        return true;
    }
    
    return false;
}


bool Zombie::isAlive()
{
    return m_isAlive;
}

sf::FloatRect Zombie::getPosition()
{
    return m_Sprtie.getGlobalBounds();
}

sf::Sprite Zombie::getSprite()
{
    return m_Sprtie;
}

void Zombie::update(float elapsedTime, sf::Vector2f playerPosition)
{
    float playerX = playerPosition.x;
    float playerY = playerPosition.y;
    
    if (playerX > m_Position.x)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
    
    if (playerY > m_Position.y)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    
    if (playerX < m_Position.x)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
    
    if (playerY < m_Position.y)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }
    
    m_Sprtie.setPosition(m_Position);
    
    float angle = (std::atan2(playerY - m_Position.y, playerX - m_Position.x)*180) / 3.41;
    
    m_Sprtie.setRotation(angle);
}


