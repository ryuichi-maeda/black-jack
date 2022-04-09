#ifndef CARD_H_
#define CARD_H_

#include <string>

using namespace std;

class Card {
    protected:
        int num;
        int score;
        string name;
        char* suit;
        void setScoreByNum(int n);
        void setNameByNum(int n);
    public:
        Card(int n, const char* s);
        int getNum() {return num;}
        int getScore() {return score;}
        string getName() {return name;}
        char* getSuit() {return suit;}
};

class Club : public Card {
    public:
        Club(int n, const char* s = "club");
};

class Diamond : public Card {
    public:
        Diamond(int n, const char* s = "diamond");
};

class Heart : public Card {
    public:
        Heart(int n, const char* s = "heart");
};

class Spade : public Card {
    public:
        Spade(int n, const char* s = "spade");
};

#endif