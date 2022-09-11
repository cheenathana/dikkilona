#include <stdbool.h>

#include "SDL2/SDL.h"

#include "include/dikkilona.h"
#include "SDL2/SDL_image.h"

const bool ABORT = false;
const bool KEEP_GOING = true;

void setup_window_background(game_state* gstate) {
   SDL_SetRenderDrawColor(gstate->render, 0, 255, 0, 255);  // R, B, G, Alpha
   SDL_RenderClear(gstate->render);
}

void teardown(game_state* gstate) {
   SDL_DestroyWindow(gstate->window);
   SDL_DestroyRenderer(gstate->render);

   SDL_Quit();
}
