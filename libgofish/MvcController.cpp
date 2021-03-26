//
// Created by Richard Johnson on 3/23/21.
//

#include "MvcController.h"

using namespace std;

MvcController::MvcController(MvcGameView& view, MvcModel& model): m_view(view), m_model(model) {

}

void MvcController::updateView(ostream& out) {
    m_view.render(out);
}

void MvcController::updatePlayAction(std::ostream &out) {
    m_view.bannerMsg(out);
}

void MvcController::setRound(int round) {
    m_model.setRound(round);
}

void MvcController::setHand1(const vector<Card*>* cards) {
    m_model.setHand1(cards);
}

void MvcController::setHand2(const vector<Card*>* cards) {
    m_model.setHand2(cards);
}

void MvcController::setHand3(const vector<Card*>* cards) {
    m_model.setHand3(cards);
}
void MvcController::setBook1(const vector<int> books){
    m_model.setBooks1(books);
}
void MvcController::setBook2(const vector<int> books){
    m_model.setBooks2(books);
}
void MvcController::setBook3(const vector<int> books){
    m_model.setBooks3(books);
}
void MvcController::setNames(string name1, string name2, string name3){
    m_model.setNames(name1, name2, name3);
}
void MvcController::setWinner(string winner) {
    m_model.setWinner(winner);
}
void MvcController::setPlayAction(std::string action) {
    m_model.setPlayAction(action);
}
