#include "SDL2/SDL.h"

#include "include/dikkilona.h"

void collision_detect(game_state* gstate) {
   // Detect collision with land textures
   // We have to loop through all the land textures to check the collision
   // with the player texture
   for (int i = 0; i < 50; i++) {
      // getting position and dimension of the player
      float hx = gstate->hero.x, hy = gstate->hero.y;
      float hw = gstate->hero.w, hh = gstate->hero.h;

      // getting the position and dimension of current looping land
      float lx = gstate->grassland[i].x, ly = gstate->grassland[i].y;
      float lw = gstate->grassland[i].w, lh = gstate->grassland[i].h;

      if ((hy+hh > ly) && (ly+lh > hy)) {
         
      }
   }
}

