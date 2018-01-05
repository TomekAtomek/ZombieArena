#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>

class Zombie
{
private:
    const float BLOATER_SPEED = 40; 
    const float CHASER_SPEED = 80;
    const float CRAWLER_SPEED = 20;
    
    const float CRAWLER_HEALTH = 3;
    const float BLOATER_HEALTH = 5;
    const float CHASER_HEALTH = 1;
    
    const int MAX_VARIANCE = 30;
    const int OFFSET = 101 - MAX_VARIANCE;
    
    sf::Vector2f m_Position;
    sf::Sprite m_Sprtie;
    
    float m_Speed;
    
    float m_Health;
    
    bool m_isAlive;

public:
    bool hit();
    
    bool isAlive();
    
    void spawn(float startX, float startY, int type, int seed);
    
    sf::FloatRect getPosition();
    
    void update(float elapsedTime, sf::Vector2f playerPosition);
    
    sf::Sprite getSprite();
    
    
    
    
};

#endif // ZOMBIE_H
