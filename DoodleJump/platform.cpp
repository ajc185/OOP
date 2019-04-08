//Andrew Cantrell
//OOP Project

#include "platform.h"
using namespace sf;

//Standard Platform code:

void Platform::setSprite(Sprite s)
{
    sprite = s;
    return;
}

void Platform::setPosition(int x,int y)
{
  this->x = x;
  this->y = y;
  sprite.setPosition(x,y);
  return;
}

bool Platform::playerLanded(int x, int y, int dy)
{
  return ((x + 50 > this->x) && (x + 20 < this->x + 68) &&
    (y + 70 > this->y) && (y + 70 < this->y + 14) && (dy > 0));
}

void Platform::afterLanding(float& dy)
{
  dy = -10;
  return;
}


//Breaking Platform code:
void BreakPlat::afterLanding(float& dy)
{
  if(!this->broken)
  {
    dy = -10;
    this->broken = true;
    return;
  }
}


//Boost Platform code:
void BoostPlat::afterLanding(float& dy)
{
  dy = -30;
  return;
}

