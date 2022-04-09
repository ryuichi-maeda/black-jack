#include <iostream>
#include <cstring>
#include <string>
#include "card.h"

using namespace std;


void Card::setScoreByNum(int n)
{
    if (n >= 11) {
        score = 10;
    } else {
        score = n;
    }
}

void Card::setNameByNum(int n)
{
    switch(n) {
        case 1:
            name = "A";
            break;
        case 11:
            name = "J";
            break;
        case 12:
            name = "Q";
            break;
        case 13:
            name = "K";
            break;
        default:
            name = to_string(n);
            break;
    }
}

Card::Card(int n, const char* s)
{
    num = n;
    setScoreByNum(n);
    setNameByNum(n);

    // メモリの動的確保
    suit = new char[strlen(s)+1];
    strcpy(suit, s);
}

Club::Club(int n, const char* s)       : Card(n, s) {}
Diamond::Diamond(int n, const char* s) : Card(n, s) {}
Heart::Heart(int n, const char* s)     : Card(n, s) {}
Spade::Spade(int n, const char* s)     : Card(n, s) {}