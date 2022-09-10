#include "SDL2/SDL.h"

#define WINDOW_TITLE "DIKKILONA"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


void initialize_window_renderer(SDL_Window*, SDL_Renderer*);
void teardown(SDL_Window*, SDL_Renderer*);
void setup_window_background(SDL_Renderer*);
