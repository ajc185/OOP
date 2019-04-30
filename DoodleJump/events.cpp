//Andrew Cantrell
//OOP Project

#include "events.h"

void doodleJump::fall()
{
    dy += 0.2; //strength of gravity?
    y += dy; //controls speed of fall
    //if (y > 500) //if y>500, player has reached bottom of screen
    //dy = -10; //this bounces at bottom of screen
    return;
};

void doodleJump::movePlatforms()
{
    if (y < h)
    {
        //loop to move platforms
        for (int i = 0; i < stdplats.size() || i < breakplats.size() || i < boostplats.size(); i++) { 
            //move platforms along with player:
            y = h;

            if(i < stdplats.size())
            {
                //move platforms relative to player
                stdplats[i].y = stdplats[i].y - dy;

                //if platform goes offscreen, generate new one
                if (stdplats[i].y > 533) 
                {
                    stdplats[i].y = 0;
                    stdplats[i].x = rand() % 375;
                      

                    //Randomly add in breaking platforms:
                    if(rand()%5 == 1)
                    {
                        tempBreak.x = rand() % 375;
                        tempBreak.y = -10*(rand()%5);
                        breakplats.push_back(tempBreak);
                    }
                    //Randomly add in boost platforms:
                    if(rand()%20 == 1)
                    {
                        tempBoost.x = rand() % 375;
                        tempBoost.y = -10*(rand()%5);
                        boostplats.push_back(tempBoost);
                    }
                }
            }
            if(i < breakplats.size())
            {
                //move break platforms relative to player
                breakplats[i].y = breakplats[i].y - dy;
            }
            if(i < boostplats.size())
            {
                //move boost platforms relative to player
                boostplats[i].y = boostplats[i].y - dy;
            }
        }
    }
    return;
}

void doodleJump::checkIfPlayerLanded()
{
    for (int i = 0; i < stdplats.size(); i++)
    {
        //if player lands on platform, bounce
        if (stdplats[i].playerLanded(x,y,dy))
        {
            stdplats[i].afterLanding(dy);
        }
    }
    for (int i = 0; i < breakplats.size(); i++)
    {
        //if player lands on platform, bounce
        if (breakplats[i].playerLanded(x,y,dy))
        {
            breakplats[i].afterLanding(dy);
        }
    }
    for (int i = 0; i < boostplats.size(); i++)
    {
        //if player lands on platform, bounce
        if (boostplats[i].playerLanded(x,y,dy))
        {
            boostplats[i].afterLanding(dy);
        }
    }
    return;
}

void doodleJump::updatePlayerPosition()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
      x += 5;
    if (Keyboard::isKeyPressed(Keyboard::Left))
      x -= 5;
    if(x > 400) //if too far right, wrap back to left
    {
        x = -80;
    }
    if(x < -80) //if too far left, wrap back to right
    {
        x = 400;
    }
    player.setPosition(x, y);
    return;
}

void doodleJump::draw()
{
    // Draw the background.
    window.draw(graphics.sBackground);
    window.draw(player.getSprite());
    for (int i = 0; i < stdplats.size(); i++) 
    {
        graphics.sPlat.setPosition(stdplats[i].x, stdplats[i].y);
        window.draw(graphics.sPlat);
    }
    for (int i = 0; i < breakplats.size(); i++) 
    {
        if(!breakplats[i].isBroken())
        {
            graphics.sBreak.setPosition(breakplats[i].x, breakplats[i].y);
            window.draw(graphics.sBreak);
        }
        else
        {
            breakplats[i].y += 10;
            graphics.sBroken.setPosition(breakplats[i].x, breakplats[i].y);
            window.draw(graphics.sBroken);
        } 
    }
    for (int i = 0; i < boostplats.size(); i++) 
    {
        graphics.sBoost.setPosition(boostplats[i].x, boostplats[i].y);
        window.draw(graphics.sBoost);
    }
        
    window.display();
}