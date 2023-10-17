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


