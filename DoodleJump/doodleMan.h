//Andrew Cantrell
//OOP Project

#ifndef DOODLEMAN_H
#define DOODLEMAN_H

#include <SFML/Graphics.hpp>
using namespace sf;

class DoodleMan{

private:
    Sprite sprite;

public:
    DoodleMan(){};
    DoodleMan(sf::Sprite s)
    : sprite(s)
    {};
    void setPosition(int,int);
    Sprite getSprite(){return sprite;};
    void setSprite(Sprite);
};

#endif