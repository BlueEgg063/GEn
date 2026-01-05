#include <gen/tools.h>
#include <gen/window.h>
uint32_t GEn_RGB(uint32_t rgb, SDL_PixelFormat* format){
    return SDL_MapRGB(format,((rgb>>16)&0xFF), ((rgb>>8)&0xFF), (rgb & 0xFF));
}