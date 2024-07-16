#include "../headers/main.h"

/**
 * drawMiniMap - Renders a mini-map for the game.
 * @renderer: Pointer to the SDL_Renderer to draw on.
 * @posX: The X position of the player.
 * @posY: The Y position of the player.
 * @dirX: The X direction the player is facing.
 * @dirY: The Y direction the player is facing.
 *
 * This function checks if the mini-map should be displayed. If so, it iterates
 * over the game's map array, drawing each cell as either a grey square for
 * empty space or a white square for walls, using the provided renderer.
 * It then draws the player as a red square on the mini-map at their
 * current position,
 * and a line indicating the direction the player is facing.
 *
 * The function uses several constants: MAP_OFFSET to adjust the
 * position of the mini-map on the screen, MAP_SCALE to scale the map's size,
 * and the global
 * variable showMap to determine if the mini-map should be displayed.
 */
int showMap = 0;

void drawMiniMap(SDL_Renderer *renderer, double posX, double posY,
				 double dirX, double dirY)
{
	if (!showMap)
		return;

	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			SDL_Rect mapRect = {
				MAP_OFFSET + x * MAP_SCALE,
				MAP_OFFSET + y * MAP_SCALE,
				MAP_SCALE,
				MAP_SCALE};

			if (worldMap[x][y] == 0)
				/*grey for empty space*/
				SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
			else
				/*white for walls*/
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			SDL_RenderFillRect(renderer, &mapRect);
		}
	}

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect playerRect = {
		MAP_OFFSET + (int)(posX * MAP_SCALE) - 2,
		MAP_OFFSET + (int)(posY * MAP_SCALE) - 2,
		4,
		4};
	SDL_RenderFillRect(renderer, &playerRect);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer,
					   MAP_OFFSET + (int)(posX * MAP_SCALE),
					   MAP_OFFSET + (int)(posY * MAP_SCALE),
					   MAP_OFFSET + (int)((posX + dirX * 2) * MAP_SCALE),
					   MAP_OFFSET + (int)((posY + dirY * 2) * MAP_SCALE));
}
