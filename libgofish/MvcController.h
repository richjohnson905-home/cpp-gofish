//
// Created by Richard Johnson on 3/23/21.
//

#ifndef GOFISH_MVCCONTROLLER_H
#define GOFISH_MVCCONTROLLER_H


#include "MvcGameView.h"

#include <iostream>

class IMvcController {
public:
    virtual void updateView(std::ostream& out) = 0;
    virtual void updatePlayAction(std::ostream& out) = 0;
};

class MvcController : public IMvcController {
private:
    MvcGameView& m_view;
    MvcModel& m_model;

public:
    MvcController(MvcGameView& view, MvcModel& model);
    void updateView(std::ostream& out);
    void updatePlayAction(std::ostream& out);
    void setRound(int round);
    void setHand1(const std::vector<Card*>* cards);
    void setHand2(const std::vector<Card*>* cards);
    void setHand3(const std::vector<Card*>* cards);
    void setBook1(const std::vector<int> cards);
    void setBook2(const std::vector<int> cards);
    void setBook3(const std::vector<int> cards);
    void setNames(std::string name1,std::string name2,std::string name3);
    void setWinner(std::string winner);
    void setPlayAction(std::string action);

};


#endif //GOFISH_MVCCONTROLLER_H
