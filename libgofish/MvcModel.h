//
// Created by Richard Johnson on 3/23/21.
//

#ifndef GOFISH_MVCMODEL_H
#define GOFISH_MVCMODEL_H

#include <vector>
#include <optional>

#include <Card.h>

class MvcModel {
private:
    int m_round;
    std::vector<int> m_books1;
    std::vector<int> m_books2;
    std::vector<int> m_books3;
    const std::vector<Card*>* m_player1Cards;
    const std::vector<Card*>* m_player2Cards;
    const std::vector<Card*>* m_player3Cards;
    std::string m_name1;
    std::string m_name2;
    std::string m_name3;
    std::string m_winner;

    int const ROW_COUNT = 20;

public:
    void setRound(int round);
    void setHand1(const std::vector<Card*>* cards);
    void setHand2(const std::vector<Card*>* cards);
    void setHand3(const std::vector<Card*>* cards);
    void setBooks1(const std::vector<int> books);
    void setBooks2(const std::vector<int> books);
    void setBooks3(const std::vector<int> books);
    void setNames(std::string& name1,std::string& name2,std::string& name3);
    std::string getName1() const {return m_name1;}
    std::string getName2() const {return m_name2;}
    std::string getName3() const {return m_name3;}
    [[nodiscard]] std::vector<std::optional<Card*>> getPlayer1Cards() const;
    [[nodiscard]] std::vector<std::optional<Card*>> getPlayer2Cards() const;
    [[nodiscard]] std::vector<std::optional<Card*>> getPlayer3Cards() const;
    [[nodiscard]] std::vector<std::optional<int>> getPlayer1Books() const;
    [[nodiscard]] std::vector<std::optional<int>> getPlayer2Books() const;
    [[nodiscard]] std::vector<std::optional<int>> getPlayer3Books() const;

    int getRound() const {return m_round;}
    void setWinner(std::string winner);
    std::string getWinner() const {return m_winner;}


};


#endif //GOFISH_MVCMODEL_H
