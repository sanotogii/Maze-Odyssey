#include "../headers/main.h"

/**
 * updateRenderer - Updates the game renderer with the current game state.
 * @renderer: Pointer to the SDL_Renderer used for rendering the game.
 * @texture: Pointer to the SDL_Texture where the game's pixels are drawn.
 * @posX: The X position of the player in the game world.
 * @posY: The Y position of the player in the game world.
 * @dirX: The X component of the direction vector the player is facing.
 * @dirY: The Y component of the direction vector the player is facing.
 *
 * This function performs several key rendering steps to update the game's
 * visual output. It updates the texture with the current pixel buffer,
 * clears the renderer, copies the texture to the renderer, draws the mini-map,
 * and finally presents the renderer to the display. The function relies on
 * global variables such as buffer and screenWidth for texture updates and
 * mini-map rendering.
 */
void updateRenderer(SDL_Renderer *renderer, SDL_Texture *texture,
					double posX, double posY, double dirX, double dirY)
{
	SDL_UpdateTexture(texture, NULL, buffer, screenWidth * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	drawMiniMap(renderer, posX, posY, dirX, dirY);

	SDL_RenderPresent(renderer);
}

/**
 * cleanup - Frees SDL resources and quits SDL.
 * @texture: Pointer to the SDL_Texture to destroy.
 * @renderer: Pointer to the SDL_Renderer to destroy.
 * @window: Pointer to the SDL_Window to destroy.
 *
 * This function is responsible for cleaning up SDL resources at the end of
 * the program. It destroys the provided SDL_Texture, SDL_Renderer, and
 * SDL_Window, in that order, and then calls SDL_Quit() to clean up any
 * remaining SDL resources and subsystems. This function should be called
 * before the program exits to ensure proper resource management.
 */
void cleanup(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window)
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
