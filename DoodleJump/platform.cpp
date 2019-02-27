//Andrew Cantrell
//OOP Project

#include "platform.h"
using namespace sf;

void Platform::setSprite(Sprite s)
{
    sprite = s;
    return;
}

void Platform::setPosition(int x,int y)
{
  sprite.setPosition(x,y);
  return;
}

void Platform::setTexture(Texture t)
{
    sprite.setTexture(t);
    return;
}

Platform::Platform()
{
}