#include <iostream>
#include <random>
#include <vector>

#include "blackjack.h"
#include "card.h"

using namespace std;


// スートごとのデッキを生成
template <class T>
SmallDeck<T>::SmallDeck()
{
    for (int i=1; i<=13; i++) {
        T card(i);
        deck.push_back(card);
    }
}

// 初期化（カード，勝者）
BlackJack::BlackJack()
{
    SmallDeck<Club>    clubDeck;
    SmallDeck<Diamond> diaDeck;
    SmallDeck<Heart>   heartDeck;
    SmallDeck<Spade>   spadeDeck;

    vector<Club>    pClubDeck  = clubDeck.getDeck();
    vector<Diamond> pDiaDeck   = diaDeck.getDeck();
    vector<Heart>   pHeartDeck = heartDeck.getDeck();
    vector<Spade>   pSpadeDeck = spadeDeck.getDeck();

    deck.insert(deck.end(), pClubDeck.begin(),  pClubDeck.end());
    deck.insert(deck.end(), pDiaDeck.begin(),   pDiaDeck.end());
    deck.insert(deck.end(), pHeartDeck.begin(), pHeartDeck.end());
    deck.insert(deck.end(), pSpadeDeck.begin(), pSpadeDeck.end());

    winner = NONE;
}

void BlackJack::play()
{
    cout << "-----------------------------------" << endl;
    cout << "       WELCOME TO BLACK JACK       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "            GAME START!            " << endl;
    cout << endl;

    // ユーザーが先に2枚引く
    firstDrawByUser();
    cout << "Your total score is " << user.getScore() << " now" << endl;
    cout << endl;

    // ディーラーが2枚引く
    firstDrawByDealer();
    cout << endl;

    // ユーザーの追加ドローターン
    cout << "<------------ YOUR TURN ---------->" << endl;
    ternUser();
    cout << endl;

    if (winner == DEALER) {
        // 結果発表
        result();
        return;
    }

    // ディーラーの追加ドローターン
    cout << "<----------- DEALER TURN --------->" << endl;
    ternDealer();
    cout << endl;
    
    if (winner == USER) {
        // 結果発表
        result();
        return;
    }

    // 結果発表
    result();
}

// カードを引く
Card BlackJack::draw()
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(0, cardNum-1);

    // ランダムにカードを引く
    int randNum = distr(eng);
    Card drawnCard = deck[randNum];

    // 引いたカードを削除
    deck.erase(deck.begin() + randNum);
    cardNum--;

    return drawnCard;
}

// ユーザーがカードを引く
void BlackJack::userDraw()
{
    Card drawnCard = draw();
    user.addDrawnCard(drawnCard);
    user.addScore(drawnCard.getScore());
    user.callDrawCard(drawnCard);
}

// ディーラーがカードを引く
void BlackJack::dealerDraw()
{
    Card drawnCard = draw();
    dealer.addDrawnCard(drawnCard);
    dealer.addScore(drawnCard.getScore());
}

// ユーザーが先に2枚引く
void BlackJack::firstDrawByUser()
{
    for (int i=0; i<2; i++) {
        userDraw();
    }
}

// ディーラーが2枚引く
void BlackJack::firstDrawByDealer()
{
    for (int i=0; i<2; i++) {
        dealerDraw();
    }

    vector<Card> drawnCards = dealer.getDrownCards();
    dealer.callDrawCard(drawnCards[0]);

    cout << "Second card of dealer is secret" << endl;
}

// ユーザーの追加ドローターン
void BlackJack::ternUser()
{
    char ans;
    while (true) {
        cout << "Do you want to draw a card? (Y/N)" << endl;
        cin >> ans;

        if (ans == 'Y') {
            // カードを引く
            userDraw();
            // 規定値を超えていたら負け
            if (user.overScore()) {
                winner = DEALER;
                break;
            }
            cout << "Your total score is " << user.getScore() << " now" << endl;
        } else if (ans == 'N') {
            break;
        } else {
            cout << "You must enter Y or N" << endl;
        }
    }
}

// ディーラーの追加ドローターン
void BlackJack::ternDealer()
{
    vector<Card> drawnCards = dealer.getDrownCards();
    cout << "Second card of dealer was " << drawnCards.back().getName() << " of " << drawnCards.back().getSuit() << endl;
    cout << "Dealer's total score is " << dealer.getScore() << " now" << endl;

    while (dealer.getScore() < 17) {
        dealerDraw();
        dealer.callDrawCard(dealer.getDrownCards().back());

        if (dealer.overScore()) {
            winner = USER;
            break;
        }

        cout << "Dealer's total score is " << dealer.getScore() << " now" << endl;
    }
}

// 結果発表
void BlackJack::result()
{
    cout << "<------------- RESULT ------------>" << endl;
    cout << "Your total score is " << user.getScore() << endl;
    cout << "Dealer's total score is " << dealer.getScore() << endl;

    // ユーザーとディーラーが規定値を超えていないときの勝敗判定
    if (winner == NONE) {
        if (user.getScore() > dealer.getScore()) {
            winner = USER;
        } else if (user.getScore() < dealer.getScore()) {
            winner = DEALER;
        }
    }

    cout << endl;
    switch (winner)
    {
        case USER:
            cout << "YOU WIN !!" << endl;
            break;
        case DEALER:
            cout << "YOU LOSE..." << endl;
            break;
        default:
            cout << "YOU DREW WITH DEALER" << endl;
            break;
    }
    cout << endl;

    cout << "black jack was over" << endl;
    cout << "Let's play again!!" << endl;
}

void BlackJack::show()
{
    for (Card& card : deck) {
        cout << card.getSuit() << " " << card.getNum() << " " << card.getName() << " " << card.getScore() << endl;
    }

    cout << "card num: " << cardNum << endl;
}