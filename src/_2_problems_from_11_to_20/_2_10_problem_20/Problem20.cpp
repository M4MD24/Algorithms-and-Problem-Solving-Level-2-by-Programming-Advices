#include <iostream>
using namespace std;

short randomNumber(const short FROM, const short TO) { return rand() % (TO - FROM + 1) + FROM; }

enum CharacterType {
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialLetter = 3,
    Digit = 4
};

char randomCharacter(const CharacterType CHARACTER_TYPE) {
    switch (CHARACTER_TYPE) {
    case SmallLetter:
        return static_cast<char>(randomNumber('a', 'z'));
    case CapitalLetter:
        return static_cast<char>(randomNumber('A', 'Z'));
    case SpecialLetter:
        return static_cast<char>(randomNumber('!', '/'));
    case Digit:
        return static_cast<char>(randomNumber('0', '9'));
    default:
        return '\0';
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << randomCharacter(SmallLetter) << endl;
    cout << randomCharacter(CapitalLetter) << endl;
    cout << randomCharacter(SpecialLetter) << endl;
    cout << randomCharacter(Digit) << endl;
}