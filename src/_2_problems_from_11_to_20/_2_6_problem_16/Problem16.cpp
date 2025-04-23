#include <iostream>
using namespace std;

void printAllPermutationsFromAAA_To_ZZZ() {
    for (char firstCharacter = 'A'; firstCharacter <= 'Z'; ++firstCharacter)
        for (char secondCharacter = 'A'; secondCharacter <= 'Z'; ++secondCharacter)
            for (char thirdCharacter = 'A'; thirdCharacter <= 'Z'; ++thirdCharacter)
                cout << firstCharacter << secondCharacter << thirdCharacter << endl;
}

int main() { printAllPermutationsFromAAA_To_ZZZ(); }