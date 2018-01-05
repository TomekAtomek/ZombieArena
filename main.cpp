#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "ZombieArena.h"
#include "TextureHolder.h"




int main(int argc, char * argv[])
{
    TextureHolder textureHolder;
    
    enum class State{PAUSED, PLAYING, LEVELING_UP, GAME_OVER};
    
    State state = State::GAME_OVER;
    
    sf::Vector2f resolution;
    
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Zombie Arena", sf::Style::Fullscreen);
    
    sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));
    
    sf::Clock clock;
    
    sf::Time gameTimeTotal;
    
    sf::Vector2f mouseWorldPosition;
    
    sf::Vector2i mouseScreenPosition;
    
    Player player;
    
    sf::IntRect arena;
    
    sf::VertexArray background;
    
    sf::Texture textureBackground;
    textureBackground.loadFromFile("graphics/background_sheet.png");
    
    //prepare the horde of Zombies
    
    int numZombies;
    int numZombiesAlive;
    Zombie * zombies = nullptr;
    
    
    while(window.isOpen())
    {
        sf::Event event;
        
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Return)
                {
                    if(state == State::PLAYING)
                    {
                        state = State::PAUSED;
                    }
                    else if (state == State::PAUSED)
                    {
                        state = State::PLAYING;
                        clock.restart();
                    }
                    else if (state == State::GAME_OVER)
                    {
                        state = State::LEVELING_UP;
                    }
                    else if (state == State::LEVELING_UP)
                    {
                        
                    }
                }
                if (state == State::PLAYING)
                {
                    
                }
            }
            
        }// end poll event
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        if(state == State::PLAYING)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player.moveUp();
            }
            else
            {
                player.stopUp();
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                player.moveLeft();
            }
            else
            {
                player.stopLeft();
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player.moveDown();
            }
            else
            {
                player.stopDown();
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player.moveRight();
            }
            else
            {
                player.stopRight();
            }
        }// end WASD while playing
        
        //handle Leveling Up state
        if (state == State::LEVELING_UP)
        {
            if ((event.key.code == sf::Keyboard::Num1)||
                (event.key.code == sf::Keyboard::Num2)||
                (event.key.code == sf::Keyboard::Num3)||
                (event.key.code == sf::Keyboard::Num4)||
                (event.key.code == sf::Keyboard::Num5)||
                (event.key.code == sf::Keyboard::Num6))
            {
                state = State::PLAYING;
            }
            
            if (state == State::PLAYING)
            {
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0;
                
                //int tileSize = 50;
                
                int tileSize = ZombieArena::createBackGround(background, arena);
                
                player.spawn(arena, resolution, tileSize);
                
                numZombies = 10;
                numZombiesAlive = numZombies;
                
                delete[] zombies;
                zombies = ZombieArena::createHorde(numZombies,arena);
                
                clock.restart();//restart clock to avoid frame jump
            }
        }//end Leveling Up
        
        //update the FRAME
        if(state == State::PLAYING)
        {
            
            sf::Time dt = clock.restart();
            
            gameTimeTotal += dt;
            
            float dtAsSeconds = dt.asSeconds();
            
            mouseScreenPosition = sf::Mouse::getPosition();
            
            // Convert mouse position to world coordinates of mainView
            mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), mainView);
            
            player.update(dtAsSeconds, mouseScreenPosition);
            
            sf::Vector2f playerPosition(player.getCenter());
            
            mainView.setCenter(playerPosition);
            
            for (int i = 0; i < numZombies; ++i)
            {
                if(zombies[i].isAlive())
                {
                    zombies[i].update(dtAsSeconds, playerPosition);
                }
            }
            
            
        }//end update the FRAME
        
        //draw the Scene
        if(state == State::PLAYING)
        {
            window.clear();
            
            window.setView(mainView);
            
            window.draw(background, &textureBackground);
            
            for (int i = 0; i < numZombies; ++i)
            {
                window.draw(zombies[i].getSprite());
            }
            
            window.draw(player.getSprite());
            
        }
        
        if(state == State::LEVELING_UP)
        {
        }
        
        if(state == State::PAUSED)
        {
        }
        
        if(state == State::GAME_OVER)
        {
        }
        window.display();
        
    }// end game loop
    
    delete[] zombies;
    
    return 0;
}
