#ifndef PLAYER_H
#define PLAYER_H

#include<SFML/Graphics.hpp>

class Player
{
public:
    Player();
    void spawn(sf::IntRect arena, sf::Vector2f resolution, uint16_t tileSize);
    void resetPlayerStats();
    bool hit(sf::Time timeHit);
    
    sf::Time getLastHitTime();
    sf::FloatRect getPosition();
    sf::Vector2f getCenter();
    float getRotation();
    sf::Sprite getSprite();
    uint16_t  getHEalth();
    
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    
    void update(float elapsedTime,sf::Vector2i mousePosition);
    void upgradeSpeed();
    void upgradeHealth();
    void increaseHealthLevel(uint16_t amount);
    
    
    
    
private:
    const float START_SPEED = 200.0f;
    const float START_HEALTH = 100.0f;
    
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    
    sf::Texture m_Texture;
    sf::Vector2f m_Resolution;
    
    sf::IntRect m_Arena;
    
    uint16_t m_TileSize;
    
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_RightPressed;
    bool m_LeftPressed;
    
    uint16_t m_Health;
    uint16_t m_MaxHealth;
    
    sf::Time m_LastHit;
    
    float m_Speed;
};

#endif // PLAYER_H
