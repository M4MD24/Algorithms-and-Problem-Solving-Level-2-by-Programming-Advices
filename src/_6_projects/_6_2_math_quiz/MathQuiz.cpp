#include <iostream>
#include <limits>
using namespace std;

enum DifficultyLevel {
    Easy = 1,
    Medium = 2,
    Hard = 3,
    MixDifficultyLevel = 4
};

enum OperationType {
    Add = '+',
    Subtract = '-',
    Multiply = '*',
    Divisor = '/',
    MixOperationType = '?'
};

struct Question {
    DifficultyLevel difficultyLevel;
    double firstNumber;
    OperationType operationType;
    double secondNumber;
    double correctAnswer;
};

struct Stats {
    long long numberOfQuestions;
    DifficultyLevel difficultyLevel;
    OperationType operationType;
    long long numberOfRightAnswers;
    long long numberOfWrongAnswers;
};

short randomNumber(
    const short FROM,
    const short TO
) { return rand() % (TO - FROM + 1) + FROM; }

bool anotherQuiz() {
    string anotherQuiz;
    do {
        cout << "Do you want another quiz? (yes/no)" << endl;
        cin >> anotherQuiz;
    } while (anotherQuiz != "yes" && anotherQuiz != "no");
    return anotherQuiz == "yes";
}

void printCurrentQuestion(
    const long long INDEX
) { cout << "Question [" << INDEX << "]" << endl; }

long long readPositiveNumber(
    const string& INPUT_MESSAGE
) {
    long long number;
    do {
        cout << INPUT_MESSAGE << endl;
        cin >> number;
    } while (number < 1);
    return number;
}

DifficultyLevel chooseDifficultyLevel(
    const short DIFFICULTY_LEVEL_CHOICE_NUMBER
) {
    switch (DIFFICULTY_LEVEL_CHOICE_NUMBER) {
    case 1:
        return Easy;
    case 2:
        return Medium;
    case 3:
        return Hard;
    default:
        return MixDifficultyLevel;
    }
}

void printDifficultyLevelChoicesList() {
    cout << "Choose difficulty level from list:" << endl;
    cout << "[1]: Easy" << endl;
    cout << "[2]: Medium" << endl;
    cout << "[3]: Hard" << endl;
    cout << "[4]: Mix" << endl;
    cout << "What would you choose?" << endl;
}

short readDifficultyLevelChoiceNumber() {
    short number;
    do {
        printDifficultyLevelChoicesList();
        cin >> number;
    } while (number < 1 || number > 4);
    return number;
}

OperationType chooseOperationType(
    const short OPERATION_TYPE_CHOICE_NUMBER
) {
    switch (OPERATION_TYPE_CHOICE_NUMBER) {
    case 1:
        return Add;
    case 2:
        return Subtract;
    case 3:
        return Multiply;
    case 4:
        return Divisor;
    default:
        return MixOperationType;
    }
}

void printOperationTypeChoicesList() {
    cout << "Choose operation type from list:" << endl;
    cout << "[1]: Add (+)" << endl;
    cout << "[2]: Subtract (-)" << endl;
    cout << "[3]: Multiply (*)" << endl;
    cout << "[4]: Divisor (/)" << endl;
    cout << "[5]: Mix (?)" << endl;
    cout << "What would you choose?" << endl;
}

short readOperationTypeChoiceNumber() {
    short number;
    do {
        printOperationTypeChoicesList();
        cin >> number;
    } while (number < 1 || number > 5);
    return number;
}

OperationType getRandomOperation() {
    char operationTypes[] = {
        Add,
        Subtract,
        Multiply,
        Divisor
    };
    return static_cast<OperationType>(operationTypes[randomNumber(
        0,
        3
    )]);
}

DifficultyLevel getRandomDifficultyLevel() {
    return static_cast<DifficultyLevel>(randomNumber(
        1,
        3
    ));
}

double getCorrectResult(
    const Question& QUESTION
) {
    switch (QUESTION.operationType) {
    case Add:
        return QUESTION.firstNumber + QUESTION.secondNumber;
    case Subtract:
        return QUESTION.firstNumber - QUESTION.secondNumber;
    case Multiply:
        return QUESTION.firstNumber * QUESTION.secondNumber;
    default:
        return QUESTION.firstNumber / QUESTION.secondNumber;
    }
}

string getDifficultyLevel(
    const DifficultyLevel DIFFICULTY_LEVEL
) {
    switch (DIFFICULTY_LEVEL) {
    case Easy:
        return "Easy";
    case Medium:
        return "Medium";
    case Hard:
        return "Hard";
    default:
        return "Mix";
    }
}

