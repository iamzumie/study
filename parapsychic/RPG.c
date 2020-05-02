#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Functions I am going to define that I don't know of but there is probably a better way to do this
char firstName();
char bettergets(); //clears input buffer and takes in input, basically, ignores \n from previous gets.

//Actual Functions required in the game
void printyou();
int input();
void startUp();
void equip();
void map(); 
void mapft();
void changeto();
void commgen();
void switchToWorld();
void smart();
int combatsystems();
int combat();
void enemyCombat();
void playerCombat();
int weapondamage;

/*MAP LOCATIONS*/
void fazeloc();
void opticloc();
void fnaticsloc();
void nvsloc();


/*GLOBAL VARIABLES*/
//MAP DISCOVERYS
int faze,optic, fnatics,nvs;  // These variables indicate if the place has been discovered or not
int ftallow;  //Tells if fast travel is allowed or not like during combat
int currentloc; //Gives the current location of the player
int visitFaze, visitOptic, visitFnatics, visitNvs;


//COMMAND LINE
//Bettergets
int btrgts=0;

//USER ABILITIES
char namePlayer[30], fname[30];
int strength, armor, intelligence, weaponsskills, stamina;
int health=100;
int weaponequipped=0; //weaponequipped, swords- 1-5, bows 6-10, great swords 10-12, spears 13-15, staffs 15-20


//ENEMY ABILITIES
char enemyName[30];
int enemyHealth;
int difficulty;


void main()
{
    int choice;
    int age;

    /*INITIALISING COMBAT RANDOM NUMBER GENERATOR*/
                    srand(time(NULL));  //Just ignore this.
    /* ******************************************/

    // TITLE SCREEN + INTRODUCTION
    startUp();


    // ASK NAME
    scanf("%[^\n]s",namePlayer);
    firstName(namePlayer,fname);


    // FIRST QUESTION
    printf("\n\nSTRANGER: Welcome %s, why have you come to this cursed land?\n\n", fname);    
    printf("[1] I don't know \t [2] Why do you care old man \t [3] I lost my way over here.\n\n");
    printf("==\t\tMake a choice: type 1, 2, or 3.\t\t==\n");

    do
    {
        input(&choice);
        switch(choice)
        {
            case 1:printf("STRANGER: You must've lost your memories.\n"); break;
            case 2:printf("STRANGER: How rude of you to say that to the man that just saved your life?\n"); break;
            case 3:printf("STRANGER: Child, nobody is lost. There are no mistakes.\n"); break;
            default: printf("You picked the wrong house fool. Try again.\n"); break;
        }
    } while (choice < 1 || choice > 3);


    // SECOND QUESTION
    printf("STRANGER: However, I found you lying there under the Tree of Thousand Blossoms. You seem to be quite lost.\n\n");
    printf("STRANGER: Tell me, what's your age?\n"); 
    printyou();
    scanf("%i", &age);

    while(age <= 0) {
        printf("You picked the wrong house fool. Try again.\n");
        printyou();
        scanf("%i", &age);
    }


    // THIRD QUESTION
    printf("STRANGER: (laughing) You surely don't look %i. You seem to have really lost your memories.\n\n", age);
    printf("STRANGER: But that could only happen to the Chosen One. Could it be? But the legends?!\n\n");
    printf("[1] Let's get outta here Mastuhchief\t [2] I AM the Chosen One\t [3] What are you talking about?\n");
    do
    {
        input(&choice);
        switch(choice)
        {
            case 1: printf("STRANGER: Ah.. I see you are a man of culture as well \n\n"); break;
            case 2: printf("STRANGER: But for someone like you to be the One! How can it be? \n\n"); break;
            case 3: printf("STRANGER: The Chosen One, like in all other games and literature, will save us from the Great Villain \n\n"); break;
            default: printf("You picked the wrong house fool. Try again.\n"); break;
        }
    } while (choice < 1 || choice > 3);
    

    // FOURTH QUESTION
    printf("STRANGER: Your journey begins here traveller, you have chosen the path.\n\n");
    printf("STRANGER: Oh how rude of me to not introduce myself. Greg Kelsoe, i am chief of this tribe.\n\n");
    printf("GREG: I think that's all you need to know for now.\n");
    printf("      You seem to be healed, head on out Chosen One.\n\n\n");
    printf("[1] Head Out \t [2] What does it mean to be 'the Chosen One?'\t [3] This is BS, I'm getting outta here!\n");
    do
    {
        input(&choice);
        switch(choice){
            case 1: printf("*Heads out*\n\n"); break;
            case 2: printf("Greg: Oh why? It means everything.\n");
                    printf("The ability to change whatever he wanted, to remake the World as you see fit.\n");
                    printf("To dodge bullets, oh wait, bullets aren't a thing yet. Oh well.\n\n (heads out)\n\n"); 
                    break;
            case 3: printf("Greg: You aren't going anywhere.");
                    printf("To have crossed the Great Lake once is just sheer luck. Luck will not help you next time.\n\n(heads out)"); 
                    break;
            default: printf("\nYou picked the wrong house fool.\n\n"); break;
    }
    } while (choice < 1 || choice > 3);
    
    
    //MAIN GAME
    char command[20];
    int i=0;

    // PHAZE CLAN INTRO
    printf("\n\n\n\n********************************\n");
    printf("* DISCOVERED PHAZE CLAN HOLDOUT *\n");
    printf("********************************\n\n\n\n");
    faze=1;

    // FIFTH QUESTION
    printf("Miko:\t Greg thinks you're the Chosen One. BS\n\n");
    printf("[1] What do you want big guy? \t [2] I think the same!\n");
    do
    {
        input(&choice);
        switch(choice){
            case 1: printf("\n\nMiko:\tDon't act tough, we all know who you are.\n"); break;
            case 2: printf("\n\nMiko:\tAtleast someone knows his stuff around.\n"); break;
            default: printf("\n\nMiko:\tYou picked the wrong house fool.\n"); break;
        }
    } while (choice < 1 || choice > 2);
    
    // OPEN MAP
    printf("Miko:\tGreg wants me to show you around.\n\n");
    printf("Miko:\tHere, take this map. It'll help you in your journey. \n\n");
    printf("\t*Map Added*\n\n");
    printf("==\t To equip map, type switch and hit return/enter. Then type map.\t==\n\n\n");
    getchar(); // REMOVES NEWLINE FROM BUFFER
    currentloc=1;
    ftallow=0;
    commgen();
}


