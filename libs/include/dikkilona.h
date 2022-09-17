#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define WINDOW_TITLE "Dikkilona"
#define WWINDOW 1000
#define HWINDOW 480

#define WHERO 45
#define HHERO 65
#define WLAWN 415
#define HLAWN 75

extern const short BACKGROUND[4];    // RBG-Alpha color for background
extern const bool ABORT; 
extern const bool KEEP_GOING;


/* Player: Hero */
typedef struct {
   float x, y, dy;
   float w, h;
   short life;
   char *name;
} player;

/* Non-Players: Antagonist */
typedef struct {
   float x, y;
} nplayer;

/* Structures: landscape */
typedef struct {
   float x, y, w, h;
} landscape;


/* Holds all data about the game's current state */
typedef struct {
   SDL_Window* window;
   SDL_Renderer* render;

   // Image Textures
   SDL_Texture* hero_texture[2];
   SDL_Texture* lawn_texture;

   // Main player stats
   player hero;

   // Non-Player stats

   // Structures stats
   landscape lawn[100];
} game_state;



/*** setup_teardown.c ***/
void initialize_window_renderer(game_state*);
void render_window_background_color(game_state*);
void load_all_textures(game_state*);
void render_landscapes(game_state*);
void render_player(game_state*);
void teardown(game_state*);

/*** event_handler.c ***/
int process_key_event(game_state*);

/*** game_physics.c ***/
void detect_collision(game_state*);
void put_in_gravity(game_state*); 
