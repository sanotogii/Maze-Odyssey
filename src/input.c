#include "../headers/main.h"

/**
 * handleInput - Processes user input for movement and rotation.
 * @posX: Pointer to the player's X position.
 * @posY: Pointer to the player's Y position.
 * @dirX: Pointer to the X component of the player's direction vector.
 * @dirY: Pointer to the Y component of the player's direction vector.
 * @planeX: Pointer to the X component of the player's camera plane.
 * @planeY: Pointer to the Y component of the player's camera plane.
 * @frameTime: The time elapsed since the last frame,
 * used to calculate movement speed.
 *
 * Description: This function handles keyboard input for moving forward (W),
 *              moving backward (S), and rotating left/right (A/D). It checks
 *              collision with the world map to prevent moving through walls.
 *              It also toggles the map view on and off with the M key,
 *				debouncing
 *              the key press to prevent rapid toggling.
 */
void handleInput(double *posX, double *posY, double *dirX, double *dirY,
				 double *planeX, double *planeY, double frameTime)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	double moveSpeed = frameTime * 3.0;
	double rotSpeed = frameTime * 2.5;

	if (state[SDL_SCANCODE_W])
	{
		if (worldMap[(int)(*posX + *dirX * moveSpeed)][(int)*posY] == 0)
			*posX += *dirX * moveSpeed;
		if (worldMap[(int)*posX][(int)(*posY + *dirY * moveSpeed)] == 0)
			*posY += *dirY * moveSpeed;
	}
	if (state[SDL_SCANCODE_S])
	{
		if (worldMap[(int)(*posX - *dirX * moveSpeed)][(int)*posY] == 0)
			*posX -= *dirX * moveSpeed;
		if (worldMap[(int)*posX][(int)(*posY - *dirY * moveSpeed)] == 0)
			*posY -= *dirY * moveSpeed;
	}
	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_A])
	{
		double oldDirX = *dirX;
		double oldPlaneX = *planeX;
		double angle = (state[SDL_SCANCODE_D]) ? -rotSpeed : rotSpeed;
		*dirX = *dirX * cos(angle) - *dirY * sin(angle);
		*dirY = oldDirX * sin(angle) + *dirY * cos(angle);
		*planeX = *planeX * cos(angle) - *planeY * sin(angle);
		*planeY = oldPlaneX * sin(angle) + *planeY * cos(angle);
	}

	if (state[SDL_SCANCODE_M])
		showMap = !showMap;
}
