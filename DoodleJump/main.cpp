//Andrew Cantrell
//OOP Project

#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include <iostream>
#include "doodleMan.h"
#include "platform.h"

using namespace sf;

struct point
{
    int x, y;
};

int
main()
{
    srand(time(0));
    
    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);//speed of game
    
    //Load images
    Texture t1, t2, t3, t4, t5, t6;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    t4.loadFromFile("images/break.png");
    t5.loadFromFile("images/broken.png");
    t6.loadFromFile("images/boost.png");
    Sprite sBackground(t1), sPlat(t2), sPers(t3), sBreak(t4), sBroken(t5), sBoost(t6);

    //Create player, set sprite to doodle image
    DoodleMan player;
    player.setSprite(sPers);

    //Create platform, set sprite to platform image
    Platform* platform = new Platform;
    platform->setSprite(sPlat);

    //Create breakable platform, set sprite to break image
    BreakPlat* breakPlat = new BreakPlat;
    breakPlat->setSprite(sBreak);
    BreakPlat* brokenPlat = new BreakPlat;
    brokenPlat->setSprite(sBroken);

     //Create boost platform, set sprite to break image
    BoostPlat* boostPlat = new BoostPlat;
    boostPlat->setSprite(sBoost);
    
    //create vectors for game items
    std::vector<Platform> stdplats;
    std::vector<BreakPlat> breakplats;
    std::vector<BoostPlat> boostplats;
    
    //place initial platforms
    Platform tempPlat;
    tempPlat.x = 177;
    tempPlat.y = 520;//rand() % 533;
    stdplats.push_back(tempPlat);
    for (int i = 0; i < 3; i++) {
        tempPlat.x = rand() % 375;
        tempPlat.y = i*120 + 50;//rand() % 533;
        stdplats.push_back(tempPlat);
    }

    BreakPlat tempBreak; //for generating breakplats later
    BoostPlat tempBoost; //for generating boostplats later
    
    int x = 170, y = 100, h = 200; //initialize player location
    float dx = 0, dy = 0; //initialize player movement
    
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Right))
            x += 3; //movement right
        if (Keyboard::isKeyPressed(Keyboard::Left))
            x -= 3; //movement left

        if(x > 400) //if too far right, wrap back to left
        {
            x = -80;
        }
        if(x < -80) //if too far left, wrap back to right
        {
            x = 400;
        }
        
        dy += 0.2; //strength of gravity?
        y += dy; //controls speed of fall
        //if (y > 500) //if y>500, player has reached bottom of screen
            //dy = -10; //this bounces at bottom of screen
        
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

        player.setPosition(x, y);
        
        //block to draw all entities
        app.draw(sBackground);
        app.draw(player.getSprite());
        for (int i = 0; i < stdplats.size(); i++) 
        {
            sPlat.setPosition(stdplats[i].x, stdplats[i].y);
            app.draw(sPlat);
        }
        for (int i = 0; i < breakplats.size(); i++) 
        {
            if(!breakplats[i].isBroken())
            {
                sBreak.setPosition(breakplats[i].x, breakplats[i].y);
                app.draw(sBreak);
            }
            else
            {
                breakplats[i].y += 10;
                sBroken.setPosition(breakplats[i].x, breakplats[i].y);
                app.draw(sBroken);
            } 
        }
        for (int i = 0; i < boostplats.size(); i++) 
        {
            sBoost.setPosition(boostplats[i].x, boostplats[i].y);
            app.draw(sBoost);
        }
        
        app.display();
    }
    
    return 0;
}