//COMMON COMMAND CENTRE
void commgen()
{
    int i = 0;
    char command[20];
    
    while(i==0){
    printf("COM:\t\t");
        if (fgets(command, sizeof command, stdin) != NULL) {
        size_t len = strlen(command);
        if (len > 0 && command[len-1] == '\n') {
            command[--len] = '\0';
        }
    }
        if(strcmp(command,"switch")==0){changeto(); i++;break;}
        if(strcmp(command,"ft")==0){mapft(); i++; break; }

        if(i==0){printf("\nCommand not found \n"); continue;}
        }
}

//SWITCHING BETWEEN COMMANDS
void changeto()
{
    int i=0;
    char command[20];
    
    while(i==0){
    printf("SWITCH TO: \t");
        if (fgets(command, sizeof command, stdin) != NULL) {
        size_t len = strlen(command);
        if (len > 0 && command[len-1] == '\n') {
            command[--len] = '\0';
        }
    }
        if(strcmp(command,"World")==0) {switchToWorld(); i++;}
        if(strcmp(command,"map")==0) { map();i++;}
        if(strcmp(command,"weapons")==0) {/*weapons()*/printf("Weapons is loaded\n");; i++;}
        if(strcmp(command,"items")==0) { /*items()*/printf("Items is loaded\n");; i++;}
        if(strcmp(command, "COM")==0) commgen();
        if(strcmp(command,"ft")==0)mapft();
        if(i==0) {printf("Invalid command\n"); continue;}

    }
}


/*MAP*/
void switchToWorld(){
    if(currentloc==1) fazeloc();
    if(currentloc==2) opticloc();
    if(currentloc==3) fnaticsloc();
    if(currentloc==4) nvsloc();
}


