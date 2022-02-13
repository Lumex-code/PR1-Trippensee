#define WIN32_LEAN_AND_MEAN // windows.h gets compiled faster due to reduction in Load
#include <stdio.h>			//standard library
#include <stdbool.h>		//library allowes the usage of booleans | False = 0 and True = 1
#include <windows.h>		//library used to change the Color of Text
#include "object.h"			//object.h used here to access the status of "hole"
#include "Typewriter.h"		//header includes function TypeLine, wich allows for Typed out effect on console

int ending() 
{
	if (hole->Status == 2)
	{
		TypeLine(".....\n", 40);
		TypeLine("After you give the guard the gold ingot, he thanks you and opens the door with one of the keys on his keychain.\n", 20);
		TypeLine("You go through the door into the long tunnel, suddenly everything turns white.\n", 40);
		system("COLOR F0");
		TypeLine(".........\n", 80);
		TypeLine("Tutorial complete...\n", 80);
		TypeLine("Welcome traveler.......\n", 80);
		TypeLine("\n\n\nTO BE CONTINUED....\n\n", 80);
		TypeLine("Type 'quit' to quit",10);
		player->Status = 6;
		return false;
	}
	else
	{
		TypeLine(".....\n", 40);
		TypeLine("After you give the guard the gold ingot, he thanks you and opens the door with one of the keys on his keychain.\n", 20);
		TypeLine("You go through the door into the long tunnel, suddenly everything turns Black again.\n", 40);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		TypeLine(".........\n", 80);
		TypeLine("Tutorial Complete...\n", 80);
		TypeLine("Welcome Traveler.......\n", 80);
		TypeLine("\n\n\nTO BE CONTINUED....\n\n", 80);
		TypeLine("Type 'quit' to quit",10);
		player->Status = 6;
		return false;
	}
}