import java.util.Scanner;

import application.service.UserService;
import application.usecase.PlayGame;
import domain.model.user.DealerStrategy;
import domain.model.user.PlayerStrategy;
import domain.repositories.DeckRepository;
import infrastructure.InMemoryDeckRepositoryImpl;

public class BlackJack {
    public static void main(String[] args) {
        System.out.println("Welcome to BlackJack!");
        Scanner scanner = new Scanner(System.in);

        PlayerStrategy playerStrategy = new PlayerStrategy(scanner);
        DealerStrategy dealerStrategy = new DealerStrategy();

        UserService playerService = new UserService(playerStrategy);
        UserService dealerService = new UserService(dealerStrategy);

        DeckRepository deckRepository = new InMemoryDeckRepositoryImpl();

        PlayGame playGame = new PlayGame(playerService, dealerService, deckRepository);
        playGame.start();

        scanner.close();
    }
}
