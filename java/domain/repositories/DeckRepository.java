package domain.repositories;

import domain.model.card.Card;

public interface DeckRepository {
    public void createDeck();

    public Card draw();
}
