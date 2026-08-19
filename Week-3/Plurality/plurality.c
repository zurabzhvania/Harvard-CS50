#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    const char * name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX] = {0};

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char * name);
void print_winner(void);

int main(int argc, char * argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    char input[20];

    printf("Number of voters: ");
    fgets(input, sizeof(input), stdin);

    int voter_count = atoi(input);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[100];

        printf("Vote: ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0';
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char * name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void) {
    int maxvotes = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > maxvotes) {
            maxvotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == maxvotes) {
            printf("%s\n", candidates[i].name);
        }
    }
}
