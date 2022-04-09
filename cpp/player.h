#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;


class Player {
    private:
        vector<Card> drawnCards;
        int score = 0;
        int borderScore = 21;
        char* name;
    public:
        Player(const char* n);

        void addDrawnCard(Card c);
        vector<Card> getDrownCards() {return drawnCards;}

        void addScore(int s);
        int  getScore() {return score;}

        char* getName() {return name;}

        void callDrawCard(Card c);

        bool overScore();
};

class User : public Player {
    public:
        User(const char* n = "You");
};

class Dealer : public Player {
    public:
        Dealer(const char* n = "Dealer");
};

#endif