#include <stdio.h>

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
         // Rubbing the right side of the land
         if ((lx+lw > hx) && (hx+hw > lx+lw)) {
            gstate->hero.x = lx + lw;     // correcting hero's x
            hx = lx + lw;
         }

         // Rubbing the left side of the land
         else if ((hx+hw) > lx && hx < lx) {
            gstate->hero.x = lx - hw;     // correcting hero's x
            hx = lx - hw;
         }
      }

      if ((hx+hw > lx) && (lx+lw > hx)) {
         // Hitting head aganist the land (if the land is floating)
         if ((ly+lh) > hy && hy > ly) {
            gstate->hero.y = ly + lh;     // correct the y of hero

            // Reducing jump velocity on hitting wall/land
            gstate->hero.dy = 0;
         }

         // Landing on the land and not going through it
         else if ((hy+hh > ly) && hy < ly) {
            gstate->hero.y = ly-hh;    // correct y of hero

            // once we are on land, make the jump velocity to zero
            gstate->hero.dy = 0;
         }
      }
   }
}

