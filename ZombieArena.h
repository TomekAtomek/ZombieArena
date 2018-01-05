#ifndef ZOMBIEARENA_H
#define ZOMBIEARENA_H

#include <SFML/Graphics.hpp>
#include "Zombie.h"

class ZombieArena
{
public:
    static int createBackGround(sf::VertexArray& rVA, sf::IntRect arena);
    static Zombie * createHorde(int numZombies, sf::IntRect arena);
};

#endif // ZOMBIEARENA_H
