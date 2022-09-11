#include <stdio.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../libs/include/dikkilona.h"


int main(int argc, char* argv[]) {
    bool status = KEEP_GOING;

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

   // Initialize a renderer for the above window
   // VSYNC - make the frames per second sync with screen refresh rate 
   //         so screen tearing will not occur
   render = SDL_CreateRenderer(
         window,
         -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
      );

   game_state gstate;
   gstate.window = window;
   gstate.render = render;
   gstate.hero.x = 50;
   gstate.hero.y = 50;

   // Loading a image
   SDL_Surface* surface = IMG_Load("assests/img/player/idle1.png");

   // creating a texture of image from surface
   SDL_Texture* playertx = SDL_CreateTextureFromSurface(render, surface);
   SDL_FreeSurface(surface);


   /* GAME LOOP */
   while (status) {
      // retrieve game status for each loop
      status = process_key_event(&gstate);

      // Apply background color to window
      setup_window_background(&gstate);

      // Render a player
      SDL_Rect pos = {gstate.hero.x, gstate.hero.y, 45, 65};     // (Posx, Posy, dimX, dimY)
      SDL_RenderCopy(render, playertx, NULL, &pos);

      // Update the renderer for displaying the present changes
      SDL_RenderPresent(gstate.render);
   }
   
   // Cleaning up window and renderer
   SDL_DestroyTexture(playertx);
   teardown(&gstate);


   return 0;   
}
