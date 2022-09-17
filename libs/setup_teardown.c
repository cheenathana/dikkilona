#include <stdbool.h>
#include <stdio.h>

#include "SDL2/SDL.h"

#include "include/dikkilona.h"
#include "SDL2/SDL_image.h"

const short BACKGROUND[4] = {135, 206, 250, 255};  // RBG-Alpha for skyblue
const bool ABORT = false;
const bool KEEP_GOING = true;


void initialize_window_renderer(game_state* gstate) {
   // Defining properties for window
   gstate->window = SDL_CreateWindow(
         WINDOW_TITLE,
         SDL_WINDOWPOS_UNDEFINED,      // initial x position
         SDL_WINDOWPOS_UNDEFINED,      // initial y position
         WWINDOW,                      // window width in pixels
         HWINDOW,                     // window height in pixels
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

void load_all_textures(game_state* gstate) {
   // HERO IMAGE
   SDL_Surface* surface1 = IMG_Load("assests/img/player/hero_idle1.png");

   // NON-PLAYER IMAGE

   // STRUCTURE IMAGE
   SDL_Surface* surface2 = IMG_Load("assests/img/structure/lawn.png");

   // Validating if textures are loaded successfully
   if (surface1 == NULL || surface2 == NULL) {
      printf("*** FATAL: IMAGE RESOURCE NOT LOADED ***\n");
      SDL_Quit();
      exit(1);
   }

   // Generating resource texture from the texture
   gstate->hero_texture[0] = SDL_CreateTextureFromSurface(gstate->render, surface1);
   gstate->lawn_texture = SDL_CreateTextureFromSurface(gstate->render, surface2);

   // Clearing up surfaces
   SDL_FreeSurface(surface1);
   SDL_FreeSurface(surface2);
}

void render_window_background_color(game_state* gstate) {
   SDL_SetRenderDrawColor(
         gstate->render, 
         BACKGROUND[0], 
         BACKGROUND[1], 
         BACKGROUND[2], 
         BACKGROUND[3]
      );
   SDL_RenderClear(gstate->render);
}

void render_landscapes(game_state* gstate) {
   for (int i = 0; i < 100; i++) {
      gstate->lawn[i].w = WLAWN;
      gstate->lawn[i].h = HLAWN;
      gstate->lawn[i].x = (i * WLAWN);
      gstate->lawn[i].y = HWINDOW - HLAWN;

      // (X-pos, Y-pos, Width, Height)
      SDL_Rect gpos = {gstate->lawn[i].x, gstate->lawn[i].y, 
                       gstate->lawn[i].w, gstate->lawn[i].h};
      SDL_RenderCopy(gstate->render, gstate->lawn_texture, NULL, &gpos);
   }
}

void render_player(game_state* gstate) {
   // poxitionX, positionY, dimensionW, dimensionH
   SDL_Rect pos = {gstate->hero.x, gstate->hero.y, WHERO, HHERO};
   SDL_RenderCopyEx(gstate->render, gstate->hero_texture[0], NULL, &pos, 0, NULL, 0);
}

void teardown(game_state* gstate) {
   // Destroying textures
   SDL_DestroyTexture(gstate->hero_texture[0]);
   SDL_DestroyTexture(gstate->lawn_texture);
   
   SDL_DestroyWindow(gstate->window);
   SDL_DestroyRenderer(gstate->render);

   SDL_Quit();
}
