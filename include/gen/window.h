#pragma once

#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// Initialize everything
void GEn_init(void);

// Creates an SDL window with the specified name
// Returns a pointer to the SDL_Window or NULL on error
SDL_Window* GEn_createWindow(const char* name);

// Creates a buffer for the window’s surface
// Returns a pointer to SDL_Surface or NULL on error
SDL_Surface* GEn_createBuffer(SDL_Window* window);

// Fills the provided buffer with the given RGB color
// Returns 0 on success, -1 on failure (invalid buffer or color)
int GEn_fillBuffer(SDL_Surface* buffer, uint32_t rgb);

// Updates the window surface
void GEn_updateScreen(SDL_Window* window);

// Enters a loop that keeps the window open until the user quits
void GEn_hangLoop(void);

// Destroys the SDL window and cleans up associated resources
void GEn_destroyWindow(SDL_Window* window);

// Quits SDL and cleans up all resources
void GEn_quit(void);
