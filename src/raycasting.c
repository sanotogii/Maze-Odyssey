#include "../headers/main.h"

/**
 * performRaycasting - Performs raycasting for each column of the screen.
 * @posX: X position of the player.
 * @posY: Y position of the player.
 * @dirX: X component of the player's direction vector.
 * @dirY: Y component of the player's direction vector.
 * @planeX: X component of the camera plane.
 * @planeY: Y component of the camera plane.
 */

void performRaycasting(double posX, double posY, double dirX, double dirY,
					   double planeX, double planeY)
{
	for (int x = 0; x < screenWidth; x++)
	{
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;

		double sideDistX, sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		int stepX, stepY, hit = 0, side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(screenHeight / perpWallDist);
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;

		int texNum = worldMap[mapX][mapY] - 1;
		double wallX;
		if (side == 0)
			wallX = posY + perpWallDist * rayDirY;
		else
			wallX = posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)(texWidth));
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		for (int y = drawStart; y < drawEnd; y++)
		{
			int d = y * 256 - screenHeight * 128 + lineHeight * 128;
			int texY = ((d * texHeight) / lineHeight) / 256;
			Uint32 color = textures[texNum][texWidth * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			buffer[y][x] = color;
		}
	}
}
