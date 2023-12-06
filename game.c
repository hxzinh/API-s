#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

const int SIZE = 2;

bool word[26];

int main(int argc, char argv[]) {
    int level;
    puts("Choose your level: ");
    scanf("%d", &level);

    if(level < 5 || level > 8) {
        printf("Error: wordsize must be either 5, 6, 7, 8\n");
        return 1;
    }

    int wordsize = 0;
    wordsize = level;
    char filename[6];
    sprintf(filename, "%i.txt", wordsize);
    printf("%s\n", filename);
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file %s. \n", filename);
        return 1;
    }

    char options[SIZE][wordsize + 1];
    for(int i = 0; i < SIZE; i++) {
        fscanf(file, "%s", options[i]);
    }

    srand(time(NULL));
    char *ans = options[rand() % SIZE];
    
    int numGuesses = wordsize + 1;
    bool win = false;

    printf("You have %d guesses to guess my %d-letters word.\n", numGuesses, wordsize);

    char *guess = (char*)malloc(100 * sizeof(char));
    for(int i = 0; i < numGuesses; i++) {
        free(guess);
        guess = (char*)calloc(100, sizeof(char));
        while(strlen(guess) != wordsize) {
            printf("Input a %d-letter word: ", wordsize);
            scanf("%s", guess);
        }

        if(strcmp(guess, ans) == 0) {
            win = true;
            break;
        }
        else 
            puts("Try again!!\n");
    }

    if(win) puts("You win!!");
    else puts("You lose!!");

    return 0;
}
