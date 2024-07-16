#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

#define screenWidth 1000
#define screenHeight 600
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define MAP_SCALE 8
#define MAP_OFFSET 10

extern int worldMap[mapWidth][mapHeight];
extern Uint32 buffer[screenHeight][screenWidth];
extern Uint32 textures[8][texWidth * texHeight];

extern int showMap;

// Function prototypes
void draw_map(SDL_Renderer *renderer, double pos_x, double pos_y, double dir_x, double dir_y);
char* getResourcePath(const char* filename);
void loadTextures();
void performRaycasting(double posX, double posY, double dirX, double dirY, 
                       double planeX, double planeY);
void handleInput(double *posX, double *posY, double *dirX, double *dirY, 
                 double *planeX, double *planeY, double frameTime);
void updateRenderer(SDL_Renderer *renderer, SDL_Texture *texture, 
                    double posX, double posY, double dirX, double dirY);
extern void initializeSDL(SDL_Window **window, SDL_Renderer **renderer, 
                          SDL_Texture **texture);
void cleanup(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Window *window);
void drawMiniMap(SDL_Renderer *renderer, double posX, double posY, 
                 double dirX, double dirY);

#endif