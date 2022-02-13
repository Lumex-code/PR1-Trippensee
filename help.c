#include <stdio.h>					//standard library

void help(); //functions lists concept on how to use commands aswell as every possible command

void help() 
{
	return printf("\nThe Command system is a basic verb-noun parser, that means you type the verb first and the the object you want to interact with.\nCommands:\n'look'\n'go'\n'inventory'\n'drop'\n'take'\n'inspect'\n'talk'\n'interact'\n\n");
}