void printQuestion(
    const long long NUMBER_OF_QUESTIONS,
    const int INDEX,
    const DifficultyLevel DIFFICULTY_LEVEL,
    const Question& QUESTION
) {
    cout << "Question Number [" << INDEX << "/" << NUMBER_OF_QUESTIONS << "] " << getDifficultyLevel(
        DIFFICULTY_LEVEL
    ) << endl;
    cout << QUESTION.firstNumber << endl;
    cout << static_cast<char>(QUESTION.operationType) << endl;
    cout << QUESTION.secondNumber << endl;
    cout << "--------------------" << endl;
}

double randomNumberByDifficulty(
    const DifficultyLevel DIFFICULTY_LEVEL
) {
    switch (DIFFICULTY_LEVEL) {
    case Easy:
        return randomNumber(
            0,
            12
        );
    case Medium:
        return randomNumber(
            -12,
            12
        );
    default:
        return randomNumber(
            -100,
            100
        );;
    }
}

void generateQuestion(
    const Stats& STATS,
    const bool IS_MIX_DIFFICULTY_LEVEL,
    const bool IS_MIX_OPERATION_TYPE,
    Question& question
) {
    if (IS_MIX_DIFFICULTY_LEVEL)
        question.difficultyLevel = getRandomDifficultyLevel();
    else
        question.difficultyLevel = STATS.difficultyLevel;

    question.firstNumber = randomNumberByDifficulty(
        question.difficultyLevel
    );

    if (IS_MIX_OPERATION_TYPE)
        question.operationType = getRandomOperation();
    else
        question.operationType = STATS.operationType;

    question.secondNumber = randomNumber(
        0,
        12
    );

    question.correctAnswer = getCorrectResult(
        question
    );
}

double readNumber() {
    double number;
    bool valid;
    do {
        cin >> number;
        valid = !cin.fail();
        if (!valid) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    } while (!valid);
    return number;
}

void answerQuestion(
    Stats& stats,
    const double CORRECT_ANSWER
) {
    if (const double ANSWER = readNumber(); ANSWER == CORRECT_ANSWER) {
        cout << "Correct Answer";
        stats.numberOfRightAnswers++;
    } else {
        cout << "Wrong Answer, Correct Answer is " << CORRECT_ANSWER;
        stats.numberOfWrongAnswers++;
    }
    cout << endl << endl;
}

void askQuestions(
    Stats& stats
) {
    const bool IS_MIX_DIFFICULTY_LEVEL = stats.difficultyLevel == MixDifficultyLevel,
               IS_MIX_OPERATION_TYPE = stats.operationType == MixOperationType;

    for (long long index = 1; index <= stats.numberOfQuestions; ++index) {
        Question question{};

        generateQuestion(
            stats,
            IS_MIX_DIFFICULTY_LEVEL,
            IS_MIX_OPERATION_TYPE,
            question
        );

        printQuestion(
            stats.numberOfQuestions,
            index,
            question.difficultyLevel,
            question
        );

        answerQuestion(
            stats,
            question.correctAnswer
        );
    }
}

string getOperationType(
    const Stats& STATS
) {
    switch (STATS.operationType) {
    case Add:
        return "Add";
    case Subtract:
        return "Subtract";
    case Multiply:
        return "Multiply";
    case Divisor:
        return "Divisor";
    default:
        return "Mix";
    }
}

void printQuizStats(
    const Stats& stats
) {
    cout << "Number of Questions: " << stats.numberOfQuestions << endl;
    cout << "Difficulty Level: " << getDifficultyLevel(
        stats.difficultyLevel
    ) << endl;
    cout << "Operation Type: " << getOperationType(
        stats
    ) << endl;
    cout << "Number of Right Answers: " << stats.numberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " << stats.numberOfWrongAnswers << endl << endl;
}

void startGame() {
    do {
        Stats stats{};

        stats.numberOfQuestions = readPositiveNumber(
            "How many questions?"
        );

        stats.difficultyLevel = chooseDifficultyLevel(
            readDifficultyLevelChoiceNumber()
        );

        stats.operationType = chooseOperationType(
            readOperationTypeChoiceNumber()
        );

        askQuestions(
            stats
        );

        printQuizStats(
            stats
        );
    } while (anotherQuiz());
}

int main() {
    srand(
        static_cast<unsigned>(time(
            nullptr
        ))
    );
    startGame();
}