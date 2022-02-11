import random
from typing import List
from card import Card, ClubCard, DiamondCard, HeartCard, SpadeCard
from user import User



def create_deck() -> List[Card]:
    deck = []
    for i in range(1, 14):
        club_card    = ClubCard(i)
        heart_card   = HeartCard(i)
        diamond_card = DiamondCard(i)
        spade_card   = SpadeCard(i)

        deck.extend([club_card, heart_card, diamond_card, spade_card])

    return deck


class BlackJack:
    def __init__(self):
        self.deck   = create_deck()
        self.player = User("あなた")
        self.dealer = User("ディーラー")

    def start_game(self):
        print("☆★☆★☆★ ブラックジャックへようこそ！ ☆★☆★☆★")
        print("ゲームを開始します。")

        self.first_step()
        self.player_turn()
        if self.player.total_score <= 21:
            self.dealer_turn()

        self.end_game()

    # ゲームの初めに、プレイヤーとディーラーがそれぞれ2枚のカードを引く
    def first_step(self):
        self.player.draw_card(self.select_card())
        self.player.draw_card(self.select_card())
        self.dealer.draw_card(self.select_card())
        self.dealer.draw_second_card(self.select_card())
        
        self.player.echo_score()

    # ランダムにカードを選ぶ
    def select_card(self) -> Card:
        num: int = random.randrange(0, len(self.deck)-1)
        selected_card: Card = self.deck.pop(num)
        return selected_card

    def player_turn(self):
        # プレイヤーがカードを引くことを希望しない、もしくは21を超えない限り、カードを引き続ける
        while True:
            res: str = self.listen()
            if res == "N":
                break

            self.player.draw_card(self.select_card())
            self.player.echo_score()

            if self.player.total_score > 21:
                break

    # プレイヤーにカードを引くかどうか聞く
    # 入力がYかNになるまで聞き続ける
    def listen(self) -> str:
        while True:
            print("カードを引きますか？引く場合はYを、引かない場合はNを入力してください。")
            res: str = input()
            if res in ["Y", "N"]:
                break

        return res

    def dealer_turn(self):
        self.dealer.echo_second_card()
        self.dealer.echo_score()

        # 得点が17以上になるまでカードを引き続ける
        while self.dealer.total_score < 17:
            self.dealer.draw_card(self.select_card())
            self.dealer.echo_score()

            if self.dealer.total_score > 21:
                break

    def end_game(self):
        print(f"　あなた　の得点は{self.player.total_score}です。")
        print(f"ディーラーの得点は{self.dealer.total_score}です。")
        self.echo_winner()
        print("ブラックジャック終了！また遊んでね★")

    # 勝敗判定し、勝者を表示する
    def echo_winner(self):
        player_score = self.player.total_score
        dealer_score = self.dealer.total_score

        if player_score > 21 or dealer_score > player_score:
            print("ディーラーの勝ちです！")
        elif dealer_score > 21 or player_score > dealer_score:
            print("あなたの勝ちです！")
        else:
            print("引き分けです！")

