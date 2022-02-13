/*	Programing 1 Presentation 14.02.2022
*	Studygroup: REE-PR1 | HAW-Hamburg
*	Professor: Prof. Dr. Marc Hensel
*	Developer: Henrik Maximilian Trippensee
* 
*	The Program is a Text Based Adventure in C. The User is asked to solve a puzzle with the given mechanics.
*	It is just a Demo, but most of the mechanics are implemented
* 
*/



#define _CRT_SECURE_NO_DEPRECATE	//allows one to use strcpy
#include <stdio.h>					//standard library
#include <stdbool.h>				//library allowes the usage of booleans | False = 0 and True = 1
#include "introduction.h"			//header for Introduction/main menu sequence -> introduction.c
#include "parseAndExecute.h"		//Header includes function of gameplayloop -> parseAndExecute.c

static bool getInput(void); //Function gets Input from keyboard and gets repeatly called in a while Loop


static char input[100] = "Introduction"; //deklaration of string, that gets called in getInput()

static bool getInput(void)
{	
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}

int main()
{
	while (menu(input) && getInput());	//Loop for menu


	strcpy(input, "look around");		//input gets set to 'Look Around' because we want to give Player Information


	while (parseAndExecute(input) && getInput()); //Main gameplay Loop -> calls parseAndExecute Function, where it asks the User for Input in a Loop(Execution.h -> Execute.c)

	
	printf("\nBye!\n"); //Message displays when one exits program


	return 0;
}