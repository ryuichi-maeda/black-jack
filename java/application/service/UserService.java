package application.service;

import domain.model.card.Card;
import domain.model.user.UserStrategy;

public class UserService {
    private UserStrategy userStrategy;
    private int score;

    public UserService(UserStrategy userStrategy) {
        this.userStrategy = userStrategy;
        this.score = 0;
    }

    public void addScore(int score) {
        this.score += score;
    }

    public int getScore() {
        return this.score;
    }

    public boolean shouldDraw() {
        return this.userStrategy.shouldDraw(this.score);
    }

    public void showDrawnCard(Card card) {
        this.userStrategy.showDrawnCard(card);
    }

    public void showHiddenCard() {
        this.userStrategy.showHiddenCard();
    }

    public void showResult() {
        this.userStrategy.showResult(this.score);
    }

    public void showCurrentScore() {
        this.userStrategy.showCurrentScore(this.score);
    }
}
