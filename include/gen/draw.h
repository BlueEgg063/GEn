#pragma once
#include <SDL_image.h>
#include <SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#define MODE_GRAPH 1
#define MODE_PIXEL 0
typedef struct {
    int x,y;
    int h,w;
    SDL_Surface* pixels;
} sprite;
int GEn_killSprites();
sprite* GEn_create_sprite(const char* path, int h, int w, int x, int y);
int GEn_render_sprite(sprite* Sprite, SDL_Surface* buffer);
int GEn_setBG(const char *path);
int GEn_render_all(SDL_Surface* buffer);
int GEn_drawBG(const char *path, SDL_Surface* buffer);