#ifndef DECK_PLAYER_H
#define DECK_PLAYER_H

#include "Card.h"
#include "IStrategy.h"
#include "Deck.h"

#include <vector>
#include <set>
#include <string>

class Player
{
public:
    Player(std::string name, Deck& deck);
    virtual ~Player() {}

    virtual int getHandSize() const;
    void showHand() const;
    void sortHand();
    void takeTurn(std::vector<Player*>& players);
    virtual void pushHandCard(Card* c);
    virtual void pushHand(std::vector<Card*> cards);
    
    void setStrategy(IStrategy* strategy);
    std::string getName() {return m_name;}
    virtual const std::vector<Card*>* getHand() const {return &m_hand;}
    virtual std::vector<Card*> doYouHave(int bait);
    std::vector<int> getBooks() const {return m_books;}

    virtual std::vector<Card*> askPlayerForCards(Player* p, int bait);
    virtual void pushEasyFish(int fish);
    void popEasyFish(int fish);
    virtual bool hasEasyFish(int bait) const;
    

    // test public
    void makeBooks();
    std::vector<int> getEasyFish();
    
protected:
    std::vector<Card*> m_hand;
    std::string m_name;
    IStrategy* m_strategy;
    std::vector<int> m_books;
    Deck& m_deck;
    std::vector<int> m_easyFish;

    static bool customCompare(const Card *lhs, const Card *rhs);
};
 

#endif