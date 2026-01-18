#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Height of one bar
#ifndef HEIGHT
#define HEIGHT 20
#endif

// How long (in microseconds) each frame lasts
#ifndef TIME
#define TIME 50000
#endif

// How many bars appear
#ifndef BARS
#define BARS 20
#endif

void quit(int) {
  printf("\x1b[?25h\x1b[1049l");
  exit(0);
}

int main() {
  signal(SIGINT, quit);
  signal(SIGTERM, quit);

  srand(time(NULL));
  const char *colors[] = {"9", "10", "11", "12", "13"};

  printf("\x1b[?1049h\x1b[?25l"); // Enter alternate terminal

  while (1) {
    int heights[BARS];

    // Generate random heights
    for(int i = 0; i < BARS; i++) heights[i] = rand() % HEIGHT;

    printf("\x1b[H\x1b[2J"); // Clear the terminal before each frame

    // Print rows top to bottom
    for (int row = HEIGHT; row >= 0; row--) {
        for(int col = 0; col < BARS; col++){
            if(heights[col] >= row){
                printf("\x1b[38;5;%sm__\x1b[0m", colors[col % 5]);
            } else{
                printf("  ");
            }
        }
        putchar('\n');
    }

    usleep(TIME);
  }
}