//Andrew Cantrell
//OOP

#ifndef GAME_H
#define GAME_H

#include "deckCompact.h"

//Player Class
class player{
    private:
    

    public:
        std::vector<Card> pile; //pile for cards won
        std::vector<Card> deck; //deck of cards to play
        int deckSize(){return deck.size();}; //return # of cards in deck
        int pileSize(){return pile.size();}; //return # of cards in pile
        Card topDeck(){return deck.back();}; //return top card of deck

        //pop card off the back of the deck and return that card
        Card popOff(){
            Card card = this->deck.back();
            this->deck.pop_back();
            return card;
        };

        //pushes the card passed to the function to the pile
        void pushToPile(Card Card){
            this->pile.push_back(Card);
        };

        void CheckDeck();//if deck is empty, set deck = pile, then clear pile

        void SplitDeck(player&); //splits the deck in half between
                                //the player calling the function
                                //and the player passed to the function

};

class Game{
    private:

    public:
        std::vector<Card> Deck;

        //displays all supported games and their corresponding number
        void showGameOptions(); 

        //starts new game of the game represented by the number passed to the function        
        bool newGame();

        //runs the game of war
        void PlayWar();
};

//Pops card from each player's deck and adds them to WinPile
void PlayCards(std::vector<Card>&,std::vector<Card>&,std::vector<Card>&,std::vector<Card>&);

//Return true only if one player has run out of cards both in their deck and pile
bool Winner(player&, player&); 

//Pops cards from each Player's deck vector, compares them and awards both cards
//to the player with a card of higher rank. In case of tie, 3 cards (if available) 
//are added to the WinPile by each player, and then a new card is popped from both 
//player's decks and compared.
void War(player&, player&);

#endif