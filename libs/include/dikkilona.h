#include <stdbool.h>

#include "SDL2/SDL.h"

#define WINDOW_TITLE "DIKKILONA"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern const bool ABORT; 
extern const bool KEEP_GOING;

typedef struct {
   float x, y;
   short life;
   char *name;
} player;


/*** setup_teardown.c ***/
void teardown(SDL_Window*, SDL_Renderer*);
void setup_window_background(SDL_Renderer*);


/*** event_handler.c ***/
int process_key_event(SDL_Window*);
