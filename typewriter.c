#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

char TypeLine(char* line, int time) {
    for (int i = 0; i < strlen(line); i++)
    {
        printf("%c", line[i]);
        fflush(stdout); //
        delay(time);
    }
}