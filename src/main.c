#include <stdio.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../libs/include/dikkilona.h"


int main(int argc, char* argv[]) {
    bool status = KEEP_GOING;

   game_state gstate;

   // Initialize SDL2
   SDL_Init(SDL_INIT_VIDEO);

   gstate.hero.x = 50;
   gstate.hero.y = 50;

   initialize_window_renderer(&gstate);

   /* GAME LOOP */
   while (status) {
      // retrieve game status for each loop
      status = process_key_event(&gstate);

      // Apply background color to window
      setup_window_background(&gstate);

      load_texture(&gstate);

      // Render a player
      SDL_Rect pos = {gstate.hero.x, gstate.hero.y, 45, 65};     // (Posx, Posy, dimX, dimY)
      SDL_RenderCopy(gstate.render, gstate.ch, NULL, &pos);

      // Update the renderer for displaying the present changes
      SDL_RenderPresent(gstate.render);
   }
   
   // Cleaning up window and renderer
   SDL_DestroyTexture(gstate.ch);
   teardown(&gstate);


   return 0;   
}
