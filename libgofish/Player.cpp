#include "Player.h"
#include "Log.h"
#include "Strategy.h"

#include <iostream>
#include <map>
#include <utility>

using std::string;
using std::endl;
using std::cout;
using std::stringstream;
using std::to_string;
using std::vector;
using std::map;

  // Static Sort hand by card value function
bool Player::customCompare(const Card* lhs, const Card* rhs) { 
    return lhs->getValue() < rhs->getValue(); 
}

Player::Player(string name, Deck& deck)
:m_name(move(name)),
m_deck(deck),
m_pStrategy(nullptr){

}

int Player::getHandSize() const {
    return m_hand.size();
}

void Player::pushHandCard(Card* c) {
    m_hand.push_back(c);
}

void Player::pushHand(vector<Card*> cards) {
    m_hand.insert( m_hand.end(), cards.begin(), cards.end() );
}

void Player::showHand() const {
//    cout << m_name << "'s Hand contains: " << m_hand.size() << endl;
    for (auto it : m_hand) {
        cout << ' ' << it->show() << endl;
    }
}

void Player::sortHand() {
    sort(m_hand.begin(), m_hand.end(), customCompare);
}

void Player::takeTurn(vector<IPlayer*>& players) {
//    string banner = "\nIt is " + m_name + "'s turn";
//    m_pController->setPlayAction(banner);
//    m_pController->updatePlayAction(cout);
    m_pStrategy->takeTurn(players);
}

void Player::setStrategy(IStrategy* strategy) {
    m_pStrategy = strategy;
}

vector<Card*> Player::askPlayerForCards(IPlayer* p, int bait) {
    return p->doYouHave(bait);
}

vector<Card*> Player::doYouHave(int bait) {
    stringstream ss;
    for(auto & it : m_hand) {
        ss << it->getValue() << " ";
    }
    L_(ldebug1) << "\t" << m_name << " being asked for " << bait << " from my " << ss.str();
    string banner = "\n" + m_name + "  being asked for " + to_string(bait);
//    m_pController->setPlayAction(banner);
//    m_pController->updatePlayAction(cout);
    
    popEasyFish(bait);

    vector<Card*> returnCards;
    auto it = m_hand.begin();
    while (it != m_hand.end()) {
        if ((*it)->getValue() == bait) {
            returnCards.push_back(*it);
            it = m_hand.erase(it);
        } else {
            ++it;
        }
    }
    return returnCards;
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
            m_hand.erase(remove_if(m_hand.begin(), m_hand.end(),
                              [=](Card* x){return x->getValue() == e.first;}),
                                m_hand.end());
        }
    }
}

void Player::pushEasyFish(int fish) {
    m_easyFish.push_back(fish);
}

void Player::popEasyFish(int fish) {
    m_easyFish.erase(
            std::remove(m_easyFish.begin(),m_easyFish.end(), fish),
                    m_easyFish.end());
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
