#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <random>
#include <algorithm>
#include <iostream>

class MainOffice{

    public:

    MainOffice(int width, int height, SDL_Renderer* renderer): width(width), height(height),renderer(renderer){
        dst = {0,0,static_cast<float>(width*1.5),(float)height};
        initOffice();

    }

    void initOffice();
    void RenderOffice();




    private:
    SDL_Renderer* renderer;
    SDL_Texture* default_office;
    int width;
    int height;
    SDL_FRect dst;

};