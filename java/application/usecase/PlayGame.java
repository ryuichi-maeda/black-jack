package application.usecase;

import application.service.UserService;
import domain.model.card.Card;
import domain.model.game.Result;
import domain.repositories.DeckRepository;

public class PlayGame {
    private UserService playerService;
    private UserService dealerService;
    private DeckRepository deckRepository;

    public PlayGame(UserService playerService, UserService dealerService, DeckRepository deckRepository) {
        this.playerService = playerService;
        this.dealerService = dealerService;
        this.deckRepository = deckRepository;
    }

    private void drawCard(UserService user) {
        Card card = this.deckRepository.draw();
        user.addScore(card.getScore());
        user.showDrawnCard(card);
        user.showCurrentScore();
    }

    private void drawHiddenCard(UserService user) {
        Card card = this.deckRepository.draw();
        user.addScore(card.getScore());
        user.showHiddenCard();
    }

    private Result getPlayerResult() {
        int playerScore = this.playerService.getScore();
        int dealerScore = this.dealerService.getScore();

        if (playerScore < 21) {
            if (dealerScore > 21) {
                return Result.WIN;
            }

            if (playerScore > dealerScore) {
                return Result.WIN;
            } else if (playerScore < dealerScore) {
                return Result.LOSE;
            } else {
                return Result.DRAW;
            }
        } else {
            if (dealerScore < 21) {
                return Result.LOSE;
            } else {
                return Result.DRAW;
            }
        }
    }

    public void start() {
        this.deckRepository.createDeck();

        // Player's turn
        System.out.println("\n<< Your turn >>");
        this.drawCard(this.playerService);
        this.drawCard(this.playerService);

        // Dealer's turn
        System.out.println("\n<< Dealer's turn >>");
        this.drawCard(this.dealerService);
        this.drawHiddenCard(this.dealerService);

        // Player's turn
        System.out.println("\n<< Your turn >>");
        while (this.playerService.shouldDraw()) {
            this.drawCard(this.playerService);
        }

        // Dealer's turn
        System.out.println("\n<< Dealer's turn >>");
        while (this.dealerService.shouldDraw()) {
            this.drawCard(this.dealerService);
        }

        // Show result
        System.out.println("\n<< Result >>");
        this.playerService.showResult();
        this.dealerService.showResult();

        Result res = this.getPlayerResult();
        System.out.println("You " + res.toString().toLowerCase());
    }
}
