#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void raceInitializer(char raceInit[]);
void tortoiseMoves(int *tortoisePtr);
void hareMoves(int *harePtr);
void printCurrentRaceStatus(char track[], int *tortoisePtr, int *harePtr);
void printWinner(int tortoisePtr, int harePtr);
void delay(unsigned int segs);

int main(void)
{
    int tortoisePosition = 1, harePosition = 1;
    char raceTrack[101];
    raceTrack[0] = '#';
    srand(time(NULL));
    puts("Tortoise and the Hare Race Game by GigiLucas");
    puts("Press enter to begin the race...");
    getchar();
    puts("BANG !!!!!");
    puts("AND THEY'RE OFF !!!!!");

    do
    {
        raceInitializer(raceTrack);
        tortoiseMoves(&tortoisePosition);
        hareMoves(&harePosition);
        if (tortoisePosition >= 100 || harePosition >= 100)
        {
            printf("%d %d\n", tortoisePosition, harePosition);
            break;
        }
        printCurrentRaceStatus(raceTrack, &tortoisePosition, &harePosition);
        delay(1);
    } while (tortoisePosition < 100 || harePosition < 100);
    printWinner(tortoisePosition, harePosition);
    return 0;
}

void raceInitializer(char raceInit[])
{
    for (size_t i = 1; i < 101; i++)
    {
        raceInit[i] = ' ';
    }
}

void tortoiseMoves(int *tortoisePtr)
{
    int destiny = 1 + rand() % 11;
    if (destiny >= 1 && destiny <= 5)
    {
        *tortoisePtr += 3;
    }
    if (destiny >= 6 && destiny <= 7)
    {
        *tortoisePtr -= 6;
        if (*tortoisePtr <= 0)
        {
            *tortoisePtr = 1;
        }
    }
    if (destiny >= 8 && destiny <= 10)
    {
        *tortoisePtr += 1;
    }
}

void hareMoves(int *harePtr)
{
    int destiny = 1 + rand() % 11;
    if (destiny >= 3 && destiny <= 4)
    {
        *harePtr += 9;
    }
    if (destiny == 5)
    {
        *harePtr -= 12;
        if (*harePtr <= 0)
        {
            *harePtr = 1;
        }
    }
    if (destiny >= 6 && destiny <= 8)
    {
        *harePtr += 1;
    }
    if (destiny >= 9 && destiny <= 10)
    {
        *harePtr -= 2;
        if (*harePtr <= 0)
        {
            *harePtr = 1;
        }
    }
}

void printCurrentRaceStatus(char track[], int *tortoisePtr, int *harePtr)
{
    if (*tortoisePtr == *harePtr)
    {
        for (size_t i = 0; i < 101; i++)
        {
            if (i == *tortoisePtr)
            {
                printf("%s", "OUCH!!!");
                continue;
            }
            printf("%c", track[i]);
        }
        puts("");
    }
    else
    {
        track[*tortoisePtr] = 'T';
        track[*harePtr] = 'H';
        for (size_t i = 0; i < 101; i++)
        {
            printf("%c", track[i]);
        }
        puts("");
    }
}

void printWinner(int tortoisePtr, int harePtr)
{
    if (tortoisePtr >= 100)
    {
        puts("TORTOISE WINS !!!!");
        puts("YAY !! ! ! !!");
    }
    if (harePtr >= 100)
    {
        puts("hare wins, yuch.");
    }
    if (harePtr == tortoisePtr)
    {
        puts("Its a tie. Underdog impressive !!!!");
    }
}

void delay(unsigned int segs)
{
    unsigned int timeNow = time(0) + segs;
    while (time(0) < timeNow)
    {
        ;
    }
}
