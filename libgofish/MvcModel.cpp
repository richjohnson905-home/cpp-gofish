//
// Created by Richard Johnson on 3/23/21.
//

#include "MvcModel.h"

using namespace std;

void MvcModel::setRound(int round) {
    m_round = round;
}

void MvcModel::setHand1(const std::vector<Card*>* cards) {
    m_player1Cards = cards;
}

void MvcModel::setHand2(const std::vector<Card*>* cards) {
    m_player2Cards = cards;
}

void MvcModel::setHand3(const std::vector<Card*>* cards) {
    m_player3Cards = cards;
}
void MvcModel::setBooks1(const std::vector<int> books){
    m_books1 = books;
}
void MvcModel::setBooks2(const std::vector<int> books){
    m_books2 = books;
}
void MvcModel::setBooks3(const std::vector<int> books){
    m_books3 = books;
}
void MvcModel::setNames(std::string& name1,std::string& name2,std::string& name3) {
    m_name1 = name1;
    m_name2 = name2;
    m_name3 = name3;
}
vector<optional<Card*>> MvcModel::getPlayer1Cards() const {
    vector<optional<Card*>> filled(ROW_COUNT);
    filled.insert(
            filled.begin(),
            std::make_move_iterator(m_player1Cards->begin()),
            std::make_move_iterator(m_player1Cards->end())
    );
    return filled;
}

vector<optional<Card*>> MvcModel::getPlayer2Cards() const {
    vector<optional<Card*>> filled(ROW_COUNT);
    filled.insert(
            filled.begin(),
            std::make_move_iterator(m_player2Cards->begin()),
            std::make_move_iterator(m_player2Cards->end())
    );
    return filled;
}

vector<optional<Card*>> MvcModel::getPlayer3Cards() const {
    vector<optional<Card*>> filled(ROW_COUNT);
    filled.insert(
            filled.begin(),
            std::make_move_iterator(m_player3Cards->begin()),
            std::make_move_iterator(m_player3Cards->end())
    );
    return filled;
}
std::vector<std::optional<int>> MvcModel::getPlayer1Books() const {
    vector<optional<int>> filled(10);
    filled.insert(
            filled.begin(),
            std::make_move_iterator(m_books1.begin()),
            std::make_move_iterator(m_books1.end())
    );
    return filled;
}
std::vector<std::optional<int>> MvcModel::getPlayer2Books() const {
    vector<optional<int>> filled(10);
    filled.insert(
            filled.begin(),
            std::make_move_iterator(m_books2.begin()),
            std::make_move_iterator(m_books2.end())
    );
    return filled;
}
std::vector<std::optional<int>> MvcModel::getPlayer3Books() const {
    vector<optional<int>> filled(10);
    filled.insert(
            filled.begin(),
            std::make_move_iterator(m_books3.begin()),
            std::make_move_iterator(m_books3.end())
    );
    return filled;
}

void MvcModel::setWinner(std::string winner) {
    m_winner = winner;
}
