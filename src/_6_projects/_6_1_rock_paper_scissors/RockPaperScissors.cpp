#include <iostream>
using namespace std;

enum Choice {
    Invalid = 0,
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum Player {
    Nothing = 0,
    Computer = 1,
    RealPlayer = 2
};

struct Stats {
    long numberOfRealPlayerWins;
    long numberOfComputerWins;
    long numberOfDraws;
    string finalWinner;
};

short readPositiveNumber(const string& INPUT_MESSAGE) {
    short number;
    do {
        cout << INPUT_MESSAGE << endl;
        cin >> number;
    } while (number < 1);
    return number;
}

void printCurrentRound(const long INDEX) { cout << "Round [" << INDEX << "]" << endl; }

void printChoicesList() {
    cout << "Choose from list:" << endl;
    cout << "[1]: Rock" << endl;
    cout << "[2]: Paper" << endl;
    cout << "[3]: Scissors" << endl;
    cout << "What would you choose?" << endl;
}

short randomNumber(
    const short FROM,
    const short TO
) { return rand() % (TO - FROM + 1) + FROM; }

short readChoiceNumber() {
    short number;
    do {
        printChoicesList();
        cin >> number;
    } while (number < 1 || number > 3);
    return number;
}

Choice checkChoice(const short CHOICE_NUMBER) {
    switch (CHOICE_NUMBER) {
    case 1:

        return Rock;
    case 2:
        return Paper;
    case 3:
        return Scissors;
    default:
        return Invalid;
    }
}

string readChoice(const Choice CHOICE) {
    switch (CHOICE) {
    case 1:
        return "Rock";
    case 2:
        return "Paper";
    case 3:
        return "Scissors";
    default:
        return "Invalid";
    }
}

Player findOutWhoRoundWon(
    const Choice REAL_PLAYER_CHOICE,
    const Choice COMPUTER_CHOICE
) {
    if (
        (REAL_PLAYER_CHOICE == Rock && COMPUTER_CHOICE == Scissors) ||
        (REAL_PLAYER_CHOICE == Paper && COMPUTER_CHOICE == Rock) ||
        (REAL_PLAYER_CHOICE == Scissors && COMPUTER_CHOICE == Paper)
    )
        return RealPlayer;
    if (
        (REAL_PLAYER_CHOICE == Rock && COMPUTER_CHOICE == Paper) ||
        (REAL_PLAYER_CHOICE == Paper && COMPUTER_CHOICE == Scissors) ||
        (REAL_PLAYER_CHOICE == Scissors && COMPUTER_CHOICE == Rock)
    )
        return Computer;
    return Nothing;
}

void incrementWinnerPoints(
    const Player ROUND_WINNER,
    Stats& stats
) {
    switch (ROUND_WINNER) {
    case Computer:
        stats.numberOfComputerWins++;
        break;
    case RealPlayer:
        stats.numberOfRealPlayerWins++;
        break;
    default:
        stats.numberOfDraws++;
    }
}

string readPlayer(const Player PLAYER) {
    switch (PLAYER) {
    case Computer:
        return "Computer";
    case RealPlayer:
        return "You";
    default:
        return "No Winner";
    }
}

void printRoundStats(
    const Choice REAL_PLAYER_CHOICE,
    const Choice COMPUTER_CHOICE,
    Stats& stats
) {
    const string REAL_PLAYER_CHOICE_AS_STRING = readChoice(REAL_PLAYER_CHOICE);
    const string COMPUTER_CHOICE_CHOICE_AS_STRING = readChoice(COMPUTER_CHOICE);
    const Player ROUND_WINNER = findOutWhoRoundWon(
        REAL_PLAYER_CHOICE,
        COMPUTER_CHOICE
    );

    incrementWinnerPoints(
        ROUND_WINNER,
        stats
    );

    cout << "You Choice: " << REAL_PLAYER_CHOICE_AS_STRING << endl;
    cout << "Computer Choice: " << COMPUTER_CHOICE_CHOICE_AS_STRING << endl;
    cout << "Round Winner: " << readPlayer(ROUND_WINNER) << endl << endl;
}

void playRound(Stats& stats) {
    const Choice REAL_PLAYER_CHOICE = checkChoice(
        readChoiceNumber()
    );
    const Choice COMPUTER_CHOICE = checkChoice(
        randomNumber(
            1,
            3
        )
    );
    printRoundStats(
        REAL_PLAYER_CHOICE,
        COMPUTER_CHOICE,
        stats
    );
}

void playRounds(
    const long ROUNDS,
    Stats& stats
) {
    for (long index = 1; index <= ROUNDS; ++index) {
        printCurrentRound(index);
        playRound(stats);
    }
}

Player findOutWhoFinalWon(const Stats& STATS) {
    if (
        STATS.numberOfDraws >= STATS.numberOfComputerWins &&
        STATS.numberOfDraws >= STATS.numberOfRealPlayerWins
    )
        return Nothing;
    if (
        STATS.numberOfComputerWins >= STATS.numberOfDraws &&
        STATS.numberOfComputerWins >= STATS.numberOfRealPlayerWins
    )
        return Computer;
    return RealPlayer;
}

void printRoundsStats(
    const long ROUNDS,
    const Stats& STATS
) {
    cout << "Game Over" << endl;
    cout << "--------------------" << endl;
    cout << "Count of Rounds: " << ROUNDS << endl;
    cout << "Number of Draws: " << STATS.numberOfDraws << endl;
    cout << "Number of Computer Wins: " << STATS.numberOfComputerWins << endl;
    cout << "Number of Computer Real Player Wins: " << STATS.numberOfRealPlayerWins << endl;
    cout << "Final Winner: " << STATS.finalWinner << endl << endl;
}

bool playAgain() {
    string playGame;
    do {
        cout << "Do you want play again? (yes/no)" << endl;
        cin >> playGame;
    } while (playGame != "yes" && playGame != "no");
    return playGame == "yes";
}

void startGame() {
    do {
        const long ROUNDS = readPositiveNumber("How many rounds?");

        Stats stats = {};

        playRounds(
            ROUNDS,
            stats
        );

        const Player FINAL_WINNER = findOutWhoFinalWon(stats);
        stats.finalWinner = readPlayer(FINAL_WINNER);

        printRoundsStats(
            ROUNDS,
            stats
        );
    } while (playAgain());
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    startGame();

    return 0;
}