#include <stdio.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../libs/include/dikkilona.h"


int main(int argc, char* argv[]) {
   SDL_Window *window;
   SDL_Renderer *render;

   // Initialide SDL2
   SDL_Init(SDL_INIT_VIDEO);

   // Initialize window and renderer
   initialize_window_renderer(window, render);

   // Apply background color to window
   setup_window_background(render);

   SDL_RenderPresent(render);

   SDL_Delay(2000);

   teardown(window, render);


   return 0;   
}
