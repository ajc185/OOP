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
public:
    virtual bool isStandard(){return false;};//returns true if standard override
    virtual bool isJoker(){return false;};//returns true if joker override
    virtual void print() = 0;
    virtual Color getColor() = 0;
};

class Joker:public Card{
private:
    Color c;

public: 
    Joker(Color color)
    : c(color)
    {};
    virtual void print() override;
    virtual Color getColor() override;
    virtual bool isJoker() override{return true;};//returns true if joker override
};

class Standard:public Card{
private:
    Rank r;
    Suit s;

public: 
    Standard(Rank rank, Suit suit)
    : r(rank), s(suit)
    {};
    virtual void print() override;
    virtual Color getColor() override;
    virtual bool isStandard() override{return true;};//returns true if standard override
};

std::vector<Card*> GenerateDeck(); //Generates vector of 52 playing cards



#endif
