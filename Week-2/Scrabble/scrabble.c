#include <ctype.h>
#include <stdio.h>
#include <string.h>
static const int SCORES[26] = {
    1, 3, 3, 2, 1, 4, 2, 4,
    1, 8, 5, 1, 3, 1, 1, 3,
    10, 1, 1, 1, 1, 4, 4, 8,
    4, 10
};
int compute_score(const char *word);
int main(void)
{
    char player1[100];
    char player2[100];
    printf("Player 1: ");
    fgets(player1, sizeof(player1), stdin);
    printf("Player 2: ");
    fgets(player2, sizeof(player2), stdin);
    player1[strcspn(player1, "\n")] = '\0';
    player2[strcspn(player2, "\n")] = '\0';
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1) {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Tie!\n");
    }
    return 0;
}
int compute_score(const char *word)
{
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            score += SCORES[toupper(word[i]) - 'A'];
        }
    }
    return score;
}
