package domain.model.user;

import domain.model.card.Card;

public interface UserStrategy {
    public boolean shouldDraw(int score);

    public void showDrawnCard(Card card);

    public void showHiddenCard();

    public void showResult(int score);

    public void showCurrentScore(int score);
}
