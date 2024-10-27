package domain.model.user;

import domain.model.card.Card;

public class DealerStrategy implements UserStrategy {
    @Override
    public boolean shouldDraw(int score) {
        return score < 17;
    }

    @Override
    public void showDrawnCard(Card card) {
        System.out.println("Dealer drew a " + card.show());
    }

    @Override
    public void showHiddenCard() {
        System.out.println("Dealer drew a hidden card");
    }

    @Override
    public void showResult(int score) {
        System.out.println("Dealer's score: " + score);
    }

    @Override
    public void showCurrentScore(int score) {
        // Do nothing
    }
}
