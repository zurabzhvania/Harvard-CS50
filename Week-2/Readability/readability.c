#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int lettercounter(char* text);
int wordcounter(char* text);
int sentencecounter(char* text);
int calculateindex(int letters, int words, int sentences);
void printresult(int gradelevel);
int main(void)
{
    char wholetext[1000];
    printf("Text: ");
    fgets(wholetext, sizeof(wholetext), stdin);
    wholetext[strcspn(wholetext, "\n")] = '\0';
    int letters = lettercounter(wholetext);
    int words = wordcounter(wholetext);
    int sentences = sentencecounter(wholetext);
    int gradelevel = calculateindex(letters, words, sentences);
    printresult(gradelevel);
    return 0;
}
int lettercounter(char* text) {
    int letters = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }
    return letters;
}
int wordcounter(char* text) {
   int spaces = 0;
   int length = strlen(text);
   for (int i = 0; i < length; i++) {
       if (isspace(text[i])) {
        spaces++;
       }
   }
   int words = spaces + 1;
   return words;
}
int sentencecounter(char* text) {
    int sentences = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    return sentences;
}
int calculateindex(int letters, int words, int sentences) {
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}
void printresult(int gradelevel) {
    if (gradelevel < 1) {
        printf("Before Grade 1");
    }
    else if (gradelevel >= 16) {
        printf("Grade 16+");
    }
    else {
        printf("Grade %i\n", gradelevel);
    }
}
