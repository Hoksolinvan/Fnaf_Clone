#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <random>
#include <algorithm>
#include <iostream>



class MainMenu{
    
    public:

    MainMenu(int width, int height,  SDL_Renderer* renderer): w(width), h(height), renderer(renderer){
        init_menu(renderer);
    }
    ~MainMenu(){
    }


    void init_menu(SDL_Renderer* renderer);
    void default_main_menu();
    void main_menu_state(int state=0, int frame=0);
    void staticTexture(int state=0);

    private:

    int w;
    int h;
    SDL_Texture* textures[4];
    SDL_Texture* static_textures[9];
    SDL_Renderer* renderer;
    const char* path[9]= {
        "assets/static_and_menu/Full_Static/12.png",
        "assets/static_and_menu/Full_Static/13.png",
        "assets/static_and_menu/Full_Static/14.png",
        "assets/static_and_menu/Full_Static/15.png",
        "assets/static_and_menu/Full_Static/16.png",
        "assets/static_and_menu/Full_Static/17.png",
        "assets/static_and_menu/Full_Static/18.png",
        "assets/static_and_menu/Full_Static/19.png",
        "assets/static_and_menu/Full_Static/20.png"
    };
    SDL_FRect dest = {0, 0, static_cast<float>(w*1.5), (float)h};

};