#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define WINDOW_TITLE "DIKKILONA"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern const bool ABORT; 
extern const bool KEEP_GOING;

typedef struct {
   /* Player: Hero */
   float x, y;
   short life;
   char *name;
} player;

typedef struct {
   /* Non-Players 01: Antagonist */
   float x, y;
} np_foe;

typedef struct {
   /* Structures: land */
   float x, y;
} grass_land;

typedef struct {
   player hero;
} game_state;


/*** setup_teardown.c ***/
void teardown(SDL_Window*, SDL_Renderer*);
void setup_window_background(SDL_Renderer*);

/*** event_handler.c ***/
int process_key_event(SDL_Window*, game_state*);
