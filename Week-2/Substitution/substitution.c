#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_TEXT_LENGTH 1000
bool valid_key(const char *key);
void encrypt(const char *plaintext, const char *key);
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!valid_key(argv[1])) {
        return 1;
    }
    char plaintext[MAX_TEXT_LENGTH];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("ciphertext: ");
    encrypt(plaintext, argv[1]);
    printf("\n");
    return 0;
}
bool valid_key(const char *key) {
    if (strlen(key) != 26){
        printf("Key must contain 26 characters.\n");
        return false;
    }
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            printf("Key must contain only alphabetic characters.\n");
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (seen[index]) {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
        seen[index] = true;
    }
    return true;
}
void encrypt(const char *plaintext, const char *key){
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        char c = plaintext[i];
        if (isupper(c)) {
            int index = c - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(c)) {
            int index = c - 'a';
            printf("%c", tolower(key[index]));
        }
        else{
            printf("%c", c);
        }
    }
}
