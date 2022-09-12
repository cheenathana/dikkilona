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
   /* Non-Players: Antagonist */
   float x, y;
} np_foe;

typedef struct {
   /* Structures: land */
   float x, y;
} land;


typedef struct {
   /* Holds all data about the game's current state */
   SDL_Window* window;
   SDL_Renderer* render;

   // Image Textures
   SDL_Texture* sprite_hero[2];
   SDL_Texture* grassyland;

   // Main player stats
   player hero;

   // Non-Player stats

   // Structures stats
   land grassy_land[100];
} game_state;


/*** setup_teardown.c ***/
void initialize_window_renderer(game_state*);
void setup_window_background(game_state*);
void teardown(game_state*);

/*** event_handler.c ***/
int process_key_event(game_state*);