//DISPLAY CURRENT LOCATION AND MAP
void map(){

    printf("\n\n\n.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:\n");
    printf("||\t\t\tMAP\t\t\t\t||\n");
    printf(".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:\n\n");
    printf("\n\n\n ");

        puts("         --------------------------\n"
"   .----/	|	 	   \\---.\n"
"   |		|			\\\n"
" .-*	PHAZE	|			 *-.----.\n"
" |		!	FANATICS          /	\\.\n"
"  *    _......-**!			 /	  `!\n"
"   *../		  `*-__/\\_     __......./        ../\n"
"    *		      !   \\__/*			\\\n"
"  .*		      !			    ..~-*\n"
"  |		       `\\	eNVieduS    !\n"
"   *	 HOPTIC 	/		    |\n"
"     *		       /	    .~``*-.*'\n"
"	*	      /		_.-`\n"
"	  *-__.____.-*\\._.----~  \n");
    printf("\n\n\n");


    printf("*Phaze Clan Holdout \t [%c] [%c]\n*HopTic Stronghold \t [%c] [%c] \n*Fanatics Stronghold \t [%c] [%c] \n*eNVieduS Holds \t [%c] [%c] \n\n \n",(faze==1)?'O':'-',(currentloc==1)?'@':'-',(optic==1)?'O':'X',(currentloc==2)?'@':'-',(fnatics==1)?'O':'X',(currentloc==3)?'@':'-',(nvs==1)?'O':'X',(currentloc==4)?'@':'-');
    printf("== \t[X]: Not Travellable\t [O]: Travellable\t [@]: Current Location\n\n\n");
    printf("==\t To exit map, type switch and hit return/enter. then type World \t==\n\n\n");
    printf("==\t To fast travel, type ft and hit return/enter. then enter the whole name of the holdout \t==\n\n\n");
    commgen();


}

//FAST TRAVEL
void mapft(){
     int i=0,j=0;
     char command[20];
     while(i==0){
     printf("FAST TRAVEL: \t");
        //bettergets(command);

        if(strcasecmp(command,"phaze clan holdout")==0 )
           if(faze==1)
                if(currentloc!=1)
                    if(ftallow==1){fazeloc(); i++;j++;}
                    else {printf("You are currently here. \n\n"); continue;}
                else {printf("You are not allowed to travel now.\n\n"); continue;}
            else {printf("This place has not yet been discovered.\n\n"); continue;}



        if(strcasecmp(command,"HopTic stronghold")==0)
            if(optic==1)
                if(ftallow==1)
                    if(currentloc!=2) {opticloc(); i++;j++;}
                    else {printf("You are currently here.\n\n"); continue;}
                else {printf("You are not allowed to travel now.\n\n"); continue;}
            else {printf("This place has not yet been discovered.\n\n"); continue;}


        if(strcasecmp(command,"fanatics stronghold")==0)
            if(fnatics==1)
                if(ftallow==1)
                    if(currentloc!=3) {fnaticsloc(); i++;j++;}
                    else {printf("You are currently here.\n\n"); continue;}
                else {printf("You are not allowed to travel now.\n\n"); continue;}
            else {printf("This place has not yet been discovered.\n\n"); continue;}


        if(strcasecmp(command,"enviedus holds")==0)
            if(nvs==1)
                if(ftallow==1)
                    if(currentloc!=4) {nvsloc(); i++;j++;}
                    else {printf("You are currently here.\n\n"); continue;}
                else {printf("You are not allowed to travel now.\n\n"); continue;}
            else {printf("This place has not yet been discovered.\n\n"); continue;}

        else if(strcasecmp(command,"switch")==0){changeto();i++;}
        else if(strcasecmp(command,"com")==0) {commgen();i++;}
        else {printf("Invalid command\n"); continue;}


     }
}

