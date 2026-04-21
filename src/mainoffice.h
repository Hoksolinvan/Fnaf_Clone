#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <random>
#include <algorithm>
#include <iostream>

class MainOffice{

    public:

    MainOffice(int width, int height, SDL_Renderer* renderer): width(width), height(height),renderer(renderer){
        dst = {0,0,static_cast<float>(width*1.5),(float)height};
        initOffice();

    }

    ~MainOffice(){
        SDL_DestroyTexture(default_office);
    }

    void initOffice();
    void RenderOffice(bool screen_camera);
    void RenderCamera();




    private:
    SDL_Renderer* renderer;
    SDL_Texture* default_office;
    SDL_Texture* Fan[3];
    SDL_Texture* leftDoorButton[4];
    SDL_Texture* rightDoorButton[4];
    int width;
    int height;
    SDL_FRect dst;
    const int delayPerItem = 25;
    int animFrame = 0;
    Uint64 animStartFrame = SDL_GetTicks();
    bool animating =false;
    //928
    SDL_FRect cameradst={935,299,165,200};
    SDL_FRect leftdst={0,250,100,200};
    SDL_FRect rightdst={1800,250,100,200};

    

};