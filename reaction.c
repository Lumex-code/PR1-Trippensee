#define WIN32_LEAN_AND_MEAN // windows.h gets compiled faster due to reduction in Load
#include <stdio.h>			//standard library
#include <string.h>			//library for standard string manipulatuion(strcmp-> compares strings)
#include <windows.h>		//library used to change the Color of Text
#include "object.h"			//accesses object.c to modify aswell as read the locations and statuses
#include "list.h"			//header includes "listObjectsAtLocation" -> list.c lists the Objects at the given location
#include "Typewriter.h"		//header includes function TypeLine, wich allows for Typed out effect on console
#include "ending.h"			//calls the ending function(->ending.c) wich triggers the ending sequence aswell as quits the game


//reaction Functions for reactions of special Objects
//self explanitory names
void reactionGuard(const char* action);
void reactionVein(const char* action);
void reactionForest(const char* action);
void reactionOven(const char* action);
void reactionChest(const char* action);
void reactionBox(const char* action);
void reactionHole(const char* action);
void reactionNote(const char* action);



void reactionGuard(const char* action)
{
	
	if ((strcmp (action, "interact") == 0) || (strcmp(action, "inspect") == 0))
	{
		if (guard->Status == 0)
		{
			TypeLine("\nThe Guard doesnt seem to be botherd by the fact that you just came out of nowhere\n", 10);
			TypeLine("He has a strong physique with a matching beard in a rugged face to it\nBesides that he wears a chainmail over a garment.\n",10);
			listObjectsAtLocation(guard);

			TypeLine("Behind him is a relative giant Door with a blantant flashing '", 10);
			TypeLine("EXIT",10);
			TypeLine("' sign over it.\n",10);
			
		
			guard->Status = 1;
		}
		else if (guard->Status == 1) {
			TypeLine("It is still the Guard, he hasnt changed much.\nMaybe you should try and talk to him?\n",0);
			listObjectsAtLocation(guard);
		}
		else if(gold->location == player)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			TypeLine("Congratz, you may Pass\n", 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			ending();
		}
		else {
			printf("Hey, whats up? have you got the things i asked for yet?"); //Player will not see this
		}
		
	}

	if (strcmp(action, "talk") == 0)
	{
		if (guard->Status == 1 || guard->Status == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			TypeLine("You are not from around here are you?\n", 30);
			TypeLine("....\nAlso not very talkative huh?\n", 30);
			TypeLine("I have a hunch, that you want to leave this Place, But i wont let you\nAtleast not for some fine Gold\nFeel free to use the equipment from my humble House\n", 30);
			TypeLine("Just a warning.... stay away from the shed\n", 30);
			TypeLine("Off you go then\n", 30);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			guard->Status = 2;
		}
		else if (guard->Status == 2 && gold->location != player)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			TypeLine("If you aint got the Gold, you aint passing through", 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (gold->location == player)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			TypeLine("Congratz, you may Pass\n", 20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			ending();
		}
	}
}

void reactionVein(const char* action) 
{
	if (pickaxe->location == player)
	{
		if (strcmp(action, "interact") == 0)
		{
			TypeLine("You Break the Gold Vein apart with your Pickaxe\n", 20);
			TypeLine("You gain: raw gold that shimers a bit\n", 10);
			rawGold->location = player;
			vein->location = NULL;
			pickaxe->Status = 1;
		}
		if ((strcmp(action, "take") == 0)) {
			printf("You could use your Pickaxe and try and interact with it.\n");
		}
	}
	if (strcmp(action, "talk") == 0)
	{
		printf("In an attempt to talk to the Vein, you realize that its not sentient.\n");
	}
}

void reactionForest(const char* action)
{
	if (strcmp(action, "interact") == 0) {

		if (axe->location == player) {

			if (wood->location == player)
			{
				TypeLine("You dont see the need to chop more wood", 10);
			}
			else
			{
				TypeLine("You chop some wood\n", 10);
				TypeLine("You Gain: Wood\n", 10);
				wood->location = player;
			}
		}
		else
		{
			TypeLine("Maybe you should get an axe and try again", 10);
		}		
	}
	//box path
	if (strcmp(action, "inspect") == 0)
	{
		if (box->location == player)
		{
			TypeLine("You dont find anything special", 10);
		}
		else
		{
			TypeLine("You find a Box, it is beautifull\n", 10);
			TypeLine("You gain: a small Box\n", 10);
			box->location = player;
		}
	}
}

void reactionOven(const char* action)
{
	if (strcmp(action, "interact") == 0)
	{
		if (rawGold->location == player && wood->location == player)
		{
			TypeLine("You use Wood to start a fire in the oven, that was apparently enough to even smelt the gold.\n",10);
			TypeLine("Through some kind of complicated process the liquid gold gets poured into a form, where it hardens.\n", 10);
			TypeLine("You get: pure Gold",10);
			gold->location = player;
			wood->location = NULL;
			rawGold->location = NULL;
		}
		else
		{
			TypeLine("You are missing some ingredients",10);
		}
	}
	if (strcmp(action, "interact") == 0)
	{
		TypeLine("The oven is a bit dusty but kept clean, on the side of the oven is interestingly a pipe that leads into a casting mold.\n", 20);
	}
}

//Objects not relevant for compeletion of main quest

void reactionChest(const char* action)
{
	if ((strcmp(action, "interact") == 0) || (strcmp(action, "inspect") == 0))
	{
		TypeLine("You open the chest and peek inside.\n",10);
		listObjectsAtLocation(chest);
		if (key->location == chest)
		{
			if (key->Status == 0)
			{
				TypeLine("You ask yourself what the key might be for\n", 10);
				
			}

			if (box->location == player)
			{
				TypeLine("Maybe its for the Box you found.\n",10);
				key->Status = 1;
			}

		}
	}
}

void reactionBox(const char* action)
{
	if (strcmp(action, "inspect") == 0)
	{
		TypeLine("You take the box in your hand and look at it in detail. The oak box is decorated with a golden writing, which you do not know.\n", 10);
	}
	if (strcmp(action, "interact") == 0)
	{
		if (key->location == player) {
			if (key->Status == 1)
			{
				TypeLine("You open the box with the key successfully.\nIn the box you can find a rune. When you look at this rune, an unpleasant feeling comes up.\nYou put the rune aside again.\n", 10);
				key->Status = 2;
				rune->location = player;

			}
			else if (key->Status == 2) {
				TypeLine("There is nothing for you to interact with anymore", 10);
			}
			
		}
	}
}
void reactionHole(const char* action) 
{
	if ((strcmp(action, "interact") == 0) || (strcmp(action, "inspect") == 0))
	{
		if (rune->location = player)
		{
			TypeLine("You place the rune appropriately, in the pattern around the hole.\nPurple sparks fly around, then nothing.\n", 10);
			hole->destination = cave;
			hole->Status = 2;
		}
		else if (hole->Status == 0 && rune->location != player)
		{
			TypeLine("This seems to be a Ritual of some kind involving Runes\n", 10);
			TypeLine("Maybe you can complete it?",10);
			hole->Status = 1;

		}
		else if (hole->Status == 1 && rune->location != player)
		{ 
			TypeLine("You dont have the needed material to activate it\n", 10);

		}
		
	}
}
void reactionNote(const char* action)
{
	if ((strcmp(action, "interact") == 0) || (strcmp(action, "inspect") == 0))
	{
		if (hole->Status == 0)
		{
			if (box->location == player)
			{
				TypeLine("On the note you will see a sketch of the box you found, next to it a few rune characters in a circle.", 10);
			}
			else
			{
				TypeLine("On the note you see a box drawn with some characters around it.\n",10);
			}
		}
		else
		{
			if (box->location == player)
			{
				TypeLine("On the note you can see a sketch of the box you found and the hole you saw in the shed.",10);
			}
			else
			{
				TypeLine("On the note you can see a sketch of a box and the hole you saw in the shed surrounded by runes", 10);
			}
		}
	}
}