/*MAP LOCATIONS*/
void fazeloc(){
    int i,res;
    int choice;
    char command[30];
    if(currentloc!=1){
    printf("\n\n\nTravelling to Phaze Clan Holdout \n\n\n\n");}
    if(visitFaze==0)
    {
        smart();
        visitFaze++;
    }
    if(visitFaze==1) //QUEST 1
    {
        i=0;
        printf("\n\n\n =*=*=*QUEST STARTED: THE GHOST KNIGHT *=*=*=\n\n");
         puts("      _,.\n"
"    ,` -.)\n"
"   ( _/-\\\\-._\n"
"  /,|`--._,-^|            ,\n"
"  \\_| |`-._/||          ,'|\n"
"    |  `-, / |         /  /\n"
"    |     || |        /  /\n"
"     `r-._||/   __   /  /\n"
" __,-<_     )`-/  `./  /\n"
"'  \\   `---'   \\   /  /\n"
"    |           |./  /\n"
"    /           //  /\n"
"\\_/' \\         |/  /\n"
" |    |   _,^-'/  /\n"
" |    , ``  (\\/  /_\n"
"  \\,.->._    \\X-=/^\n"
"  (  /   `-._//^`\n"
"   `Y-.____(__}\n"
"    |     {__)\n"
"          ()\n");
printf("\nA new challenger approaches \n\n\n");
printf("Ghost Knight: \t Bring me the chosen One. I will slay him and enchant my sword with his blood.\n\n");

printf("\n[1.Use Speech (Intelligence)\t 2. RUN (requires Stamina) 3. FIGHT (COMBINATION OF ABILITIES)\n\n");
while(i==0)
{
    input(&choice);
    if(choice==1)
    {
        if(intelligence>5){printf("\n\nGHOST KNIGHT: \tYour words cannot keep me off for a long time. But I must go now\n\n");intelligence++;break;}
                                  else {printf("\n\nGHOST KNIGHT: \tYour words don't scare me.\n\n");intelligence++;continue;}
    }
    else if(choice==2)
    {
        if(stamina>5) {printf("\n\nGHOST KNIGHT: \tYou can run, but cannot hide for long. I will be back.\n\n");stamina++;break;}
                                  else {printf("\n\nGHOST KNIGHT: \t(runs) Haha, fool you think you can run away from me?\n\n");stamina++;continue;}

    }
    else if(choice==3)
    {
        res=combatsystems(20,2,"Ghost Knight");
        if(res==1){printf("\n\nYOU HAVE SLAIN GHOST KNIGHT\n\n");break;}
        else {printf("\n\nYOU HAVE BEEN SLAIN. Fight Again\n\n");continue;}


    }
    else {printf("\n\nyou picked the wrong house fool.\n\n\n"); continue;}
    }
    printf("\n\nMiko:\t This... This is impossible. The Ghost Knight never leaves without the head he came for. \n");
    printf("\n\nMiko:\t You really must be the Chosen One. \n\n\n");
    printf("\n\n\n=+=+=+=THE GHOST KNIGHT COMPLETED =+=+=+\n\n\n");
    //If possible add a "hold standing system.
    printf("\n\n\nMiko:\t You should go to HopTic and announce your arrival to the Island. I'll have a messenger sent ahead of you. \n\n");
    printf("==\tType ok to continue\t==\n");
    while(i==0){
    printf("YOU: \t");
    fgets(command, sizeof command, stdin);
    if(strncmp(command,"ok",2)==0){ break;}
    else {printf("\nLet me know if you change your mind\n"); continue;}
    }
    visitFaze++; //QUEST 1 COMPLETED
    ftallow=1;
    optic=1;
    printf("\n\n\nSwitch to your map, and travel to HopTic\n");
    commgen();
    }
}



void opticloc(){
    printf("Travelling to Team Hoptics Stronghold\n");
}

void fnaticsloc(){
    printf("Travelling to Fanatics Stronghold\n");
}

void nvsloc(){
    printf("Travelling to eNVieduS Holds\n");
}

/*MAP LOCATIONS END*/

/*SMART*/

