#include "../headers/main.h"

/**
 * getResourcePath - Constructs a full path to a resource file.
 * @filename: The name of the file to construct the path for.
 *
 * This function takes a filename and constructs a full path to the file
 * by prefixing it with a relative directory path ("pics/"). It uses a static
 * buffer to hold the constructed path, meaning the buffer is shared across
 * all calls to this function and its content is overwritten on each call.
 * The function uses snprintf to safely format the full path into the buffer.
 *
 * Return: A pointer to a static buffer containing the full path. This buffer
 * should not be modified or freed by the caller, and its content will be
 * overwritten on subsequent calls to this function.
 */

char *getResourcePath(const char *filename)
{
	static char path[1024];

	snprintf(path, sizeof(path), "pics/%s", filename);
	return (path);
}

/**
 * loadTextures - Loads images, converts them, and stores in a global array.
 *
 * Iterates over texture filenames, constructs full paths, and loads images
 * using SDL's IMG_Load. Each image is converted to SDL_PIXELFORMAT_ARGB8888
 * for consistency. Pixel data is copied into a global array for rendering.
 * On failure to load or convert an image, prints an error and exits.
 *
 * Assumes global variables `textures`, `texWidth`, and `texHeight` exist for
 * storing pixel data and texture dimensions. Requires initialized SDL and
 * SDL_image libraries.
 *
 * Note: Uses SDL_FreeSurface to avoid memory leaks from created SDL_Surface
 * objects.
 */

void loadTextures(void)
{
	SDL_Surface *img;

	const char *filenames[8] = {
		"redbrick.png", "greystone.png", "bluestone.png", "colorstone.png",
		"eagle.png", "wood.png", "mossy.png", "pillar.png"};

	for (int i = 0; i < 8; i++)
	{
		char *fullPath = getResourcePath(filenames[i]);

		img = IMG_Load(fullPath);
		if (!img)
		{
			printf("IMG_Load: %s\n", IMG_GetError());
			printf("Failed to load: %s\n", fullPath);
			exit(1);
		}
		printf("Successfully loaded: %s\n", fullPath);

		SDL_Surface *convertedSurface = SDL_ConvertSurfaceFormat(img,
												SDL_PIXELFORMAT_ARGB8888, 0);

		if (!convertedSurface)
		{
			printf("SDL_ConvertSurfaceFormat: %s\n", SDL_GetError());
			exit(1);
		}

		for (int y = 0; y < texHeight; y++)
		{
			for (int x = 0; x < texWidth; x++)
			{
				Uint32 pixel = ((Uint32 *)convertedSurface->pixels)[y * texWidth + x];

				textures[i][y * texWidth + x] = pixel;
			}
		}
		SDL_FreeSurface(convertedSurface);
		SDL_FreeSurface(img);
	}
}
