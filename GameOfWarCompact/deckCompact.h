//Andrew Cantrell
//OOP Game of War Assignment

#ifndef DECKCOMPACT_H
#define DECKCOMPACT_H

#include <vector>

//Card Color
enum Color{
    Red,
    Black,
};

//Card Suits
enum Suit{
    Clubs,
    Spades,
    Hearts,
    Diamonds,
};

//Card Ranks
enum Rank{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

//Card object
class Card{
    private:
        char value;

    public:
        Card(Rank, Suit); //standard card constructor
        Card(Color); //joker card constructor
        Rank getRank(){return static_cast<Rank>(value & 0xF);};//returns rank
        Suit getSuit(){return static_cast<Suit>(value >> 4);};// returns suit
        enum Color getColor(){return static_cast<enum Color>(((value >> 6))&0x1);};//returns color
        bool isJoker(){return value>>7;};//returns true if joker
};


void ShuffleDeck(std::vector<Card>&); //Shuffles the deck elements (cards) randomly
std::vector<Card> GenerateDeck(); //Generates vector of 52 playing cards



#endif