void smart(){ //Abilities of the player
    int i=0,n;
    char command[30],y[2];
    printf("\n\n\nMiko: \tIt's time for testing out your skills. Head over to Dunkley to start.\n[Type OK to go to Dunkley.]\n\n");
    while(i==0){
    printf("YOU: \t");
    fgets(command, sizeof command, stdin);
    if(strncmp(command,"ok",2)==0){ printf("\n\n\n(Goes to Dunkley)\n\n"); break;}
    else {printf("\nLet me know if you change your mind\n"); continue;}
    }
    printf("\n\n\nDunkley:\t Ahh, the chosen one. You are here to put your abilities to the test. Let's start:\n \n\n\n");
    printf("== Allocate points as to skills as required. You have a total of 20 points to spend. ==\n");
    printf("== YOU CANNOT REALLOCATE THESE POINTS FURTHER DOWN THE GAME. ==\n");
    printf("\nAbilities: STRENGTH, REFELEX, INTELLIGENCE, WEAPON SKILLS, STAMINA\n");

    while(i==0){
    n=20;
    printf("\n\n\nStrength:\t [%d]/[20] \t",n); scanf("%d",&strength); n=n-strength;
    printf("Armor:  \t [%d]/[20] \t",n); scanf("%d",&armor); n=n-armor;
    printf("Intelligence:\t [%d]/[20] \t",n); scanf("%d",&intelligence ); n=n-intelligence;
    printf("Weapon Skills:\t [%d]/[20] \t",n); scanf("%d",&weaponsskills); n=n-weaponsskills;
    printf("Stamina:\t [%d]/[20] \t",n); scanf("%d",&stamina); n=n-stamina;

    if(n<0)
        {printf("\nYou have used up more points. Reallocate. \n");continue;}
    else if(n>0){printf("\nYou have points remaining to allocate. Reallocate \n");continue;}
    else if(n==0){
            printf("\nAllocation complete. Do you want to reallocate? (y/n) \n");
            scanf("%s",y);
            if(strcasecmp(y,"y")==0) continue;
            else {printf("\n\n\n*==Abilities are increased based on your use. Use an ability more to level it up==*\n\n\n\n"); break;}
            }
    }
}

/*COMBAT*/
int combatsystems(int opponentHealth,int currentdifficulty,char currentenemyname[30]) //changes enemy abilities
{
    int res;
    enemyHealth=opponentHealth;
    difficulty=currentdifficulty;
    strcpy(enemyName, currentenemyname);
    if(enemyHealth!=0 || health!=0)
        res=combat();
    return res;

}

int combat()
{
    int combresult;
    int i=0;
    while(i==0){
    printf("\nYour Health [%d]\t Stamina [%d] \t x \t %s Health [%d] \n \n",health,stamina,enemyName,enemyHealth);
    if(health<=0) {combresult=0; break;}
    else if(enemyHealth<=0) {combresult=1; break;}
    else {int r = rand()%5+1;
    enemyCombat(&r);}

    }

    return combresult;

}


void enemyCombat(int *r)
{
    int imp=rand()%10+2; //imp or impact helps to randomize and fine adjust the damages to a certain level while difficulty is a coarse adjustment to damaage.
    switch(*r){
    case 1: {printf("%s used Slash damaging %d health \n\n",enemyName,imp*difficulty);health=health-(imp*difficulty); break;}
    case 2: {printf("%s used Puncture damaging %d health \n\n",enemyName,imp*difficulty);health=health-(imp*difficulty);break;}
    case 3: {printf("%s used Magic damaging %d health \n\n",enemyName,imp*difficulty);health=health-(imp*difficulty);break;}
    case 4: {printf("%s used Special Move damaging %d health \n \n",enemyName,(imp+2)*difficulty);health=health-((imp+2)*difficulty);break;}
    case 5: {printf("%s attacked and missed \n \n",enemyName);break;}
    }
    printf("Your Health [%d]\t Stamina [%d] \t x \t %s Health [%d] \n \n",health,stamina,enemyName,enemyHealth);
    playerCombat();
}


