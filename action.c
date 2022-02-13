#include <stdio.h>		//standard library
#include <string.h>		//library for standard string manipulatuion(strcmp-> compares strings)
#include "object.h"		//Struct Object gets called to get information on Objects
#include "list.h"		//header includes "listObjectsAtLocation" -> list.c lists the Objects at the given location
#include "noun.h"		//header includes "isThere" function wich checks if the given Object should be reachable by the Player
#include "reaction.h"	//includes all the reaction functions for spesific Objects that need to trigger a special response 

void executeAction(const char* action, const char* object);	//gets called when User uses "interact,interpret or talk", it checks if the Object that is given requires a special response 

void executeAction(const char* action, const char* target)
{
	if (target != NULL && isThere("who you want to interact with", target))
	{
		if (strcmp(target, "guard") == 0)
		{
			reactionGuard(action);
		}
		else if (strcmp(target, "vein") == 0)
		{
			reactionVein(action);
		}
		else if (strcmp(target, "forest") == 0)
		{
			reactionForest(action);
		}
		else if (strcmp(target, "oven") == 0) {

			reactionOven(action);
		}
		else if(strcmp(target, "chest") == 0)
		{
			reactionChest(action);
		}
		else if (strcmp(target, "box") == 0)
		{
			reactionBox(action);
		}
		else if (strcmp(target, "hole") == 0)
		{
			reactionHole(action);
		}
		else if (strcmp(target, "note") == 0)
		{
			reactionNote(action);
		}
		else if(strcmp(target, "table") == 0)
		{
			listObjectsAtLocation(table);
		}
		else if (strcmp(target, "wardrobe") == 0)
		{
			listObjectsAtLocation(wardrobe);
		}
		else if (strcmp(target, "fridge") == 0)
		{
			listObjectsAtLocation(fridge);
		}
		else
		{
			//Uses this Code if object that is being interacted with is not sepcial enough
			OBJECT* obj = isThere("what you want to get", target);
			if ((strcmp(action, "inspect") == 0) || (strcmp(action, "interact") == 0))
			{
				printf("Its %s\n", obj->description);
			}
			else if (strcmp(action, "talk") == 0) 
			{
				printf("%s doesnt seem to respond\n",obj->tag);
			}
		}
	}
}
