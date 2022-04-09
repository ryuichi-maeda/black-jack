#include <iostream>
#include <cstring>

#include "card.h"
#include "player.h"

using namespace std;


Player::Player(const char* n)
{
    name = new char[strlen(n)+1];
    strcpy(name, n);
}

// 引いたカードを追加
void Player::addDrawnCard(Card c)
{
    drawnCards.push_back(c);
}

// 得点を加算
void Player::addScore(int s)
{
    score += s;
}

// 引いたカードをコール
void Player::callDrawCard(Card c)
{
    cout << getName() << " draw " << c.getName() << " of " << c.getSuit() << endl;
}

// 得点が規定値を超えていないかチェック
bool Player::overScore()
{
    if (score > borderScore) {
        return true;
    } else {
        return false;
    }
}

User::User(const char* n)     : Player(n) {}
Dealer::Dealer(const char* n) : Player(n) {}