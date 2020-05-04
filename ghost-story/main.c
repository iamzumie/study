#include <stdio.h>
#include <string.h>
#include <ctype.h>

// FUNCTIONS
void command();
void startUp();
int input();
char * readline();
char * fWord();
void use();


// INIT
int answer;
char name[20];
char * read;
char * fword;

// MAIN GAME
int main() 
    {
    // TITLE SCREEN + INTRODUCTION
    startUp();

    // FIRST QUESTION
    printf("[1] look around\t [2] go north\t [3] go south\n");
    do {
        input(&answer);
        switch(answer) 
        {
            case 1: printf("\nIt's pouring, maybe it's better if we go somewhere to hide.\n\n"); break;
            case 2: printf("\nYou go towards the mansion and stand in front of the doors.\nThere's a sign on the door that says: \"Begone humans! Leave the dead in peace!\"\n\n"); break;
            case 3: printf("\nIt's too dark going south, it's freezing outside.\n\n"); break;
            default: printf("Answer %i is not an option.\n\n", answer); break;
        }
    } while (answer != 2);
    
    // SECOND QUESTION
    printf("What do you do?\n\n");
    printf("[1] Go inside\t [2] Knock on the door\t [3] Kick a flower pot\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer) 
        {
            case 1: printf("\nIt's locked. You need to find a key.\n\n"); break;
            case 2: printf("\nNobody's home, it seems abandonded too.\n\n"); break;
            case 3: printf("\nWhilst kicking the flower pot you noticed underneath it you found a key.");
                    printf("\nYou open the doors and go inside.\n\nIt's very dark inside.\n\n");
                    break;
            default: printf("Answer %i is not an option.\n\n", answer); break;
        }
    } while (answer != 3);

    // THIRD QUESTION
    getchar(); // REMOVES NEWLINE FROM BUFFER
    printf("We could use some light..\n");
    printf("\n[!] To use a lighter, type 'USE' and hit enter. Then type 'LIGHTER'.\n\n");

    // USE
    while(1) {
        command();
        read = fWord();

        if ((strcasecmp(read, "use") == 0)) 
            break;
        else
            printf("I don't know the word %s.\n\n", read);
    }
    
    // LIGHTER
    while(1) {
        use();
        read = fWord();
        
        if ((strcasecmp(read, "lighter") == 0)) 
            break;
        else
            printf("I don't know the word %s.\n\n", read);
    }

    // FOURTH QUESTION
    printf("\nThe room lightened up.\nWow seems like nobody has been here in years!\n");
    printf("\nWhat's that?! You hear a sound coming out of the corridor closet.\n");
}

// -->
void command() {
    printf(">  ");
}

// USE
void use() {
    printf("USE:  ");
}

// INPUT
int input(int *answer)
{
    command();
    scanf("%i", &*answer);

    return *answer;
}

// READLINE
char * readline() 
{
    char buffer[20];
    char * input = buffer;
    int size = 32;

    fgets(input, size, stdin);
    input[strcspn(input, "\r\n")] = 0; // REMOVES NEWLINE FROM GETLINE
    
    return input;
}

// READ FIRST WORD
char * fWord() 
{
    char buffer[20];
    char * input = buffer;
    int size = 32;

    fgets(input, size, stdin);
    input = strtok(input, " ");
    input[strcspn(input, "\r\n")] = 0; // REMOVES NEWLINE FROM GETLINE
    
    return input;
}

// TITLE SCREEN & INTRODUCTION
void startUp() 
{
    // TITLE SCREEN
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\tGHOST STORY v0.1\n");
    printf("\n");
    printf("\t\t\t    A TEXT-ADVENTURE GAME    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    // INTRODUCTION
    printf("\nIt's a cold day, mid december and you find yourself wandering outside.\n\nIn the distance you see a mansion.\n\n");
}