//Andrew Cantrell
//OOP Game of War Assignment

#ifndef DECKUNION_H
#define DECKUNION_H

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

class StandardCard{

private:
    Rank rank;
    Suit suit;

public:
    StandardCard(Rank r, Suit s)
        :rank(r),suit(s)
    {}
    Rank getRank(){return rank;}
};

class JokerCard{

private:
    Color color;

public:
    JokerCard(Color c)
        :color(c)
    {}
};

union CardData{
    StandardCard sc;
    JokerCard jc;

    CardData(Rank r, Suit s)
        :sc(StandardCard(r,s))
    {}
    CardData(Color c)
        :jc(JokerCard(c))
    {}
};

class Card{

private:
    int kind; //the tag
    CardData data;

public:
    Card(Rank r, Suit s)
        :kind(0),data(r,s)
    {}
    Card(Color c)
        :kind(1),data(c)
    {}
    int isJoker(){return kind;}
    Rank getRank(){return data.sc.getRank();}
};

void ShuffleDeck(std::vector<Card>&); //Shuffles the deck elements (cards) randomly
std::vector<Card> GenerateDeck(); //Generates vector of 52 playing cards

#endif