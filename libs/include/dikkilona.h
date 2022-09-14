#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define WINDOW_TITLE "Dikkilona"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

extern const short BACKGROUND[4];    // RBG-Alpha color for background

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
} nplayer;

typedef struct {
   /* Structures: land */
   float x, y, w, h;
} land;


typedef struct {
   /* Holds all data about the game's current state */
   SDL_Window* window;
   SDL_Renderer* render;

   // Image Textures
   SDL_Texture* hero_texture[2];
   SDL_Texture* grassland_texture;

   // Main player stats
   player hero;

   // Non-Player stats

   // Structures stats
   land grassland[100];
} game_state;


/*** setup_teardown.c ***/
void initialize_window_renderer(game_state*);
void render_window_background_color(game_state*);
void load_all_textures(game_state*);
void render_land(game_state*);
void render_player(game_state*);
void teardown(game_state*);

/*** event_handler.c ***/
int process_key_event(game_state*);
