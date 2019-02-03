//Andrew Cantrell
//OOP Game of War Assignment

#include "deck.h"
#include <algorithm> //shuffle
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock

//card constructor, takes rank and suit
card newCard(Rank r, Suit s)
{
    card Card;
    Card.rank = r;
    Card.suit = s;
    return Card;
}

//Generates vector of 52 playing cards
void player::GenerateDeck()
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            this->deck.push_back(newCard(static_cast<Rank>(j),static_cast<Suit>(i)));
        }
    }
    return;
}

//Shuffles the deck vector elements randomly
void player::ShuffleDeck()
{
    // Following code from http://www.cplusplus.com/reference/algorithm/shuffle/
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->deck.begin(), this->deck.end(),std::default_random_engine(seed));
}

//splits the deck in half between
//the player calling the function
//and the player passed to the function
void player::SplitDeck(player& otherPlayer)
{
    for(int i = 0; i < 26; i++)
    {
        card Card = this->deck.back();
        this->deck.pop_back();
        otherPlayer.deck.push_back(Card);
    }
}

//Pops card from each player's deck and adds them to WinPile
void PlayCards(player& Player1,player& Player2,std::vector<card>& WinPile)
{
    WinPile.push_back(Player1.popOff());
    WinPile.push_back(Player2.popOff());
}

//if deck is empty, set deck = pile, then clear pile
void player::CheckDeck()
{
    if(this->deck.empty() && !this->pile.empty())
    {
        this->deck = this->pile;
        this->pile.clear();
        this->ShuffleDeck();
    }
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
    std::vector<card> WinPile; //used to temporarily store cards won by player
    bool tie = false;
    do
    {
        Player1.CheckDeck();
        Player2.CheckDeck();
        
        //Player1 wins
        if(Player1.getRank() > Player2.getRank())
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
        else if(Player2.getRank() > Player1.getRank())
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