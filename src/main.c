#include <stdio.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../libs/include/dikkilona.h"


int main(int argc, char* argv[]) {
   int status = KEEP_GOING;

   SDL_Window *window;
   SDL_Renderer *render;

   // Initialide SDL2
   SDL_Init(SDL_INIT_VIDEO);

   // Defining properties for window
   window = SDL_CreateWindow(WINDOW_TITLE,
         SDL_WINDOWPOS_UNDEFINED,      // initial x position
         SDL_WINDOWPOS_UNDEFINED,      // initial y position
         WINDOW_WIDTH,                 // window width in pixels
         WINDOW_HEIGHT,                // window height in pixels
         0                             // flags
      );

   // Initialie a renderer for the above window
   render = SDL_CreateRenderer(
         window,
         -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
      );


   /* GAME LOOP */
   while (status) {
      // retrieve game status for each loop
      status = process_key_event(window);

      // Apply background color to window
      setup_window_background(render);

      // Update the renderer for displaying the present changes
      SDL_RenderPresent(render);
   }
   
   // Cleaning up window and renderer
   teardown(window, render);


   return 0;   
}
