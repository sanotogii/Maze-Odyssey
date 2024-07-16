#include "../headers/main.h"

/**
 * initializeSDL - Initializes SDL, creates a window, renderer, and texture.
 * @window: A pointer to a pointer to the SDL_Window to be initialized.
 * @renderer: A pointer to a pointer to the SDL_Renderer to be initialized.
 * @texture: A pointer to a pointer to the SDL_Texture to be initialized.
 *
 * This function initializes the SDL library for video, checks for PNG image
 * support, and creates an SDL window, renderer, and texture with specified
 * properties. If any step fails, the function prints an error message and
 * exits the program.
 *
 * Return: void. Exits on failure.
 */

void initializeSDL(SDL_Window **window, SDL_Renderer **renderer,
					SDL_Texture **texture)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		exit(1);
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("IMG_Init Error: %s\n", IMG_GetError());
		exit(1);
	}

	*window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED, screenWidth,
								screenHeight, SDL_WINDOW_SHOWN);
	if (!*window)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		exit(1);
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (!*renderer)
	{
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		exit(1);
	}
	*texture = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_ARGB8888,
								SDL_TEXTUREACCESS_STREAMING, screenWidth,
								screenHeight);
	if (!*texture)
	{
		printf("SDL_CreateTexture Error: %s\n", SDL_GetError());
		exit(1);
	}
}
