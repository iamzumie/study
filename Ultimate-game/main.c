#include <stdio.h>
#include <stdbool.h>
#include "parsexec.h"

// FUNCTIONS
static char input[100] = "look around";

static bool getInput() {
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;

}

void startUp();

int main() {
    startUp();

    while(parseAndExecute(input) && getInput());

    return 0;
}


// STARTUP
void startUp() {
    // TITLE SCREEN
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\tOPERATION WURFELD\n");
    printf("\n");
    printf("\t\t\t    A STEALTH-ADVENTURE GAME    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    //INTRO
    printf("The year is 1944, Nazi Germany invaded Belgium.\n\n");
    printf("You got thrown in a dark cell of a castle.\n\n");
    printf("Your mission: Find your way out Castle Wurfeld.\n\n"); 
}