//Andrew Cantrell
//OOP Project

#include "doodleMan.h"
using namespace sf;

void DoodleMan::setSprite(Sprite s)
{
    sprite = s;
    return;
}

void DoodleMan::setPosition(int x,int y)
{
  sprite.setPosition(x,y);
  return;
}

void DoodleMan::setTexture(Texture t)
{
    sprite.setTexture(t);
    return;
}

DoodleMan::DoodleMan()
{
}