#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printHangman(int lives);
void printTitle(char a[]);
char toCaps(char c);
int isLetter(char c);
int isIn(char str[], char c);
void printLetters(char str[]);
int countlines(char *filename);

int hangman() {
    char keepPlaying = 'Y', letter;
    int lives, win;

    char correctWord[200];
    char currentWord[200];
    char incorrectLetters[27];
    int it;

    FILE *words;
    int line;

    while (keepPlaying == 'Y' || keepPlaying == 'y') {
        lives = 6;
        win = 0;
        it = 0;

        words = fopen("words.txt", "r");
        if (words == NULL) {
            printf("Error: words.txt not found");
            return 1;
        }

        line = rand() % countlines("words.txt");

        for (int i = 0; i <= line; i++)
            fgets(correctWord, sizeof(correctWord), words);

        fclose(words);

        /*Pass correct word to caps*/
        for (int i = 0; i < strlen(correctWord); i++)
            correctWord[i] = toCaps(correctWord[i]);

        /*Prepare current word*/
        strcpy(currentWord, correctWord);
        for (int i = 0; currentWord[i] != '\0'; i++)
            currentWord[i] = '_';
        incorrectLetters[0] = '\0';

        /*Game*/
        while (lives > 0 && !win) {
            printf("\t\t HANGMAN");
            printf("\n\nWord: %s\n", currentWord);
            printHangman(lives);
            printf("\nIncorrect letters: ");
            if (strlen(incorrectLetters) != 0)
                printLetters(incorrectLetters);
            else
                printf("none.");
            do {
                printf("\nEnter a letter: ");
                scanf(" %c", &letter); // Note the space before %c to consume newline characters
            } while (!isLetter(letter));

            if (letter >= 97)
                letter = toCaps(letter);

            printf("\n");
            if (isIn(correctWord, letter)) {
                if (!isIn(currentWord, letter)) {
                    for (int i = 0; correctWord[i] != '\0'; i++)
                        if (correctWord[i] == letter)
                            currentWord[i] = letter;
                } else {
                    printf("Letter %c is already in your current word.", letter);
                    lives--;
                }
            } else {
                printf("Letter %c isn't in the correct word.", letter);
                if (!isIn(incorrectLetters, letter)) {
                    incorrectLetters[it] = letter;
                    incorrectLetters[it + 1] = '\0';
                    it++;
                } else
                    printf("\nAlso, you had tried this letter earlier.");
                lives--;
            }

            if (strcmp(currentWord, correctWord) == 0)
                win = 1;
            if (lives == 0)
                win = 0;
            system("@cls||clear");
        }
        system("cls");
        if (win)
            printf("\n\tYou have won :D");
        else {
            printf("You Lost");
            printf("\n\nThe correct word was %s.\n", correctWord);
        }

        do {
            printf("\nDo you want to keep playing? [Y/N]: ");
            scanf(" %c", &keepPlaying); // Note the space before %c to consume newline characters
        } while (keepPlaying != 'y' && keepPlaying != 'Y' && keepPlaying != 'n' && keepPlaying != 'N');
        system("@cls||clear");
    }
    return 0;
}

void printHangman(int lives) {
    switch (lives) {
    case 6:
        printf("%c%c%c%c%c\n", 201, 205, 205, 205, 187);
        printf("%c\n", 186);
        printf("%c\n", 186);
        printf("%c\n", 186);
        printf("%c\n", 186);
        printf("%c\n", 202);
        break;

    case 5:
        printf("%c%c%c%c%c\n", 201, 205, 205, 205, 187);
        printf("%c   O\n", 186);
        printf("%c\n", 186);
        printf("%c\n", 186);
        printf("%c\n", 186);
        printf("%c\n", 202);
        break;

    case 4:
        printf("%c%c%c%c%c\n", 201, 205, 205, 205, 187);
        printf("%c   O\n", 186);
        printf("%c   %c\n", 186, 179);
        printf("%c   %c\n", 186, 179);
        printf("%c\n", 186);
        printf("%c\n", 202);
        break;

    case 3:
        printf("%c%c%c%c%c\n", 201, 205, 205, 205, 187);
        printf("%c   O\n", 186);
        printf("%c %c%c%c\n", 186, 196, 196, 18);
}
}
