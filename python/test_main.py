import unittest
from card import Card, ClubCard, SpadeCard
from blackjack import create_deck


class TestCreateDeck(unittest.TestCase):

    def setUp(self) -> None:
        self.deck = create_deck()

    def is_equal_card(self, one: Card, other: Card) -> bool:
        equal_num: bool  = one.num == other.num
        equal_suit: bool = one.suit == other.suit
        result = equal_num and equal_suit
        return result

    def test_first_card(self):
        start_card = ClubCard(1)
        result = self.is_equal_card(self.deck[0], start_card)
        self.assertTrue(result)

    def test_last_card(self):
        last_card = SpadeCard(13)
        result = self.is_equal_card(self.deck[51], last_card)
        self.assertTrue(result)

    def test_card_num(self):
        card_num = 52
        self.assertEqual(len(self.deck), card_num)

    def tearDown(self) -> None:
        del self.deck


if __name__ == "__main__":
    unittest.main()
