#include "Deck.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

Deck::Deck() {
 
    for (int i = 2; i < 15; i++) {
        cards.push_back(new Card(i, Card::hearts));
    }
    for (int i = 2; i < 15; i++) {
        cards.push_back(new Card(i, Card::diamonds));
    }
    for (int i = 2; i < 15; i++) {
        cards.push_back(new Card(i, Card::spades));
    }
    for (int i = 2; i < 15; i++) {
        cards.push_back(new Card(i, Card::clubs));
    }
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(cards.begin(), cards.end(), g);
}

int Deck::getDeckSize() {
    return cards.size();
}

Card* Deck::dealCard() {
    Card* c = cards.back();
    cards.pop_back();
    return c;
}

void Deck::showDeck() {
    std::cout << "Deck contains: " << cards.size() << std::endl;
    for (std::vector<Card*>::iterator it = cards.begin(); it != cards.end(); ++it) {
        std::cout << ' ' << (*it)->show() << std::endl;
    }
}

void Deck::initDeck(std::vector<Card*>& newCards) {
    cards.clear();
    for (std::vector<Card*>::iterator it = newCards.begin(); it != newCards.end(); ++it) {
        cards.push_back(*it);
    }
}