package domain.model.game;

public enum Result {
    WIN("Win"),
    LOSE("Lose"),
    DRAW("Draw");

    private String result;

    Result(String result) {
        this.result = result;
    }

    public String getResult() {
        return this.result;
    }
}
