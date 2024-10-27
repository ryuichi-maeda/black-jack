package domain.model.user;

import java.util.Scanner;

import domain.model.card.Card;

public class PlayerStrategy implements UserStrategy {
    private Scanner scanner;

    public PlayerStrategy(Scanner scanner) {
        this.scanner = scanner;
    }

    @Override
    public boolean shouldDraw(int score) {
        boolean res;
        while (true) {
            System.out.println("Do you want to draw a card? (y/n)");
            String input = scanner.nextLine().toLowerCase();

            if (input.equals("y") || input.equals("n")) {
                res = input.equals("y");
                break;
            }

            System.out.println("Invalid input. Please enter 'y' or 'n'.");
        }
        return res;
    }

    @Override
    public void showDrawnCard(Card card) {
        System.out.println("You drew a " + card.show());
    }

    @Override
    public void showHiddenCard() {
        System.out.println("You drew a hidden card");
    }

    @Override
    public void showResult(int score) {
        System.out.println("Your score: " + score);
    }

    @Override
    public void showCurrentScore(int score) {
        System.out.println("Your current score: " + score);
    }
}
