//
// Created by Richard Johnson on 3/25/21.
//

#ifndef GOFISH_MOCKMVCCONTROLLER_H
#define GOFISH_MOCKMVCCONTROLLER_H

#include "trompeloeil.hpp"
#include "MvcController.h"

class MockMvcController : public IMvcController {
public:
    MAKE_MOCK1(updateView, void(std::ostream& out));
    MAKE_MOCK1(updatePlayAction, void(std::ostream& out));

};

#endif //GOFISH_MOCKMVCCONTROLLER_H
