//Andrew Cantrell
//OOP Game of War Assignment

#ifndef DECK_H
#define DECK_H

#include <vector>

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
        Card(Rank, Suit); //card constructor
        Rank getRank(){return static_cast<Rank>(value & 0xF);};//returns rank
        Suit getSuit(){return static_cast<Suit>(value >> 4);};// returns suit

};

void ShuffleDeck(std::vector<Card>&); //Shuffles the deck elements (cards) randomly
std::vector<Card> GenerateDeck(); //Generates vector of 52 playing cards



#endif
