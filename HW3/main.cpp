#include <iostream>
#include <string>
#include <cstring>

char* encrypt(char* rawText, int key) {
    int length = strlen(rawText);
    char* encryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        if (isalpha(rawText[i])) {
            char shift = islower(rawText[i]) ? 'a' : 'A';
            encryptedText[i] = ((rawText[i] - shift + key) % 26 + 26) % 26 + shift; 
        }
        else {
            
            encryptedText[i] = rawText[i];
        }
    }

    encryptedText[length] = '\0'; 
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    int length = strlen(encryptedText);
    char* decryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        if (isalpha(encryptedText[i])) {
            char shift = islower(encryptedText[i]) ? 'a' : 'A';
            decryptedText[i] = ((encryptedText[i] - shift - key + 26) % 26 + 26) % 26 + shift;
        }
        else {

            decryptedText[i] = encryptedText[i];
        }
    }

    decryptedText[length] = '\0';
    return decryptedText;
}

int main() {

    std::string inputText;
    std::cout << "Enter text to encrypt: ";
    std::getline(std::cin, inputText);

    int key;
    std::cout << "Enter encryption key: ";
    std::cin >> key;


    char* cstr = new char[inputText.length() + 1];
    strcpy_s(cstr, inputText.length() + 1, inputText.c_str());


    char* encryptedText = encrypt(cstr, key);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;


    char* decryptedText = decrypt(encryptedText, key);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;


    delete[] cstr;
    delete[] encryptedText;
    delete[] decryptedText;

    return 0;
}

