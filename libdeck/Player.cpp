#include "Player.h"
#include "Log.h"

#include <time.h>
#include <iostream>
#include <map>

using namespace std;

  // Static Sort hand by card value function
bool Player::customCompare(const Card* lhs, const Card* rhs) { 
    return lhs->getValue() < rhs->getValue(); 
}

Player::Player(string name, Deck& deck):m_name(name), m_deck(deck){

}

int Player::getHandSize() const {
    return m_hand.size();
}

void Player::pushHand(Card* c) {
    m_hand.push_back(c);
}

void Player::pushHand(vector<Card*> cards) {
    m_hand.insert( m_hand.end(), cards.begin(), cards.end() );
}

void Player::showHand() const {
    cout << m_name << "'s Hand contains: " << m_hand.size() << endl;
    for (vector<Card*>::const_iterator it = m_hand.begin(); it != m_hand.end(); ++it) {
        cout << ' ' << (*it)->show() << endl;
    }
}

void Player::sortHand() {
    sort(m_hand.begin(), m_hand.end(), customCompare);
}

void Player::takeTurn(vector<Player*>& players) {
    m_strategy->takeTurn(players);
    makeBooks();
}

void Player::setStrategy(IStrategy* strategy) {
    m_strategy = strategy;
}

bool Player::otherHasCards(Player* p, vector<Card*>& cards, int fish) {
    p->doYouHave(fish, cards);
    return cards.size() > 0;
}

void Player::doYouHave(int bait, vector<Card*>& cards) {
    std::stringstream ss;
    for(vector<Card*>::const_iterator it = m_hand.begin(); it != m_hand.end(); ++it) {
        ss << (*it)->getValue() << " ";
    }
    L_(ldebug1) << "\t" << m_name << " being asked for " << bait << " from my " << ss.str();
    
    popEasyFish(bait);
    vector<Card*>::iterator it = m_hand.begin();
    while (it != m_hand.end()) {
        if ((*it)->getValue() == bait) {
            cards.push_back(*it);
            it = m_hand.erase(it);
        } else {
            ++it;
        }
    }
}

void Player::makeBooks() {
    map<int, int> frequency;
    for(Card* i: m_hand) {
        ++frequency[i->getValue()];
    }
    for(const auto& e: frequency) {
        if (e.second == 4) {
            L_(linfo) << "MAKING BOOK for " << e.first << "!!";
            popEasyFish(e.first);
            m_books.push_back(e.first);
            m_hand.erase(std::remove_if(m_hand.begin(), 
                              m_hand.end(),
                              [=](Card* x){return x->getValue() == e.first;}),
                                m_hand.end());
        }
    }
}

void Player::pushEasyFish(int fish) {
    m_easyFish.push_back(fish);
}

void Player::popEasyFish(int fish) {
    m_easyFish.erase(std::remove(m_easyFish.begin(), m_easyFish.end(), fish), m_easyFish.end());
}

bool Player::hasEasyFish(int bait) const {
    if(find(m_easyFish.begin(), m_easyFish.end(), bait) != m_easyFish.end()) {
        return true;
    } else {
        return false;
    }
}

vector<int> Player::getEasyFish() {
    return m_easyFish;
}
