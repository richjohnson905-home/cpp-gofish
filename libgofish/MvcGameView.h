//
// Created by Richard Johnson on 3/23/21.
//

#ifndef GOFISH_MVCGAMEVIEW_H
#define GOFISH_MVCGAMEVIEW_H


#include "MvcModel.h"

#include <iostream>

class MvcGameView {
private:
    MvcModel& m_model;

    const int PRECISION = 25;
    const int ROW_COUNT = 20;
    const bool m_slow = false;

    void renderHeader(std::ostream& out);
    void renderTable(std::ostream& out);
    void renderFooter(std::ostream& out);
    void renderFooter2(std::ostream& out);

    std::string getCardDisplay(std::optional<Card*>& card);
    std::string getBookDisplay(std::vector<std::optional<int>>& books);

public:

    MvcGameView(MvcModel& model);
    void render(std::ostream& out);
    void bannerMsg(std::ostream& out);
};


#endif //GOFISH_MVCGAMEVIEW_H
