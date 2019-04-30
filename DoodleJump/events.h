//Andrew Cantrell
//OOP Project

#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.hpp>
#include "doodleMan.h"
#include "platform.h"
using namespace sf;

//Code from https://gitlab.com/andrew.n.sutton/spring-19-oop/blob/master/bejeweled/main.cpp
struct event_listener
{
  // Window events
  virtual void on_close() { }
  virtual void on_gain_focus() { }
  virtual void on_lose_focus() { }
  virtual void on_resize(sf::Event::SizeEvent) { }

  // Mouse events
  virtual void on_mouse_button_press(sf::Event::MouseButtonEvent) { }
  virtual void on_mouse_button_release(sf::Event::MouseButtonEvent) { }

  // Keyboard events
  virtual void on_key_press(sf::Event::KeyEvent) { }
  virtual void on_key_release(sf::Event::KeyEvent) { }
};
struct event_source
{
  event_source(sf::Window& w)
    : window(&w)
  { }

  void
  listen(event_listener& l)
  {
    listeners.push_back(&l);
  }

  // Notify listeners of queued events.
  void
  poll()
  {
    sf::Event e;
    while (window->pollEvent(e))
      process(e);
  }

  // Notify listeners of a single event.
  void process(sf::Event const& e)
  {
    switch (e.type) 
    {
        case Event::Closed:
        return notify([e](event_listener* l) { l->on_close(); });

        case Event::Resized:
        return notify([e](event_listener* l) { l->on_resize(e.size); });
        
        case Event::MouseButtonPressed:
        return notify([e](event_listener* l) { l->on_mouse_button_press(e.mouseButton); });
        case Event::MouseButtonReleased:
        return notify([e](event_listener* l) { l->on_mouse_button_release(e.mouseButton); });

        case Event::KeyPressed:
        return notify([e](event_listener* l) { l->on_key_press(e.key); });
        case Event::KeyReleased:
        return notify([e](event_listener* l) { l->on_key_press(e.key); });
        
        default:
        break;
    }
  }
  template<typename F>
  void notify(F fn)
  {
    for (event_listener* l : listeners)
      fn(l);    
  }

  // The window that we can poll for events.
  sf::Window* window;

  // A list of listeners to notify about particular
  // events.
  std::vector<event_listener*> listeners;
};




//Original/Modified Code:
struct point
{
    int x, y;
};
struct doodle_graphics
{
    // Textures loaded from disk.
    sf::Texture t1, t2, t3, t4, t5, t6;

    // Drawable sprites.
    sf::Sprite sBackground, sPlat, sPers, sBreak, sBroken, sBoost;
    doodle_graphics()
    {
        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/platform.png");
        t3.loadFromFile("images/doodle.png");
        t4.loadFromFile("images/break.png");
        t5.loadFromFile("images/broken.png");
        t6.loadFromFile("images/boost.png");
        sBackground.setTexture(t1);
        sPlat.setTexture(t2);
        sPers.setTexture(t3);
        sBreak.setTexture(t4);
        sBroken.setTexture(t5);
        sBoost.setTexture(t6);
    }
};

struct doodleJump : event_listener
{
    // The game window.
    sf::RenderWindow window;

    // Game state:

    int x , y , h; //player location variables
    float dx, dy; //player movement variables

    //graphics
    doodle_graphics graphics;

    //Create player, set sprite to doodle image
    DoodleMan player = DoodleMan(graphics.sPers);

    //Create platform, set sprite to platform image
    Platform* platform = new Platform;

    //Create breakable platform, set sprite to break image
    BreakPlat* breakPlat = new BreakPlat;
    BreakPlat* brokenPlat = new BreakPlat;

     //Create boost platform, set sprite to break image
    BoostPlat* boostPlat = new BoostPlat;
    
    //create vectors for game items
    std::vector<Platform> stdplats;
    std::vector<BreakPlat> breakplats;
    std::vector<BoostPlat> boostplats;

    //platforms
    Platform tempPlat;
    BreakPlat tempBreak; //for generating breakplats later
    BoostPlat tempBoost; //for generating boostplats later

    doodleJump()
    :window(VideoMode(400, 533), "Doodle Game!")
    {
        window.setFramerateLimit(60);
        //initialize player location:
        x = 170;
        y = 100;
        h = 200;
        //initialize player movement:
        dx = 0;
        dy = 0;
        //initialize platforms:
        tempPlat.x = 177;
        tempPlat.y = 520;//rand() % 533;
        stdplats.push_back(tempPlat);
        for (int i = 0; i < 3; i++) 
        {
            tempPlat.x = rand() % 375;
            tempPlat.y = i*120 + 50;//rand() % 533;
            stdplats.push_back(tempPlat);
        }
    };

    // Returns true if the app is open.
    bool is_open() const { return window.isOpen(); }

    // Close the application.
    void on_close() override
    {
        window.close();
    }

    void fall();
    void movePlatforms();
    void checkIfPlayerLanded();
    void updatePlayerPosition();

    void draw();

};



#endif