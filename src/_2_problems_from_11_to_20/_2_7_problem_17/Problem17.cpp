#include <iostream>
using namespace std;

string readPassword() {
    string password;
    do {
        cout << "Enter password (three characters only):" << endl;
        cin >> password;
    } while (
        password.empty() || password.size() > 3 ||
        password[0] < 'A' || password[0] > 'Z' ||
        password[1] < 'A' || password[1] > 'Z' ||
        password[2] < 'A' || password[2] > 'Z'
    );
    return password;
}

void printTrailDetails(const short COUNTER, const string CURRENT_PASSWORD) { cout << "Trail [" << COUNTER << "]: " << CURRENT_PASSWORD << endl; }

short calculateTrailCountBetweenAAA_To_ZZZ(const string PASSWORD) {
    short counter = 1;
    for (char firstCharacter = 'A'; firstCharacter <= 'Z'; ++firstCharacter)
        for (char secondCharacter = 'A'; secondCharacter <= 'Z'; ++secondCharacter)
            for (char thirdCharacter = 'A'; thirdCharacter <= 'Z'; ++thirdCharacter, ++counter) {
                const string CURRENT_PASSWORD = {firstCharacter, secondCharacter, thirdCharacter};
                printTrailDetails(counter, CURRENT_PASSWORD);
                if (CURRENT_PASSWORD == PASSWORD)
                    return counter;
            }
    return counter;
}

int main() {
    const short TRAIL_COUNT = calculateTrailCountBetweenAAA_To_ZZZ(readPassword());
    cout << "Found at: " << TRAIL_COUNT;
}