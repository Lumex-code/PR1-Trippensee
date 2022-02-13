#define _CRT_SECURE_NO_DEPRECATE //allows us to use strtok
#include <stdio.h>      //standard library
#include <stdbool.h>    //library allowes the usage of booleans | False = 0 and True = 1
#include <string.h>     //library for standard string manipulatuion(strtok)
#include "location.h"   //header allows the usage of "look" and "go" as commands    ->  location.c
#include "inventory.h"  //header allows the usage of "inventory", "drop" and "take" ->  inventory.c
#include "action.h"     //header allows the usage of "inspect", "talk", "interact"  ->  action.c
#include "help.h"       //Includes help function, wich lists every command
#include "object.h"     //included to acess player status



bool parseAndExecute(char* input); //Function is repeated and checks input given to it


bool parseAndExecute(char* input)
{
    // standard function strtok is used to build a basic verb-noun parser
    // strtok splits string, where space is and replaces it with a /0 -> we get 2 Strings from a single input
    char* verb = strtok(input, " \n");
    char* noun = strtok(NULL, " \n");
    
    //checks if ending is fullfiled
   

    if (verb != NULL)
    {
        if (strcmp(verb, "quit") == 0)
        {
            return false;
        }
        else if (strcmp(verb, "look") == 0)
        {
            executeLook(noun);
        }
        else if (strcmp(verb, "go") == 0)
        {
            executeGo(noun);
        }
        else if (strcmp(verb, "inventory") == 0)
        {
            executeInventory();
        }
        else if (strcmp(verb, "drop") == 0)
        {
            executeDrop(noun);
        }
        else if (strcmp(verb, "take") == 0)
        {
            executeTake(noun);
        }
        else if(strcmp(verb, "inspect") == 0)
        {
            executeAction(verb, noun);
        }
        else if (strcmp(verb, "talk") == 0)
        {
            executeAction(verb, noun);
        }
        else if (strcmp(verb, "interact") == 0)
        {
            executeAction(verb, noun);
        }
        else if (strcmp(verb, "help") == 0)
        {
            help();
        }
        else
        {
            printf("I don't know how to '%s'.\n", verb);
        }
    }

    return true;
}
