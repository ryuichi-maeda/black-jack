from card_data import card_data

class Card:
    def __init__(self, num:int, suit:str):
        self.num:   int = num
        self.suit:  str = suit
        self.mark:  str = card_data[num]["mark"]
        self.score: int = card_data[num]["score"]
        

class ClubCard(Card):
    def __init__(self, num:int):
        super().__init__(num, "クラブ")
        

class HeartCard(Card):
    def __init__(self, num:int):
        super().__init__(num, "ハート")
        

class DiamondCard(Card):
    def __init__(self, num:int):
        super().__init__(num, "ダイヤ")
        

class SpadeCard(Card):
    def __init__(self, num:int):
        super().__init__(num, "スペード")
        
