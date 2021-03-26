//
// Created by Richard Johnson on 3/23/21.
//

#include "MvcGameView.h"

#include <iomanip>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;

MvcGameView::MvcGameView(MvcModel& model):m_model(model) {

}

void MvcGameView::render(std::ostream &out) {
    renderHeader(out);
    renderTable(out);
    renderFooter(out);
    renderFooter2(out);
}

void MvcGameView::bannerMsg(std::ostream &out) {
    string msg = m_model.getPlayAction();
    if (m_slow) {
        int x = 0;
        while (msg[x] != '\0') {
            out << msg[x] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            x++;
        };
    } else {
        out << msg;
    }
}

void MvcGameView::renderHeader(std::ostream &out) {
    out << endl;
    out << endl;
    out << "\t\t================= ROUND " << m_model.getRound() << " =================" << endl;
}

std::string MvcGameView::getCardDisplay(std::optional<Card*>& card) {
    stringstream ss;
    if (card.has_value()) {
        ss << card.value()->getValue();
    } else {
        ss << "";
    }
    return ss.str();
}

std::string MvcGameView::getBookDisplay(vector<optional<int>> &books) {
    stringstream ss;
    for (auto & b : books) {
        if (b.has_value()) {
            ss << b.value() << " ";
        }
    }
    return ss.str();
}

void MvcGameView::renderTable(std::ostream& out) {
    vector<optional<Card*>> p1 = m_model.getPlayer1Cards();
    vector<optional<Card*>> p2 = m_model.getPlayer2Cards();
    vector<optional<Card*>> p3 = m_model.getPlayer3Cards();
//    out << left << setw(PRECISION) << m_model.getName1() << setw(PRECISION) << m_model.getName2() << right << setw(PRECISION) << m_model.getName3() <<  endl;
//
//    for (int i = 0; i < ROW_COUNT; ++i) {
//        out << left << setw(PRECISION) << getCardDisplay(p1.at(i)) << setw(PRECISION) << getCardDisplay(p2.at(i)) << right << setw(PRECISION) << getCardDisplay(p3.at(i)) <<  endl;
//    }
    out << "\n" << m_model.getName1() << "\t";
    for (int i = 0; i < ROW_COUNT; ++i) {
        out << " " << getCardDisplay(p1.at(i));
    }
    vector<optional<int>> b1 = m_model.getPlayer1Books();
    string b1Display = getBookDisplay(b1);
    out << endl << "\tBooks: " << b1Display << endl;

    out << "\n" << m_model.getName2() << "\t";
    for (int i = 0; i < ROW_COUNT; ++i) {
        out << " " << getCardDisplay(p2.at(i));
    }
    vector<optional<int>> b2 = m_model.getPlayer2Books();
    string b2Display = getBookDisplay(b2);
    out << endl << "\tBooks: " << b2Display << endl;

    out << "\n" << m_model.getName3() << "\t";
    for (int i = 0; i < ROW_COUNT; ++i) {
        out << " " << getCardDisplay(p3.at(i));
    }
    vector<optional<int>> b3 = m_model.getPlayer3Books();
    string b3Display = getBookDisplay(b3);
    out << endl << "\tBooks: " << b3Display << endl;
}

void MvcGameView::renderFooter(std::ostream &out) {
//    out << "Books" << endl;
//    vector<optional<int>> b1 = m_model.getPlayer1Books();
//    string b1Display = getBookDisplay(b1);
//    vector<optional<int>> b2 = m_model.getPlayer2Books();
//    string b2Display = getBookDisplay(b2);
//    vector<optional<int>> b3 = m_model.getPlayer3Books();
//    string b3Display = getBookDisplay(b3);
//    out << left << setw(PRECISION) << b1Display << setw(PRECISION) << b2Display << right << setw(PRECISION) << b3Display << endl;
}

void MvcGameView::renderFooter2(std::ostream &out) {
    if (!m_model.getWinner().empty()) {
        out << "\n\nWE HAVE A ROUND " << m_model.getRound() << " WINNER: " << m_model.getWinner() << endl;
    }
}
