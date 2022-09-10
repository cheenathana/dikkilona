#include "SDL2/SDL.h"

#include "include/dikkilona.h"


void initialize_window_renderer(SDL_Window *window, SDL_Renderer *render) {
   // Defining properties for window
   window = SDL_CreateWindow(WINDOW_TITLE,
         SDL_WINDOWPOS_UNDEFINED,      // initial x position
         SDL_WINDOWPOS_UNDEFINED,      // initial y position
         WINDOW_WIDTH,                 // window width in pixels
         WINDOW_HEIGHT,                // window height in pixels
         0                             // flags
      );

   // Initialie a renderer for the above window
   render = SDL_CreateRenderer(window,
         -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
      );
}


void setup_window_background(SDL_Renderer *render) {
   SDL_SetRenderDrawColor(render, 0, 0, 255, 255);  // R, B, G, Alpha
   SDL_RenderClear(render);
}


void teardown(SDL_Window *window, SDL_Renderer *render) {
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(render);

   SDL_Quit();
}
