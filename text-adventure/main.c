#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char input[100];

// Quiting the game
bool playing(char *input) {
    char *quit = "quit";
    strcmp(input, quit) == 0 ? false : true;
}

int main() 
{
    // TITLE SCREEN
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\tOPERATION WURFELD\n");
    printf("\n");
    printf("\t\t\t    A STEALTH-ADVENTURE GAME    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    // INTRODUCTION
    printf("Belgium 1914, close to the german border..\n\n");
    printf("An airstrike nearby wakes you up in your tent.\n");

    // First interaction
    while(playing(input)) {
        printf("You: ");
        scanf("%s", &input);
    }
    
    // END MESSAGE
    printf("\n\nLike you got something better to do!\n");

    return 0;
}