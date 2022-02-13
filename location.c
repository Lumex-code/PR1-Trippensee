#include <stdio.h>      //standard library
#include <string.h>     //library for standard string manipulatuion(strcmp-> compares strings)
#include "object.h"     //header includes a struct with a pointer to itself(used in object.c), for easier refrence of the object we also define 
#include "list.h"       //header includes "listObjectsAtLocation" and "getPassage" -> list.c
#include "noun.h"       //header includes "isThere" function wich checks if the given Object should be reachable by the Player
#include "Typewriter.h" //header includes function TypeLine, wich allows for Typed out effect on console

void executeLook(const char* noun); //when called lits all the objects at Location of Player, exept for the Player himself aswell as the Location
void executeGo(const char* noun);   //when called, will go to a Location, if they are adjacent to the current Location and reachable(noun.c-> isThere) when arriving, it calls executeLook to get list of objects in new Location

void executeLook(const char* noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are in %s.\n", player->location->description);
        listObjectsAtLocation(player->location);
    }
    else
    {
        TypeLine("I don't understand what you want to see.\n", 15);
    }
}

void executeGo(const char* noun)
{
    OBJECT* obj = isThere("where you want to go", noun);
    if (obj == NULL)
    {
        // already handled by isThere
    }
    else if (getPassage(player->location, obj) != NULL)
    {
        player->location = obj;
        executeLook("around");
    }
    else if (obj->location != player->location)
    {
        printf("You don't see any %s here.\n", noun);
    }
    else if (obj->destination != NULL)
    {
        player->location = obj->destination;
        executeLook("around");
    }
    else
    {
        TypeLine("You can't get much closer than this.\n", 15);
    }
}