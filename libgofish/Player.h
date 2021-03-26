#ifndef DECK_PLAYER_H
#define DECK_PLAYER_H

#include "Card.h"
#include "Deck.h"
#include "MvcController.h"

#include <vector>
#include <set>
#include <string>

class IStrategy;

class IPlayer {
public:
    virtual void pushHandCard(Card* c) = 0;
    virtual void pushHand(std::vector<Card*> cards) = 0;
    virtual const std::vector<Card*>* getHand() const = 0;
    virtual void makeBooks() = 0;
    virtual void pushEasyFish(int fish) = 0;
    virtual bool hasEasyFish(int bait) const = 0;
    virtual int getHandSize() const = 0;
    virtual std::vector<Card*> askPlayerForCards(IPlayer* p, int bait) = 0;
    virtual std::string getName() = 0;
    virtual std::vector<Card*> doYouHave(int bait) = 0;
    virtual void takeTurn(std::vector<IPlayer*>& players) = 0;
    virtual std::vector<int> getBooks() const = 0;
    virtual void sortHand() = 0;
};

class Player : public IPlayer
{
protected:
    std::vector<Card*> m_hand;
    std::string m_name;
    IStrategy* m_pStrategy;
    std::vector<int> m_books;
    Deck& m_deck;
    std::vector<int> m_easyFish;
    IMvcController* m_pController;

    static bool customCompare(const Card *lhs, const Card *rhs);

public:
    Player(std::string name, Deck& deck, IMvcController* controller);
    virtual ~Player() {}

    virtual int getHandSize() const;
    virtual void pushHandCard(Card* c);
    virtual void pushHand(std::vector<Card*> cards);
    virtual const std::vector<Card*>* getHand() const {return &m_hand;}
    virtual std::vector<Card*> doYouHave(int bait);
    virtual std::vector<Card*> askPlayerForCards(IPlayer* p, int bait);
    virtual void pushEasyFish(int fish);
    virtual bool hasEasyFish(int bait) const;
    virtual void makeBooks();
    virtual std::string getName() {return m_name;}
    virtual void takeTurn(std::vector<IPlayer*>& players);
    virtual void sortHand();
    virtual std::vector<int> getBooks() const {return m_books;}

    void showHand() const;
    void setStrategy(IStrategy* strategy);
    void popEasyFish(int fish);
    std::vector<int> getEasyFish();
    
};
 

#endif