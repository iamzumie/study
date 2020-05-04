#include <stdio.h>
#include <string.h>
#include <ctype.h>

// FUNCTIONS
void command();
void startUp();
int input();
char * readLine();
char * fWord();
void action();
void function();
void showmap();

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
    printf("[1] look around\t [2] go north\t [3] go south\n\n");
    do {
        input(&answer);
        switch(answer) 
        {
            case 1: printf("It's pouring, maybe it's better if we go somewhere to hide.\n\n"); break;
            case 2: printf("You go towards the mansion.\nThere's a sign on the door that says: \"Begone humans! Leave the dead in peace!\"\n\n"); break;
            case 3: printf("It's too dark going south, it's freezing outside.\n\n"); break;
            default: printf("Answer %i is not an option.\n\n", answer); break;
        }
    } while (answer != 2);

    
    // SECOND QUESTION
    printf("[1] Go inside\t [2] Knock on the door\t [3] Kick a flower pot\n\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer) 
        {
            case 1: printf("It's locked. You need to find a key.\n\n"); break;
            case 2: printf("Nobody's home, it seems abandonded too.\n\n"); break;
            case 3: printf("You found the key under the flower pot!");
                    printf("\nYou open the door, it's very dark inside..\n\n");
                    break;
            default: printf("Answer %i is not an option.\n\n", answer); break;
        }
    } while (answer != 3);


    // THIRD QUESTION
    printf("We could use some light..\n");
    printf("\n[!] To use a lighter, type 'USE' and hit enter. Then type 'LIGHTER'.\n\n");
    getchar(); // REMOVES NEWLINE

    action("USE"); // LOOKS AT USE FIRST
    function("USE", "lighter");


    // FOURTH QUESTION
    printf("The room lightened up a little, all windows are boarded.\n");
    printf("What do you want to do next?\n\n");
    printf("[1] use toilet     [2] turn on some lights     [3] search for candles\n\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer) 
        {
            case 1: printf("Aaah that felt good!\n\n"); break;
            case 2: printf("Nothing happened.. I guess the power isn't working.\n\n"); break;
            case 3: printf("You found a candle, just in time. Your lighter was almost empty.\n"); break;
            default: printf("Answer %i is not an option.\n", answer); break;
        }
    } while (answer != 3);
            printf("While looking for candles you also found a map which seems to be like the floorplan.\n");
            
    // MAP     
    printf("\n[!] \"Use\" map where you want to go to:\n\n");
    getchar();
    action("USE"); // LOOKS AT USE FIRST
    function("USE", "map");
    showmap();

    printf("\nChoose where you want to go to:\n");
    printf("[1] KITCHEN     [2] DINING ROOM     [3] HAL     [4] LIVING ROOM     [5] UPSTAIRS\n\n");
    do
    {
        command();
        scanf("%i", &answer);
        switch(answer)
        {
            case 1: 
                printf("KITCHEN\n\n");
                break;
            case 2: 
                printf("DINING ROOM\n\n");
                break;
            case 3: 
                printf("HALL\n\n");
                break;
            case 4: 
                printf("LIVING ROOM\n\n");
                break;
            case 5:
                printf("We haven't discovered all locations below yet.\n\n");
                break;
            default: 
                printf("Answer %i is not an option.\n\n", answer); 
                break;
        }
    } while (answer < 1 || answer > 4);
        printf("Succes!\n");
    
}




// FUNCTIONS

// -->
void command() {
    printf(">  ");
}

// INPUT
int input(int *answer)
{
    command();
    scanf("%i", &*answer);

    return *answer;
}

// ACTION
void action(char * input) 
{
    while(1) {
        command();
        read = fWord();
        if ((strcasecmp(read, input) == 0)) 
        {
            printf("%s:  ", input);
            break;
        }
        else
            printf("I don't know the word %s.\n\n", read);
    }
}

// FUNCTION
void function(char * cmd, char * input) 
{
    while(1) 
    {
        read = fWord();
        if ((strcasecmp(read, input) == 0)) 
            break;
        else
            printf("I don't know the word %s.\n\n", read);
            printf("%s:  ", cmd);
    }
}

// READLINE
char * readLine() 
{
    char buffer[20];
    char * input = buffer;
    size_t size = 32;

    getline(&input, &size, stdin);
    input[strcspn(input, "\r\n")] = 0; // REMOVES NEWLINE FROM GETLINE
    
    return input;
}

// READ FIRST WORD
char * fWord() 
{
    char buffer[20];
    char * input = buffer;
    size_t size = 32;

    getline(&input, &size, stdin);
    input = strtok(input, " ");
    input[strcspn(input, "\r\n")] = 0; // REMOVES NEWLINE FROM GETLINE
    
    return input;
}

void showmap()
{
        puts(
        "\n\n"
        "   ______________________________________\n"
        "  /            |        | UP |           \\ \n"
        " |             | TOILET |----|            |\n"
        " |   KITCHEN   |___ ____|----|            |\n"
        " |                      |----|            |\n"
        " |______  _____|        |                 |\n"
        " |             |        |                 |\n"
        " |    DINING   |              LIVING      |\n"
        " |     ROOM             |      ROOM       |\n"
        " |             |  HALL  |                 |\n"
        " |_____________|________|_________________|\n"
        );
}

// TITLE SCREEN & INTRODUCTION
void startUp() 
{
    // TITLE SCREEN
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\tG H O S T   S T O R Y\n");
    printf("\n");
    printf("\t\tA   T E X T - A D V E N T U R E  G A M E    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    // INTRODUCTION
    printf("\nIt's a cold day, mid december and you find yourself wandering outside. In the distance you see a mansion.\n\n");
}