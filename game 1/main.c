#include <stdio.h>
#include <stdbool.h>

// FUNCTIONS
void command();

// INIT
int answer;

// MAIN GAME
int main() {

    // INTRO
    printf("\n\nYou are in a field.\n\n");
    printf("What is your next move?\n");
    printf("[1] look around\t [2] go north\t [3] go south\n");

    // 1st QUESTION
    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("In front of you is a castle.\n\n"); break;
            case 1: printf("You go towards the castle and stand in front of the doors.\n\n"); break;
            case 2: printf("It's too dark going south.\n\n"); break;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 2);
    
    // 2nd QUESTION
    printf("What do you do?\n\n");
    printf("[1] Go inside\t [2] Knock on the door\t [3] Kick a flower pot\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("It's locked.\n\n"); break;
            case 1: printf("Nobody's home, it seems abandonded too.\n\n"); break;
            case 2: printf("Whilst kicking the flower pot you noticed underneath you found a key.\nYou open the doors and go inside.\n\nIt's very dark inside.\n"); break;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 3);
    
    // 3th QUESTION
    printf("[1] Search around\t [2] Grab your lighter\t [3] Go north\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("You found a lightswitch that works.\nIt seems like nobody's been here in years.\n\n"); break;
            case 1: printf("You obviously don't have a lighter, who smokes in 2020 anyway?\n\n"); break;
            case 2: printf("You wander around in the darkness.\n"); break;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 1);

    // 4th QUESTION
    printf("Where do you want to go?\n\n");
    printf("[1] Kitchen\t [2] Living room\t [3] Look around the corridor.\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("Good thinking, who takes on an adventure while they have an empty stomach?\nToo bad the fridge is empty..\n\n You return to the corridor.\n"); break;
            case 1: printf("The living room is filled with antique furniture, above the fireplace you noticed a shotgun.\n The hear the rattling sound from upstairs again.\n\n"); break;
            case 2: printf("Nothing to see here..\n"); break;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 2);

    // 5th QUESTION
    printf("What is your next move?\n\n");
    printf("[1] Equip shotgun\t [2] Take a nap on the couch\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("You only found some salt bullets. Why would we need salt bullets? Hmm.. Strange indeed.\n\n"); break;
            case 1: printf("\nYou fell asleep and got killed.\n\nGAME OVER\n\nThanks for playing!\n"); return 0;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 1);


    // 6th QUESTION
    printf("Where do you want to go next?\n\n");
    printf("[1] Upstairs\t [2] Quit this game because you are afraid..\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("\nUpstairs you find a treasure chest, while trying to open it a Ghost shows up! BOOOOOOEEE\n\n"); break;
            case 1: printf("\nRight, you almost shit you pants huh?\n\nGAME OVER\n\nThanks for playing!\n"); return 0;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 1);


    // ENDGAME
    printf("What do you do?\n\n");
    printf("[1] TALK\t [2] RUN [3] FIGHT\t\n");

    do {
        command();
        scanf("%i", &answer);
        switch(answer - 1) 
        {
            case 0: printf("Seriously talk? Try again mate, this is a serious dangerous ghost.\n\n"); break;
            case 1: printf("\nRight, you almost shit you pants huh?\n\nGAME OVER\n\nThanks for playing!\n"); return 0;
            case 2: 
                printf("You pump the ghost with rust bullets and the Ghost dissapears.\n\n*****VICTORY*****\n\n"); 
                printf("Thanks for playing!\n");
                return 0;
            default: printf("Answer %d is not an option.\n\n", answer); break;
    }
    } while (answer != 2);
        return 0;
}

// -->
void command() {
    printf("-->  ");
    
}