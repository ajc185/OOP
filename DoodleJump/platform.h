//Andrew Cantrell
//OOP Project

#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Platform{

private:
    Sprite sprite;

public:
    Platform();
    void setPosition(int,int);
    Sprite getSprite(){return sprite;};
    void setSprite(Sprite);
    void setTexture(Texture);
};

#endif