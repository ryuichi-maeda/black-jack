#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <iostream>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;


// 勝者
enum Winner {
    USER,
    DEALER,
    NONE,
};

class BlackJack {
    private:
        User user;
        Dealer dealer;
        vector<Card> deck;
        int cardNum = 52;
        Winner winner;

        Card draw();
        void userDraw();
        void dealerDraw();

        void firstDrawByUser();
        void firstDrawByDealer();

        void ternUser();
        void ternDealer();

        void result();
    public:
        // カードの初期化
        BlackJack();
        void play();
        void show();
};

template <class T>
class SmallDeck {
    private:
        vector<T> deck;
    public:
        SmallDeck();
        vector<T> getDeck() {return deck;}
};

#endif