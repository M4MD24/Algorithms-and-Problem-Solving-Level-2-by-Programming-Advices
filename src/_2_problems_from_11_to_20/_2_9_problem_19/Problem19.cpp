#include <iostream>
using namespace std;

short randomNumber(const short FROM, const short TO) { return rand() % (TO - FROM + 1) + FROM; }

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10);
}