//Andrew Cantrell
//OOP

#include "game.h"
#include <iostream>

//splits the deck in half between
//the player calling the function
//and the player passed to the function
void player::SplitDeck(player& otherPlayer)
{
    for(int i = 0; i < 26; i++)
    {
        Card card = this->deck.back();
        this->deck.pop_back();
        otherPlayer.deck.push_back(card);
    }
}

//if deck is empty, set deck = pile, then clear pile
void player::CheckDeck()
{
    if(this->deck.empty() && !this->pile.empty())
    {
        this->deck = this->pile;
        this->pile.clear();
        ShuffleDeck(this->deck);
    }
}

//displays all supported games and their corresponding number
void Game::showGameOptions()
{
    std::cout << "\nLIST OF GAMES:\n";
    std::cout << "1 - Game of War\n";
    std::cout << "0 - End Program\n\n";

    return;
}

//starts new game based on user input        
bool Game::newGame()
{
    int choice = 1;
    showGameOptions();
    std::cout << "Please enter the number of the game you wish to play: ";
    std::cin >> choice;
    if(choice == 0)
    {
        return false;
    }
    if(choice == 1)
    {
        this->PlayWar();
        return true;
    }
    else
    {
        std::cout << "\nInvalid Game Choice\n";
        return true;
    }
}

//runs the game of war
void Game::PlayWar()
{
    player Player1;
    Player1.deck = GenerateDeck();
    ShuffleDeck(Player1.deck);
    player Player2;
    Player1.SplitDeck(Player2);

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
    return;
}

//Pops card from each player's deck and adds them to WinPile
void PlayCards(player& Player1,player& Player2,std::vector<Card>& WinPile)
{
    WinPile.push_back(Player1.popOff());
    WinPile.push_back(Player2.popOff());
}

//Return true only if one player has run out of cards both in their deck and pile
bool Winner(player& Player1, player& Player2)
{
    if((Player1.deckSize() == 0 && Player1.pileSize() == 0) || (Player2.deckSize() == 0 && Player2.pileSize() == 0))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//Pops cards from each Player's deck vector, compares them and awards both cards
//to the player with a card of higher rank. In case of tie, 3 cards (if available) 
//are added to the WinPile by each player, and then a new card is popped from both 
//player's decks and compared.
void War(player& Player1, player& Player2)
{
    std::vector<Card> WinPile; //used to temporarily store cards won by player
    bool tie = false;
    do
    {
        Player1.CheckDeck();
        Player2.CheckDeck();
        //Player1 wins
        if(Player1.topDeck().getRank() > Player2.topDeck().getRank())
        {
            tie = false;
            PlayCards(Player1, Player2, WinPile);
            //Transfer all WinPile Cards to Player1Pile:
            while(!WinPile.empty())
            {
                Player1.pushToPile(WinPile.back());
                WinPile.pop_back();
            }
        }
        //Player2 wins
        else if(Player2.topDeck().getRank() > Player1.topDeck().getRank())
        {
            tie = false;
            PlayCards(Player1, Player2, WinPile);
            //Transfer all WinPile Cards to Player2Pile:
            while(!WinPile.empty())
            {
                Player2.pushToPile(WinPile.back());
                WinPile.pop_back();
            }
        }
        //Tie
        else
        {
            tie = true;
            //If there is more than 1 card in each players deck,
            //Each Player adds a card to WinPile
            if(Player1.deckSize() > 1 && Player2.deckSize() > 1)
            {
                PlayCards(Player1, Player2, WinPile);
                Player1.CheckDeck();
                Player2.CheckDeck();
            }
            //If there is still more than 1 card in each players deck,
            //Each Player adds a card to WinPile
            if(Player1.deckSize() > 1 && Player2.deckSize() > 1)
            {
                PlayCards(Player1, Player2, WinPile);
                Player1.CheckDeck();
                Player2.CheckDeck();
            }
            //If there is still more than 1 card in each players deck,
            //Each Player adds a card to WinPile
            if(Player1.deckSize() > 1 && Player2.deckSize() > 1)
            {
                PlayCards(Player1, Player2, WinPile);
                Player1.CheckDeck();
                Player2.CheckDeck();
            }
            //If there is not more than 1 card in each players deck,
            //Only the player with more than 1 card adds a card to WinPile
            else
            {
                if(Player1.deckSize() == 1)
                {
                    WinPile.push_back(Player2.popOff());
                }
                else if(Player2.deckSize() == 1)
                {
                    WinPile.push_back(Player1.popOff());
                }
            }
            
        }  
    }while(tie);
}

