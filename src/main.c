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
      // retrieve game status for each loop
      status = process_key_event(&gstate);

      // Apply background color to window
      render_window_background_color(&gstate);

      // Render a player
      SDL_Rect pos = {gstate.hero.x, gstate.hero.y, 45, 65};     // (Posx, Posy, dimX, dimY)
      SDL_RenderCopy(gstate.render, gstate.hero_texture[0], NULL, &pos);

      // Render the grass land for the player to walk
      render_land(&gstate);

      // Update the renderer for displaying the present changes
      SDL_RenderPresent(gstate.render);
   }
   
   // Cleaning up window and renderer
   SDL_DestroyTexture(gstate.hero_texture[0]);
   SDL_DestroyTexture(gstate.grassland_texture);
   teardown(&gstate);


   return 0;   
}
