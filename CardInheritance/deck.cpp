//Andrew Cantrell
//OOP Game of War Assignment

#include "deck.h"
#include <iostream>

//Generates vector of 52 playing cards
std::vector<Card*> GenerateDeck()
{
    std::vector<Card*> deck;
    deck.push_back(new Standard(Ace,Clubs));
    deck.push_back(new Standard(Two,Clubs));
    deck.push_back(new Standard(Three,Clubs));
    deck.push_back(new Standard(Four,Clubs));
    deck.push_back(new Standard(Five,Clubs));
    deck.push_back(new Standard(Six,Clubs));
    deck.push_back(new Standard(Seven,Clubs));
    deck.push_back(new Standard(Eight,Clubs));
    deck.push_back(new Standard(Nine,Clubs));
    deck.push_back(new Standard(Ten,Clubs));
    deck.push_back(new Standard(Jack,Clubs));
    deck.push_back(new Standard(Queen,Clubs));
    deck.push_back(new Standard(King,Clubs));

    deck.push_back(new Standard(Ace,Spades));
    deck.push_back(new Standard(Two,Spades));
    deck.push_back(new Standard(Three,Spades));
    deck.push_back(new Standard(Four,Spades));
    deck.push_back(new Standard(Five,Spades));
    deck.push_back(new Standard(Six,Spades));
    deck.push_back(new Standard(Seven,Spades));
    deck.push_back(new Standard(Eight,Spades));
    deck.push_back(new Standard(Nine,Spades));
    deck.push_back(new Standard(Ten,Spades));
    deck.push_back(new Standard(Jack,Spades));
    deck.push_back(new Standard(Queen,Spades));
    deck.push_back(new Standard(King,Spades));

    deck.push_back(new Standard(Ace,Hearts));
    deck.push_back(new Standard(Two,Hearts));
    deck.push_back(new Standard(Three,Hearts));
    deck.push_back(new Standard(Four,Hearts));
    deck.push_back(new Standard(Five,Hearts));
    deck.push_back(new Standard(Six,Hearts));
    deck.push_back(new Standard(Seven,Hearts));
    deck.push_back(new Standard(Eight,Hearts));
    deck.push_back(new Standard(Nine,Hearts));
    deck.push_back(new Standard(Ten,Hearts));
    deck.push_back(new Standard(Jack,Hearts));
    deck.push_back(new Standard(Queen,Hearts));
    deck.push_back(new Standard(King,Hearts));

    deck.push_back(new Standard(Ace,Diamonds));
    deck.push_back(new Standard(Two,Diamonds));
    deck.push_back(new Standard(Three,Diamonds));
    deck.push_back(new Standard(Four,Diamonds));
    deck.push_back(new Standard(Five,Diamonds));
    deck.push_back(new Standard(Six,Diamonds));
    deck.push_back(new Standard(Seven,Diamonds));
    deck.push_back(new Standard(Eight,Diamonds));
    deck.push_back(new Standard(Nine,Diamonds));
    deck.push_back(new Standard(Ten,Diamonds));
    deck.push_back(new Standard(Jack,Diamonds));
    deck.push_back(new Standard(Queen,Diamonds));
    deck.push_back(new Standard(King,Diamonds));

    deck.push_back(new Joker(Red));
    deck.push_back(new Joker(Black));
    return deck;
}

void Joker::print()
{
    switch(this->c)
    {
        case Red:
            std::cout << "R";
            break;
        case Black:
            std::cout << "B";
            break;
    };
    return;
}

void Standard::print()
{
    switch(this->r)
    {
        case Ace:
            std::cout << "A";
            break;
        case Two:
            std::cout << "2";
            break;
        case Three:
            std::cout << "3";
            break;
        case Four:
            std::cout << "4";
            break;
        case Five:
            std::cout << "5";
            break;
        case Six:
            std::cout << "6";
            break;
        case Seven:
            std::cout << "7";
            break;
        case Eight:
            std::cout << "8";
            break;
        case Nine:
            std::cout << "9";
            break;
        case Ten:
            std::cout << "T";
            break;
        case Jack:
            std::cout << "J";
            break;
        case Queen:
            std::cout << "Q";
            break;
        case King:
            std::cout << "K";
            break;
    };
    switch(this->s)
    {
        case Hearts:
            std::cout << "H";
            break;
        case Diamonds:
            std::cout << "D";
            break;
        case Spades:
            std::cout << "S";
            break;
        case Clubs:
            std::cout << "C";
            break;
    };
    return;
}

Color Joker::getColor()
{
    return this->c;
}

Color Standard::getColor()
{
    switch(this->s)
    {
        case Hearts:
            return Red;
        case Diamonds:
            return Red;
        case Clubs:
            return Black;
        case Spades:
            return Black;   
    };
}