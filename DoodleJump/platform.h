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
    int x;
    int y;
    Platform(){};
    void setPosition(int,int);
    Sprite getSprite(){return sprite;};
    void setSprite(Sprite);
    bool playerLanded(int,int,int);
    virtual void afterLanding(float&);
    virtual bool isBreak(){return false;};
    virtual bool isBroken(){return false;};
    virtual bool isBoost(){return false;};
};

class BreakPlat:public Platform{

private:
    bool broken;
public:
    BreakPlat(){broken = false;};
    void afterLanding(float&) override;
    bool isBreak() override{return true;};
    bool isBroken() override{return broken;};
    bool isBoost() override{return false;};
};

class BoostPlat:public Platform{

public:
    BoostPlat(){};
    void afterLanding(float&) override;
    bool isBreak() override{return false;};
    bool isBroken() override{return false;};
    bool isBoost() override{return false;};
};

#endif