#include "Strategy.h"
#include "Player.h"
#include "Log.h"

#include <iostream>

using namespace std;

Strategy::Strategy(ITurnHelper& turnHelper, IPlayer& myPlayer, Deck& deck)
:m_me(myPlayer),
m_turnHelper(turnHelper),
m_deck(deck)
{

}

void Strategy::takeTurn(vector<IPlayer*>& players)
{
    L_(linfo) << m_me.getName() << " Move Start";
    while (m_turnHelper.easyFish(players) ||
           m_turnHelper.hardFish(players, m_deck))
    {
        L_(linfo) << "Boom - go again player " << m_me.getName();
    }
}
