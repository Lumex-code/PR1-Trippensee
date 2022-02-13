#define _CRT_SECURE_NO_DEPRECATE //allows one to use strcmp, strtok and scnaf
#define WIN32_LEAN_AND_MEAN      //windows.h gets compiled faster due to reduction in Load
#include <stdio.h>               //standard library
#include <stdbool.h>             //library allowes the usage of booleans | False = 0 and True = 1
#include <string.h>              //library for standard string manipulatuion(strcmp-> compares strings)
#include <Windows.h>             //library used to change the Color of Text
#include "Typewriter.h"          //header includes function TypeLine, wich allows for Typed out effect on console
#include "help.h"                //Includes help function, wich lists every command

void menu(char* input); //Main Menu where you can choose to start the Game
char Introduction();    //Introduction, Title of the game and starting text
void startingScene();   //Story gets played-> after that moves on to main Loop(main.c)
char skip();            //Story gets skipped-> return false -> main loop starts(main.c)

char name[30] = "Steve";

void menu(char* input) 
{

    char* verb = strtok(input, " \n");
    char* noun = strtok(NULL, " \n");

    if (verb != NULL)
    {
        if (strcmp(verb, "quit") == 0)
        {
            return false;
        }
        else if (strcmp(verb, "start") == 0)
        {
            startingScene(name);
        }
        else if (strcmp(verb, "Introduction") == 0)
        {
            Introduction();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else if (strcmp(verb, "skip") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            skip();
        }
        else if (strcmp(verb, "help") == 0)
        {
            help();
        }
        else
        {
            printf("I don't know what '%s' is.\n", verb);
        }
    }
}


char Introduction(void)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    TypeLine("Welcome to this magical adventure!\n", 10);
    TypeLine("------------------------------------\n", 10);
    TypeLine("To start the game type 'start', to quit type 'quit', to skip the intro type 'skip'.\n For a list of possible Commands type 'help'.\n", 10);

    return true;
}


char skip(void) 
{
    return false;
}

void startingScene(void)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
   
    TypeLine("\nYou wake up in a Dark Room.\n", 60);
    TypeLine("You look around, but you can`t seem to see or feel anything. \n", 60);
    TypeLine("You only remember that the elevator was suddenly in a free fall, after that you don't remember anything anymore.\n", 60);
    TypeLine("Suddenly you hear a british sounding voice say:\n", 120);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    TypeLine("\nahem.. !\n",130);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    TypeLine("\n*statict interference*\n", 40);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    TypeLine("\nIs this thing on?...\n", 130);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    TypeLine("\n*agressive microphone check*\n",40);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    TypeLine("\nI think this is working....\nAnyway...\n",60);
    TypeLine("\nWELCOME TO THE MOST EPIC... uh adventure?\n", 60);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    TypeLine("\n*paper flipping*\n", 40);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    TypeLine("\nUh... hu.... bla.. bla.. Death... Bla... Magic\n", 70);
    TypeLine("hmmmm\n", 70);
    TypeLine("Ah! Screw this!\n*Ahem*\nListen you are here for some stupid regulation of Coporate...\n", 60);
    TypeLine(".........\n",60);
    TypeLine("\noh... sorry, excuse my tardiness,... my name is ", 60);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    TypeLine("Alistor the XII,", 60);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    TypeLine(" may I ask for yours?\n", 60); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("\n--> ");
    scanf("%s", name);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    printf("%s??!\n", name);
    TypeLine("..... seriously?\n", 60);

    TypeLine("I will just call you Harvey.\n", 60);
    TypeLine("Anyway you just have to solve this Puzzle and you can return to your Mortal boring Life, ok?\nOK!\n", 60);
    TypeLine("Have Fun! and ", 60);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    TypeLine("WATCH OUT!\n",250);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    TypeLine("\nYour body suddenly disintegrates and you are being teleported.\n", 60);

    return false;
}


