#include "Card.h"

#include <sstream>
#include <iostream>

Card::Card(int value, suit mySuit) {
    value_ = value;
    suit_ = mySuit;
}

int Card::getValue() const
{
    return value_;
}

Card::suit Card::getSuit() const
{
    return suit_;
}

std::string Card::getCardValue() const {
    if (value_ < 11) {
        return std::to_string(value_);
    } else {
        switch(value_) {
            case 11:
                return "J";
            case 12:
                return "Q";
            case 13:
                return "K";
            case 14:
                return "A";
            default:
                std::cout << "UNKNOWN CARD VALUE: " << value_ << std::endl;
                return "U";
        }
    }
}

std::string Card::getSuitValue() const {
    switch(suit_) {
        case Card::hearts:
            return "HEARTS";
        case Card::diamonds:
            return "DIAMONDS";
        case Card::spades:
            return "SPADES";
        case Card::clubs:
            return "CLUBS";
        default:
            std::cout << "UNKNOWN CARD SUIT: " << suit_ << std::endl;
            return "UNK SUIT";
    }
}

std::string Card::show() const {
    std::stringstream ss;

    ss << getCardValue() << ":" << getSuitValue();
    return ss.str();
}

