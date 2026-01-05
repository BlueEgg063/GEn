#include <gen/draw.h>
static SDL_Surface *bg_cache = NULL;
sprite* sprites[100];
int sprite_ct = 0;
int GEn_killSprites(){
    SDL_FreeSurface(bg_cache);
    bg_cache = NULL;
    for (int i = 0; i < sprite_ct; i++){
        SDL_FreeSurface(sprites[i]->pixels);
        free(sprites[i]);
        sprites[i] = NULL;
    }
    sprite_ct = 0;
    return 0;
}
int GEn_render_all(SDL_Surface* buffer){
    for (int i = 0; i < sprite_ct; i++){
        if (GEn_render_sprite(sprites[i], buffer) == -1){
            return -1;
        }
    }
    return 0;
}
sprite* GEn_create_sprite(const char* path, int h, int w, int x, int y){
sprite *Sprite = malloc(sizeof(sprite));
Sprite->h = h;
Sprite->w = w;
Sprite->x = x;
Sprite->y = y;
Sprite->pixels = IMG_Load(path);
if (Sprite->pixels == NULL){
    return NULL;
}
else {
    sprites[sprite_ct++] = Sprite;
    return Sprite;
}
}
int GEn_render_sprite(sprite* Sprite, SDL_Surface* buffer){
if (!Sprite){
    return -1;
}
SDL_Rect sprt;
sprt.x = Sprite->x;
sprt.y = Sprite->y;
sprt.h = Sprite->h;
sprt.w = Sprite->w;
if (SDL_BlitScaled(Sprite->pixels, NULL, buffer, &sprt)!=0){
    return -1;
}
else {
    return 0;
}
}
int GEn_setBG(const char *path){               
    if (path){
        SDL_FreeSurface(bg_cache);
        bg_cache = IMG_Load(path);
        if (bg_cache == NULL) return -1; else return 0;
    }         
    else{
        bg_cache = NULL;
        return 0;
    }
}
int GEn_drawBG(const char *path, SDL_Surface* buffer){
SDL_Surface* image;
if (!path && !bg_cache) return -1;
else if (bg_cache && !path){
    image = bg_cache;
}
else {if (GEn_setBG(path)) return -1; image = bg_cache;}
SDL_Rect dst;
if (!image || !buffer) return -1;
dst.x = 0;
dst.y = 0;
dst.w = buffer -> w;
dst.h = buffer -> h;
if (SDL_BlitScaled(image, NULL, buffer, &dst)!=0) return -1;
return 0;
}