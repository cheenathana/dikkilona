#include <stdbool.h>

#include "SDL2/SDL.h"

#include "include/dikkilona.h"
#include "SDL2/SDL_image.h"

const bool ABORT = false;
const bool KEEP_GOING = true;

void setup_window_background(SDL_Renderer *render) {
   SDL_SetRenderDrawColor(render, 0, 255, 0, 255);  // R, B, G, Alpha
   SDL_RenderClear(render);
}

void teardown(SDL_Window *window, SDL_Renderer *render) {
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(render);

   SDL_Quit();
}
