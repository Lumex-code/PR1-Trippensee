#include <stdio.h>		//standard library
#include <string.h>		//library for standard string manipulatuion(strcmp-> compares strings)
#include "object.h"		//header to access "OBJECT" struct here in particuarlly the weight int list for the objects 
#include "list.h"		//header includes "listObjectsAtLocation" and "getPassage" -> list.c
#include "noun.h"		//header includes "isThere" function wich checks if the given Object should be reachable by the Player


void executeInventory(void);		 //Lists all the Objects that have the Location of 'player', so evry object in Inventory
void executeTake(const char* noun);	//moves the mentioned object into the inventory, if it is not too heavy(see weight stat list)
void executeDrop(const char* item);	//moves the mentioned object to the location the player is currently in, but only when the object even is in the inventory


void executeInventory(void) 
{
	if (listObjectsAtLocation(player)==0){
		printf("You have nothing on you.");
	}
}

void executeTake(const char *noun)
{
	OBJECT* obj = isThere("what you want to get", noun);
	if (obj == player) {
		printf("You cant pick yourself up");
	}
	else if (obj->location == player)
	{
		printf("You already have %s. \n", obj->description);
	}
	else if (obj->weight == 1)
	{
		printf("%s is too heavy\n",obj->description);
	}
	else if (obj->weight == 3 || obj->weight == NULL)
	{
		printf("It is physically impossible to pick %s up\n", obj->description);
	}
	else if (obj->weight == 4)
	{
		printf("That is a bit too invasive, dont you think?");
	}
	else if (obj->weight == 5)
	{
		obj->location = player;
		printf("You pick up %s \n", obj->description);
	}
	else if (obj->weight == 2)
	{
		//special reactions if needed
	}
	else
	{
		printf("There has been an Glitch in the Matrix\n");
	}
	
	/*weight 0, NULL: an Object of the world(door, entrance ect.)
	* weight 1: too heavy
	* weight 2: open for special Objects(not yet implemented)
	* weight 4: private objects from guard for example
	* weight 5: Object can be picked up*/
}



void executeDrop(const char* item) 
{
	OBJECT* obj = isThere("what you want to drop\n", item);
	if (obj->location == player)
	{
		printf("You drop %s\n", obj->tag);
		obj->location = player->location;
	}
	else
	{
		printf("You dont have a %s in your inventory\n", obj->tag);
	}
}


