import java.util.*;
import java.util.concurrent.atomic.AtomicReference;

public class FourthZ {
    public static void main(String[] args) {
        AtomicReference<Random> gen = new AtomicReference<>(new Random());
        int gameRounds = 10;//gen.get().nextInt(100) + 100;

        boolean[] selfChoices = new boolean[gameRounds];
        boolean[] enemyChoices = new boolean[gameRounds];

        Strategy[] strategies = {new AlwaysCooperate(), new AlwaysBetray(), new TitForTat(), new Pavlov(), new RandomChange(), new Unforgiving()};

        int c = 0;
        for (Strategy strategy : strategies) {
            int selfScore = 0, enemyScore = 0;

            System.out.println("Стратегия игрока: " + strategy.getName());

            int enemyStrategyIndex = gen.get().nextInt(strategies.length); // случайный выбор стратегии противника
            Strategy enemyStrategy = strategies[enemyStrategyIndex];
            System.out.println("Стратегия противника: " + enemyStrategy.getName());

            for (int round = 0; round < gameRounds; ++round) {
                boolean selfAction = strategy.makeChoice(round, selfChoices, enemyChoices);
                boolean enemyAction = enemyStrategy.makeChoice(round, enemyChoices, selfChoices);

                selfChoices[round] = selfAction;
                enemyChoices[round] = enemyAction;

                System.out.println("Раунд " + (round + 1) + ":\t\t" + (selfAction ? "+" : "-") + "\t" + (enemyAction ? "+" : "-"));

                if (selfAction && enemyAction) {
                    selfScore += 24;
                    enemyScore += 24;
                } else if (!selfAction && !enemyAction) {
                    selfScore += 4;
                    enemyScore += 4;
                } else if (selfAction && !enemyAction) {
                    selfScore += 0;
                    enemyScore += 20;
                } else {
                    selfScore += 0;
                    enemyScore += 20;
                }
            }

            System.out.println("Очки игрока: " + selfScore);
            System.out.println("Очки противника: " + enemyScore);
            System.out.println();
            if (c < 2){
                c++;
            }
            else {
                break;
            }
        }
    }
}

interface Strategy {
    boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices);
    String getName();
}

class AlwaysCooperate implements Strategy {
    public boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices) {
        return true;
    }
    public String getName() {
        return "Всегда сотрудничать";
    }
}

class AlwaysBetray implements Strategy {
    public boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices) {
        return false;
    }
    public String getName() {
        return "Всегда изменять";
    }
}

class TitForTat implements Strategy {
    public boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices) {
        if (roundNumber == 0) {
            return true;
        }
        return enemyChoices[roundNumber - 1];
    }
    public String getName() {
        return "TIT-FOR-TAT";
    }
}

class Pavlov implements Strategy {
    public boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices) {
        if (roundNumber == 0) {
            return true;
        }
        int selfTotalScore = 0, enemyTotalScore = 0;

        // Calculate total scores from all previous rounds
        for (int i = 0; i < roundNumber; i++) {
            if (selfChoices[i] && enemyChoices[i]) {
                selfTotalScore += 24;
                enemyTotalScore += 24;
            } else if (!selfChoices[i] && !enemyChoices[i]) {
                selfTotalScore += 4;
                enemyTotalScore += 4;
            } else if (selfChoices[i] && !enemyChoices[i]) {
                selfTotalScore += 0;
                enemyTotalScore += 20;
            } else {
                selfTotalScore += 20;
                enemyTotalScore += 0;
            }
        }

        // Update strategy based on cumulative scores
        if (selfTotalScore == enemyTotalScore) {
            return selfChoices[roundNumber - 1];
        } else {
            return selfTotalScore > enemyTotalScore;
        }
    }

    public String getName() {
        return "PAVLOV";
    }
}

class RandomChange implements Strategy {
    Random gen = new Random();
    public boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices) {
        return gen.nextBoolean();
    }
    public String getName() {
        return "RANDOM";
    }
}

class Unforgiving implements Strategy {
    boolean cooperate = true;
    int betrayalCount = 0;
    public boolean makeChoice(int roundNumber, boolean[] selfChoices, boolean[] enemyChoices) {
        if (roundNumber == 0) {
            betrayalCount = 0;
            return true;
        }
        if (selfChoices[roundNumber - 1] && !enemyChoices[roundNumber - 1]) {
            betrayalCount++;
        }
        if (betrayalCount >= 1) {
            cooperate = false;
        }
        return cooperate;
    }
    public String getName() {
        return "Стратегия непрощения";
    }
}