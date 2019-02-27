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
    DoodleMan();
    void setPosition(int,int);
    Sprite getSprite(){return sprite;};
    void setSprite(Sprite);
    void setTexture(Texture);
};

#endif