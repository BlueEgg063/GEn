#include <gen/window.h>
#include <gen/tools.h>
//GEn_init and GEn_quit are called automatically
void __attribute__((destructor)) GEn_quit(){
    IMG_Quit();
    SDL_Quit();
    return;
}
int GEn_fillBuffer(SDL_Surface* buffer, uint32_t rgb){
        if (rgb > 0xFFFFFF || !buffer){
            return -1;
        }
        else{
        SDL_FillRect(buffer,NULL , GEn_RGB(rgb, buffer->format));
        return 0;
        }
    }
//must call this to see stuff everytime you add new things
void GEn_updateScreen(SDL_Window* window){
SDL_UpdateWindowSurface(window);
return;
}
void __attribute__((constructor)) GEn_init(){
SDL_Init(SDL_INIT_VIDEO);
IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}
//creates a window, and gives you a pointer to it, so call it as a definition to a variable(ex: 
SDL_Window* GEn_createWindow(const char* name){
SDL_Window* window = NULL;
    window = SDL_CreateWindow(
    name,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    0, 0,
    SDL_WINDOW_FULLSCREEN_DESKTOP
);

    if (window == NULL){
        printf("Window Init Failed! SDL error: %s\n", SDL_GetError());
        return NULL;
    }
    else{
        return window;
        }
    }
SDL_Surface* GEn_createBuffer(SDL_Window* window){
    if (!window) return NULL;
    SDL_Surface* buffer;
    buffer = SDL_GetWindowSurface(window);
    if (buffer == NULL){
        return NULL;
    }
    else{
        GEn_fillBuffer(buffer, 0xFFFFFF);
        GEn_updateScreen(window);
        return buffer;
    }
}
void GEn_hangLoop(){
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
        SDL_Delay(10);
    }
    return;
}
void GEn_destroyWindow(SDL_Window* window){
    SDL_DestroyWindow(window);
    return;
}
