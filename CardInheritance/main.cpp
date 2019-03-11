//Andrew Cantrell
//OOP

#include <iostream>
#include "deck.h"

int main() {
    std::vector<Card*> deck = GenerateDeck();

    for(int i = 0; i < deck.size(); i++)
    {
        deck[i]->print();
        std::cout<<" ";
    }
}