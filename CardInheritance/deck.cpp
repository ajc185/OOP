//Andrew Cantrell

#include "deckCompact.h"
#include <algorithm> //shuffle
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock

//standard card constructor, takes rank and suit
Card::Card(Rank r, Suit s)
    :value(static_cast<unsigned>(s << 4) + static_cast<unsigned>(r))
{}

//joker card constructor, takes rank and suit
Card::Card(Color c)
    :value(static_cast<unsigned>((0x2+c)<<6))
{}

//Generates vector of 52 playing cards
std::vector<Card> GenerateDeck()
{
    std::vector<Card> deck {
        Card(Ace,Clubs),
        Card(Two,Clubs),
        Card(Three,Clubs),
        Card(Four,Clubs),
        Card(Five,Clubs),
        Card(Six,Clubs),
        Card(Seven,Clubs),
        Card(Eight,Clubs),
        Card(Nine,Clubs),
        Card(Ten,Clubs),
        Card(Jack,Clubs),
        Card(Queen,Clubs),
        Card(King,Clubs),

        Card(Ace,Spades),
        Card(Two,Spades),
        Card(Three,Spades),
        Card(Four,Spades),
        Card(Five,Spades),
        Card(Six,Spades),
        Card(Seven,Spades),
        Card(Eight,Spades),
        Card(Nine,Spades),
        Card(Ten,Spades),
        Card(Jack,Spades),
        Card(Queen,Spades),
        Card(King,Spades),

        Card(Ace,Hearts),
        Card(Two,Hearts),
        Card(Three,Hearts),
        Card(Four,Hearts),
        Card(Five,Hearts),
        Card(Six,Hearts),
        Card(Seven,Hearts),
        Card(Eight,Hearts),
        Card(Nine,Hearts),
        Card(Ten,Hearts),
        Card(Jack,Hearts),
        Card(Queen,Hearts),
        Card(King,Hearts),

        Card(Ace,Diamonds),
        Card(Two,Diamonds),
        Card(Three,Diamonds),
        Card(Four,Diamonds),
        Card(Five,Diamonds),
        Card(Six,Diamonds),
        Card(Seven,Diamonds),
        Card(Eight,Diamonds),
        Card(Nine,Diamonds),
        Card(Ten,Diamonds),
        Card(Jack,Diamonds),
        Card(Queen,Diamonds),
        Card(King,Diamonds),

        Card(Red),
        Card(Black),
    };
    return deck;
}

//Shuffles the deck vector elements randomly
void ShuffleDeck(std::vector<Card> &deck)
{
    // Following code from http://www.cplusplus.com/reference/algorithm/shuffle/
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(),std::default_random_engine(seed));
}
