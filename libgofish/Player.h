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
    [[nodiscard]] virtual bool hasEasyFish(int bait) const = 0;
    [[nodiscard]] virtual int getHandSize() const = 0;
    virtual std::vector<Card*> askPlayerForCards(IPlayer* p, int bait) = 0;
    virtual std::string getName() = 0;
    virtual std::vector<Card*> doYouHave(int bait) = 0;
    virtual void takeTurn(std::vector<IPlayer*>& players) = 0;
    [[nodiscard]] virtual std::vector<int> getBooks() const = 0;
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
    virtual ~Player() = default;

    [[nodiscard]] int getHandSize() const override;
    void pushHandCard(Card* c) override;
    void pushHand(std::vector<Card*> cards) override;
    [[nodiscard]] const std::vector<Card*>* getHand() const override {return &m_hand;}
    std::vector<Card*> doYouHave(int bait) override;
    std::vector<Card*> askPlayerForCards(IPlayer* p, int bait) override;
    void pushEasyFish(int fish) override;
    [[nodiscard]] bool hasEasyFish(int bait) const override;
    void makeBooks() override;
    std::string getName() override {return m_name;}
    void takeTurn(std::vector<IPlayer*>& players) override;
    void sortHand() override;
    [[nodiscard]] std::vector<int> getBooks() const override {return m_books; }

    void showHand() const;
    void setStrategy(IStrategy* strategy);
    void popEasyFish(int fish);
    std::vector<int> getEasyFish();
    
};
 

#endif