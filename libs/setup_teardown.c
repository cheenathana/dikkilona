#include <stdbool.h>

#include "SDL2/SDL.h"

#include "include/dikkilona.h"
#include "SDL2/SDL_image.h"

const bool ABORT = false;
const bool KEEP_GOING = true;


void initialize_window_renderer(game_state* gstate) {
   // Defining properties for window
   gstate->window = SDL_CreateWindow(
         WINDOW_TITLE,
         SDL_WINDOWPOS_UNDEFINED,      // initial x position
         SDL_WINDOWPOS_UNDEFINED,      // initial y position
         WINDOW_WIDTH,                 // window width in pixels
         WINDOW_HEIGHT,                // window height in pixels
         0                             // flags
      );

   // Initialize a renderer for the above window
   // VSYNC - make the frames per second sync with screen refresh rate 
   //         so screen tearing will not occur
   gstate->render = SDL_CreateRenderer(
         gstate->window,
         -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
      );
}

void setup_window_background(game_state* gstate) {
   SDL_SetRenderDrawColor(gstate->render, 0, 255, 0, 255);  // R, B, G, Alpha
   SDL_RenderClear(gstate->render);
}

void load_texture(game_state* gstate) {
   // Loading a image
   SDL_Surface* surface = IMG_Load("assests/img/player/idle1.png");

   if (surface == NULL) {
      printf("FATAL: IMAGE RESOURCE NOT LOADED\n");
      SDL_Quit();
      exit(1);
   }

   // Generating a resource texture from Surface
   gstate->ch = SDL_CreateTextureFromSurface(gstate->render, surface);
   SDL_FreeSurface(surface);
}


void teardown(game_state* gstate) {
   SDL_DestroyWindow(gstate->window);
   SDL_DestroyRenderer(gstate->render);

   SDL_Quit();
}
