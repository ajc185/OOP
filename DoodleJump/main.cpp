//Andrew Cantrell
//OOP Project

#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include <iostream>
#include "events.h"

using namespace sf;

int
main()
{
    srand(time(0));
    // Create the app data and window.
    doodleJump app;

    // Construct the event loop and listeners.  
    event_source events(app.window);
    events.listen(app);

    while (app.is_open()) 
    {
        // Poll for events.
        events.poll();

        // Update game state.
        app.fall();
        app.movePlatforms();
        app.checkIfPlayerLanded();
        app.updatePlayerPosition();

        // Redraw the game.
        app.draw();
    }
  
  return 0;
}
