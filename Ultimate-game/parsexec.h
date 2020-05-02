#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool parseAndExecute (char *input)
{
    char *verb = (input," \n");
    char *noun = (NULL, " \n");
    if (verb != NULL) 
    {
        printf("Right, like you got something better to do!\n");
        return false;
    }
    else if (verb == "look") 
    {
        printf("It's dark in here.\n");
    }
    else if (verb == "go")
    {
        printf("It's too dark in here.\n");
    }
    else
    {
        printf("I don't know how to '%s' .\n", verb);
    }
    
}