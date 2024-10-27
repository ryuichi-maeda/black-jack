package infrastructure;

import java.util.ArrayList;
import java.util.Random;

import domain.model.card.Card;
import domain.model.card.Deck;
import domain.model.card.Suit;
import domain.repositories.DeckRepository;

public class InMemoryDeckRepositoryImpl implements DeckRepository {
    private Deck deck;

    public InMemoryDeckRepositoryImpl() {
        this.deck = new Deck();
    }

    @Override
    public void createDeck() {
        ArrayList<Suit> suits = new ArrayList<>();
        for (Suit suit : Suit.values()) {
            suits.add(suit);
        }
        for (Suit suit : suits) {
            for (int i = 1; i <= 13; i++) {
                String name = "";
                switch (i) {
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
                        name = Integer.toString(i);
                        break;
                }
                this.deck.add(new Card(suit, i, name));
            }
        }
    }

    @Override
    public Card draw() {
        Random random = new Random();
        int index = random.nextInt(this.deck.getNumberOfCards());
        return this.deck.draw(index);
    }
}
