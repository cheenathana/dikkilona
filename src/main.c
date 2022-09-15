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

   load_all_textures(&gstate);

   /* GAME LOOP */
   while (status) {
      // retrieve game status & key events for each loop
      status = process_key_event(&gstate);

      // Apply background color to window
      render_window_background_color(&gstate);

      // Render the grass land for the player to walk
      render_land(&gstate);

      // Render the player
      render_player(&gstate);

      // Update the renderer for displaying the present changes
      SDL_RenderPresent(gstate.render);
   }
   
   // Cleaning up textures, window & renderer
   teardown(&gstate);

   return 0;   
}
