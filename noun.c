#include <stdio.h>      //standard library                                   
#include <stdbool.h>    //library allowes the usage of booleans | False = 0 and True = 1
#include <string.h>     //library for standard string manipulatuion(strcmp-> compares strings)
#include "object.h"     //header includes a struct with a pointer to itself(used in object.c), for easier refrence of the object we also define 
#include "list.h"       //header includes "listObjectsAtLocation" and "getPassage" -> list.c


/*Function isThere will output a generic message if no object in the Location matches the given noun*/
OBJECT* isThere(const char* intention, const char* noun);

/*Function getObject determines the object that belongs to a given noun.
It returns a pointer to the object with the tag that matches that particular noun
gets called only by isThere*/
static OBJECT* getObject(const char* noun);

/*Function objectHasTag gets called by getObjekt, to check if the noun is equale to the object we are
comparing it to. Returns True if that is the Case.
gets called by getObject*/
static bool objectHasTag(OBJECT* obj, const char* noun);



OBJECT* isThere(const char* intention, const char* noun)
{
    OBJECT* obj = getObject(noun);
    if (obj == NULL)
    {
        printf("I don't understand %s.\n", intention);
    }
    else if (obj->location == chest || obj->location == fridge || obj->location == wardrobe || obj->location == table)
    {
        //this else if checks for special cases
        if (player->location != hut || player->location != bedroom)
        {
            return obj;
        }
        else
        {
            return NULL;
        }
        
    }
    else if (obj->location == guard)
    {
    //else if checks for special case, so that one can interact with Items on guard when one is in cave
        if (player->location == cave) {
            return obj;
        }
        else
        {
            return NULL;
        }
    }

    else if (!(obj == player ||
        obj == player->location ||
        obj->location == player ||
        obj->location == player->location ||
        //Checks if 2 locations are adjacent, also prevents Objects with Locations set to NULL to be considered locations
        getPassage(player->location, obj) != NULL ||
        (obj->location != NULL &&
        (obj->location->location == player ||
         obj->location->location == player->location))))
    {
        printf("You don't see any %s here.\n", noun);
        obj = NULL;
    }
    return obj;
}

static OBJECT* getObject(const char* noun)
{
    OBJECT* obj, * pointerToObject = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun))
        {
            pointerToObject = obj;
        }
    }
    return pointerToObject;
}

static bool objectHasTag(OBJECT* obj, const char* noun)
{
    return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;
}