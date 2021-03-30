//
// Created by Richard Johnson on 3/29/21.
//
#include "GoFishConfig.h"

GoFishConfig::GoFishConfig():
m_view(m_model),
m_controller(m_view, m_model),
m_ai1("Ava", m_deck),
m_ai2("Jarvis", m_deck),
m_ai3("Rich", m_deck),
m_turnHelper1(m_helper, m_ai1),
m_turnHelper2(m_helper, m_ai2),
m_turnHelper3(m_helper, m_ai3),
m_goFishStrategyAi1(m_turnHelper1, m_ai1, m_deck),
m_goFishStrategyAi2(m_turnHelper2, m_ai2, m_deck),
m_goFishStrategyAi3(m_turnHelper3, m_ai3, m_deck),
m_game(m_players, 7, m_deck, m_controller)
{
    int order = m_util.getRandomNumber(0, 3);
    if (order == 0) {
        m_players.push_back(&m_ai1);
        m_players.push_back(&m_ai2);
        m_players.push_back(&m_ai3);
        m_controller.setNames("Ava", "Jarvis", "Rich");
    } else if (order == 1) {
        m_players.push_back(&m_ai2);
        m_players.push_back(&m_ai3);
        m_players.push_back(&m_ai1);
        m_controller.setNames("Jarvis", "Rich", "Ava");
    } else {
        m_players.push_back(&m_ai3);
        m_players.push_back(&m_ai1);
        m_players.push_back(&m_ai2);
        m_controller.setNames("Rich", "Ava", "Jarvis");
    }
    m_ai1.setStrategy(&m_goFishStrategyAi1);
    m_ai2.setStrategy(&m_goFishStrategyAi2);
    m_ai3.setStrategy(&m_goFishStrategyAi3);
}

GoFishGame GoFishConfig::getGame() const {
    return m_game;
}