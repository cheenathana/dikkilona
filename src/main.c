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
   gstate.grassy_land[0].x = 100;
   gstate.grassy_land[0].y = 100;

   initialize_window_renderer(&gstate);

   SDL_Surface* surface1 = IMG_Load("assests/img/player/idle1.png");
   SDL_Surface* surface2 = IMG_Load("assests/img/structure/land_long.png");

   if (surface1 == NULL || surface2 == NULL) {
      printf("FATAL: IMAGE RESOURCE NOT LOADED\n");
      SDL_Quit();
      exit(1);
   }

   // Generating resource texture from the surface
   gstate.sprite_hero[0] = SDL_CreateTextureFromSurface(gstate.render, surface1);
   gstate.grassyland = SDL_CreateTextureFromSurface(gstate.render, surface2);
   SDL_FreeSurface(surface1);
   SDL_FreeSurface(surface2);



   /* GAME LOOP */
   while (status) {
      // retrieve game status for each loop
      status = process_key_event(&gstate);

      // Apply background color to window
      setup_window_background(&gstate);

      // Render a player
      SDL_Rect pos = {gstate.hero.x, gstate.hero.y, 45, 65};     // (Posx, Posy, dimX, dimY)
      SDL_RenderCopy(gstate.render, gstate.sprite_hero[0], NULL, &pos);

      SDL_Rect gpos = {gstate.grassy_land[0].x, gstate.grassy_land[0].y, 400, 80}; // (Posx, Posy, dimX, dimY)
      SDL_RenderCopy(gstate.render, gstate.grassyland, NULL, &gpos);

      // Update the renderer for displaying the present changes
      SDL_RenderPresent(gstate.render);
   }
   
   // Cleaning up window and renderer
   SDL_DestroyTexture(gstate.sprite_hero[0]);
   teardown(&gstate);


   return 0;   
}
