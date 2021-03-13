#include "HumanStrategy.h"

#include <iostream>

HumanStrategy::HumanStrategy(Player* myPlayer, Deck& deck):me_(myPlayer) {

}

void HumanStrategy::takeTurn(std::vector<Player*>& players) {

}

// void HumanStrategy::makeMove(std::vector<Player*>& players) {
//     // while ask random player for cards gives cards
//     // else take one card and turn is over
//     std::cout << me_->getName() << " making move" << std::endl;
// }

// void HumanStrategy::doYouHave(int fish, std::vector<Card*>& cards) {
//     // std::vector<Card*>* myCards = me_->getHand();
//     // std::vector<Card*>::iterator it = myCards->begin();
//     // while (it != myCards->end()) {
//     //     if ((*it)->getValue() == fish) {
//     //         cards.push_back(*it);
//     //         it = myCards->erase(it);
//     //     } else {
//     //         ++it;
//     //     }
//     // }
// }