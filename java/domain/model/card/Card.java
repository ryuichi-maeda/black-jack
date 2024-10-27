package domain.model.card;

public class Card {
    private Suit suit;
    private int value;
    private String name;

    public Card(Suit suit, int value, String name) {
        this.suit = suit;
        this.value = value;
        this.name = name;
    }

    public Suit getSuit() {
        return this.suit;
    }

    public int getScore() {
        if (this.value > 10) {
            return 10;
        }
        return this.value;
    }

    public String getName() {
        return this.name;
    }

    public String show() {
        return this.name + " of " + this.suit.getSuit();
    }
}
