#include <iostream>
using namespace std;

string readText() {
    cout << "Enter text:" << endl;
    string text;
    getline(
        cin,
        text
    );
    return text;
}

string encryptText(string text, const short ENCRYPTION_KEY) {
    for (int index = 0; index < text.length(); ++index)
        text[index] = static_cast<char>(static_cast<int>(text[index]) + ENCRYPTION_KEY);
    return text;
}

string decryptText(string text, const short ENCRYPTION_KEY) {
    for (int index = 0; index < text.length(); ++index)
        text[index] = static_cast<char>(static_cast<int>(text[index]) - ENCRYPTION_KEY);
    return text;
}

int main() {
    const short ENCRYPTION_KEY = 2;

    const string TEXT = readText();

    const string TEXT_AFTER_ENCRYPTION = encryptText(
        TEXT,
        ENCRYPTION_KEY
    );
    const string TEXT_AFTER_DECRYPTION = decryptText(
        TEXT_AFTER_ENCRYPTION,
        ENCRYPTION_KEY
    );

    cout << "Original Text: " << TEXT << endl;
    cout << "Text After Encryption: " << TEXT_AFTER_ENCRYPTION << endl;
    cout << "Text Before Decryption: " << TEXT_AFTER_DECRYPTION;
}