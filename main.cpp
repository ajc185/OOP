//Andrew Cantrell
//OOP Game of War Assignment

#include "deck.h"
#include <iostream>
#include <vector>

int main()
{
    //Create 2 Players
    player Player1;
    player Player2;

    //Player 1 creates deck of cards
    Player1.GenerateDeck();
    //Player 1 shuffles the deck
    Player1.ShuffleDeck();
    //Player 1 gives half the crads in the deck to Player 2
    Player1.SplitDeck(Player2);

    //Main game loop
    while(!Winner(Player1, Player2))
    {
        std::cout << "\n";
        War(Player1, Player2);
        std::cout << "Player1 Deck: " << Player1.deckSize() << " cards\n";
        std::cout << "Player1 Pile: " << Player1.pileSize() << " cards\n";
        std::cout << "Player2 Deck: " << Player2.deckSize() << " cards\n";
        std::cout << "Player2 Pile: " << Player2.pileSize() << " cards\n";
    }
    if(Player1.deckSize() == 0 && Player1.pileSize() == 0)
    {
        std::cout << "\nPlayer 2 wins!\n";
    }
    else
    {
        std::cout << "\nPlayer 1 wins!\n";
    }
    return 0;
}
