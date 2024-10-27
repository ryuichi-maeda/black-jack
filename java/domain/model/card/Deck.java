package domain.model.card;

import java.util.ArrayList;
import java.util.List;

public class Deck {
    private List<Card> cards;

    public Deck() {
        this.cards = new ArrayList<Card>();
    }

    public void add(Card card) {
        this.cards.add(card);
    }

    public int getNumberOfCards() {
        return this.cards.size();
    }

    public Card draw(int index) {
        return this.cards.remove(index);
    }
}
