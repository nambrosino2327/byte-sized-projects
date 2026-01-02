#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Length of one bar
#ifndef WIDTH
#define WIDTH 20
#endif

// How long (in microseconds) each frame lasts
#ifndef TIME
#define TIME 50000
#endif

// How many bars appear
#ifndef BARS
#define BARS 20
#endif

int main(){
    srand(time(NULL));
    const char* colors[] = {"9", "10", "11", "12", "13"};

    printf("\x1b[?1049h"); // Enter alternate terminal

    while (1){
       printf("\x1b[H\x1b[2J");   // Clear the terminal before each frame

        for(int i = 0; i < BARS; i++){
            int h = rand() % WIDTH;
            printf("\x1b[38;5;%sm", colors[i % 5]);
            for (int j = 0; j < h; j++) putchar('|');
            printf("\x1b[0m\n");
        }

        usleep(TIME);
    }
}