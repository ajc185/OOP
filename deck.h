//Andrew Cantrell
//OOP Game of War Assignment

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
struct card{
    Rank rank;
    Suit suit;
};

//Player Class
class player{
    private:
        std::vector<card> pile; //pile for cards won
        std::vector<card> deck; //deck of cards to play

    public:
        int deckSize(){return deck.size();}; //return # of cards in deck
        int pileSize(){return pile.size();}; //return # of cards in pile

        //pop card off the back of the deck and return that card
        card popOff(){
            card Card = this->deck.back();
            this->deck.pop_back();
            return Card;
        };

        //return rank of the top card in the deck
        Rank getRank(){
            return this->deck.back().rank;
        };

        //pushes the card passed to the function to the pile
        void pushToPile(card Card){
            this->pile.push_back(Card);
        };

        void CheckDeck();

        void SplitDeck(player&); //splits the deck in half between
                                //the player calling the function
                                //and the player passed to the function

        void ShuffleDeck(); //Shuffles the deck elements (cards) randomly
        void GenerateDeck(); //Generates vector of 52 playing cards
};

card newCard(Rank r, Suit s); //card constructor, takes rank and suit

//Pops card from each player's deck and adds them to WinPile
void PlayCards(std::vector<card>&,std::vector<card>&,std::vector<card>&,std::vector<card>&);

//Return true only if one player has run out of cards both in their deck and pile
bool Winner(player&, player&); 

//Pops cards from each Player's deck vector, compares them and awards both cards
//to the player with a card of higher rank. In case of tie, 3 cards (if available) 
//are added to the WinPile by each player, and then a new card is popped from both 
//player's decks and compared.
void War(player&, player&);
