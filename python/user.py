from typing import List
from card import Card

class User:
    def __init__(self, role:str):
        # roleはplayerかdealerのどちらか
        self.role        = role
        self.total_score = 0
        self.cards       = []

    def draw_card(self, card:Card):
        self.cards.append(card)
        print(f"{self.role}の引いたカードは{card.suit}の{card.mark}です。")
        self.total_score += card.score

    def draw_second_card(self, card:Card):
        self.cards.append(card)
        print(f"{self.role}の2枚目のカードは分かりません。")
        self.total_score += card.score

    def echo_score(self):
        print(f"{self.role}の現在の得点は{self.total_score}です。")

    def echo_second_card(self):
        second_card = self.cards[1]
        print(f"{self.role}の2枚目のカードは{second_card.suit}の{second_card.mark}でした。")