#include "SDL2/SDL.h"

#include "include/dikkilona.h"


int process_key_event(game_state *gstate) {
  /* To process any keyboard keys are pressed.
   * 
   * Expected events,
   * 1. Click x button in window
   * 2. Pressing ESC key
   * 3. Navigation keys(up, down, right, left)
   */
   SDL_Event key_event;

   while (SDL_PollEvent(&key_event)) {
      switch (key_event.type) {
         case SDL_WINDOWEVENT_CLOSE:
            // 1. CHECK FOR X CLOSE BUTTON CLICKED
            if (gstate->window) {
               SDL_DestroyWindow(gstate->window);
               gstate->window = NULL;
               return ABORT;
            }
            break;

         case SDL_KEYDOWN:
            // 2. CHECK FOR KEY PRESS
            switch (key_event.key.keysym.sym) {
               // 2.1 ESC key
               case SDLK_ESCAPE:
                  return ABORT;

               // 2.2 Navigation keys
               case SDLK_RIGHT:
                  gstate->hero.x += 10;
                  break;

               case SDLK_LEFT:
                  gstate->hero.x -= 10;
                  break;

               case SDLK_UP:
                  gstate->hero.y -= 10;
                  break;

               case SDLK_DOWN:
                  gstate->hero.y += 10;
                  break;
            }
            break;

         case SDL_QUIT:
            // 3. TERMINATE
            return ABORT;
      }
   }

   return KEEP_GOING;
}
