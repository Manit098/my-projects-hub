#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("\nCannot add more candidates. Limit reached!\n");
        return;
    }

    printf("\nEnter Candidate Name: ");
    getchar(); // Clear newline
    fgets(candidates[candidateCount].name, NAME_LENGTH, stdin);
    candidates[candidateCount].name[strcspn(candidates[candidateCount].name, "\n")] = 0; // Remove newline
    candidates[candidateCount].votes = 0;
    candidateCount++;

    printf("\nCandidate added successfully!\n");
}

void addVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("\nCannot add more voters. Limit reached!\n");
        return;
    }

    printf("\nEnter Voter Name: ");
    getchar(); // Clear newline
    fgets(voters[voterCount].name, NAME_LENGTH, stdin);
    voters[voterCount].name[strcspn(voters[voterCount].name, "\n")] = 0; // Remove newline
    voters[voterCount].hasVoted = 0;
    voterCount++;

    printf("\nVoter added successfully!\n");
}

void castVote() {
    char voterName[NAME_LENGTH];
    char candidateName[NAME_LENGTH];

    printf("\nEnter Voter Name: ");
    getchar(); // Clear newline
    fgets(voterName, NAME_LENGTH, stdin);
    voterName[strcspn(voterName, "\n")] = 0; // Remove newline

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("\nYou have already voted!\n");
                return;
            }

            printf("\nEnter Candidate Name: ");
            fgets(candidateName, NAME_LENGTH, stdin);
            candidateName[strcspn(candidateName, "\n")] = 0; // Remove newline

            for (int j = 0; j < candidateCount; j++) {
                if (strcmp(candidates[j].name, candidateName) == 0) {
                    candidates[j].votes++;
                    voters[i].hasVoted = 1;
                    printf("\nVote cast successfully!\n");
                    return;
                }
            }

            printf("\nCandidate not found!\n");
            return;
        }
    }

    printf("\nVoter not found!\n");
}

void viewResults() {
    if (candidateCount == 0) {
        printf("\nNo candidates available!\n");
        return;
    }

    printf("\nElection Results:\n");
    printf("%-30s %-10s\n", "Candidate Name", "Votes");
    printf("------------------------------------------\n");

    for (int i = 0; i < candidateCount; i++) {
        printf("%-30s %-10d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    do {
        printf("\nOnline Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. Cast Vote\n");
        printf("4. View Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                addVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                viewResults();
                break;
            case 5:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
