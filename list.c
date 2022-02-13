#include <stdio.h>      //standard library
#include "object.h"     //header includes a struct with a pointer to itself(used in object.c), for easier refrence of the object we also define 

int listObjectsAtLocation(OBJECT* location);    //goes through list of Objects at the given location

OBJECT* getPassage(OBJECT* from, OBJECT* to);   //Checks if the given Location from executego() reachable is



int listObjectsAtLocation(OBJECT* location)
{
    int count = 0;

    OBJECT* obj;

    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (obj != player && obj->location == location)
        {
            if (count++ == 0)
            {
                printf("You see:\n");
            }
            printf("%s\n", obj->description);
        }
    }
    return count;
}

OBJECT* getPassage(OBJECT* from, OBJECT* to)
{
    if (from != NULL && to != NULL)
    {
        OBJECT* obj;
        for (obj = objs; obj < endOfObjs; obj++)
        {
            if (obj->location == from && obj->destination == to)
            {
                return obj;
            }
        }
    }
    return NULL;
}