void playerCombat(){
if(stamina!=0){
    int r, enemyPossibility, choice; //r is enemy's choice. enemypossibility is possibility of next to be missed  by the enemy
    int playerPossibility=rand()%10; //possibility of player missing next attack, a factor of 10 provides a fair possibility with range.

int imp = rand() % 5 + 1; //imp or impact helps to randomize and fine adjust the damages to a certain level while skills do the coarse adjustment
printf("[1. Slash \t 2. Punch \t 3. Kick \t 4. Special Move \t 5. Defend (Conserves Stamina)]\n");

input(&choice);
if(playerPossibility>3) //so player can miss only few times
{
switch (choice) {
case 1:
  {
    if(weaponequipped!=0){
    printf("You used Slash damaging %d %s 's health \n\n", (strength*(stamina / imp) + (weaponsskills * weapondamage ) * (imp / difficulty)), enemyName); enemyHealth = enemyHealth - (strength*(stamina / imp) + (weaponsskills * weapondamage ) * (imp / difficulty));
      stamina--;
      break;
    }
    else printf("You do not have a weapon equipped, Try another attack \n");
    playerCombat();
    break;
  }
    case 2: {
      printf("You used Punch damaging %d %s 's health \n\n", ((strength + stamina) * (imp / difficulty)), enemyName);enemyHealth = enemyHealth - ((strength + stamina) * (imp / difficulty));
      stamina--;
      break;
    }
    case 3: {
      printf("You used Kick damaging %d %s 's health \n\n", (((1+imp) * strength * stamina / imp ) * ((imp+2) / difficulty)), enemyName); enemyHealth = enemyHealth - ((1+imp) * strength * stamina / imp ) * ((imp+2) / difficulty);
      stamina--;
      break;
    }
    case 4: {
      printf("You used Special Move damaging %d %s 's health \n\n", (((3*imp) * strength * stamina / (imp)) * ((imp+1) / difficulty)), enemyName);enemyHealth = enemyHealth - (((3*imp) * strength * stamina / (imp)) * ((imp+1) / difficulty));
      stamina--;
      break;
    }
    case 5: {
      printf("You are defending \n");
      enemyPossibility = rand() % 5+((armor%4)/difficulty); //+(armor%4)/difficulty gives more probability of the enemy missing when armor is sufficiently high.
      if (enemyPossibility >=2) { //so enemy can miss more times while defending
        r = 5;
        enemyCombat( & r);
      } else combat();
    }
    default: {
      printf("Invalid Attack.\n");playerCombat();
    }
  } //End of switch stmnt
  combat();
}   //Possibility if end
else { printf("You missed. \n \n");combat();} //Possibility if else

}   //Stamina if end
else{   //Stamina if else
        printf("You are out of stamina, you'll have to sit out this move \n");
        stamina++;
        combat();

    }
}




// PRINT STATEMENT
void printyou() 
{
    printf("\n\nYOU:\t");
}

// USER INPUT
int input(int *a)
{
    printyou();
    scanf("%i",&*a);

    return *a;
}

// TITLE SCREEN + INTRODUCTION
void startUp() 
{
    // TITLE SCREEN
    printf("*********************************************************************************************************\n");
    puts("*\t\t\t\t\tTHE MLG ISLANDS: 420 360 NOSCOPE HEADSHOT \t\t\t*\n"
           "*\t\t\t\t\t\tA CLI RPG \t\t\t\t\t\t*");
    printf("*********************************************************************************************************\n");

    // INTRODUCTION
    printf("\n\nWelcome adventurer,\nYou have travelled far into the Forbidden Jungle of Azekaphar. ");
    printf("These are dangerous places, and dangerous times..\n\n");
    printf("Tell me, what is your name traveller?\n");
    printyou();

}



/*FUNCTIONS I WROTE BECAUSE I DONT KNOW ANY PRE-DEFINED FUNCTIONS AND THESE COULD PROBABLY BE DONE IN BETTER WAYS*/
char firstName(char a[30],char b[30]) //for extracting first name from full name entered first
{
    int i;
    char temp;
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]!=' ')
        {
            b[i]=a[i];
        }
        else { b[i]='\0'; break;}
    }
}
