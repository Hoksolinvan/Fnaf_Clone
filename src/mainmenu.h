#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <random>
#include <algorithm>
#include <iostream>



class MainMenu{
    
    public:

    MainMenu(int width, int height,  SDL_Renderer* renderer): w(width), h(height), renderer(renderer){
        dest = {0, 0, static_cast<float>(w), (float)h};
        dest2= {0, 0, static_cast<float>(w), (float)h*2};

        init_menu(renderer);
       
    }
    ~MainMenu(){
        for(int i=0; i<4;i++){
            SDL_DestroyTexture(textures[i]);
        }
        for(int i=0; i<9;i++){
            SDL_DestroyTexture(static_textures[i]);
        }
        for(int i=0; i<15;i++){
            SDL_DestroyTexture(divided_static_texture[i]);
        }

        SDL_DestroyTexture(textTexture);
        SDL_DestroyTexture(textTexture1);
        SDL_DestroyTexture(textTexture2);
        SDL_DestroyTexture(textTexture3);
        SDL_DestroyTexture(textTexture4);
    }


    void init_menu(SDL_Renderer* renderer);
    void default_main_menu();
    void main_menu_state(int state=0, int frame=0);
    void staticTexture(int state=0);
    void divided_staticTexture(int frame);
    bool render_text();


    private:

    int w;
    int h;
    SDL_Texture* textures[4];
    SDL_Texture* static_textures[9];
    SDL_Texture* divided_static_texture[15];
    SDL_Renderer* renderer;
    SDL_Texture* textTexture;
    SDL_Texture* textTexture1;
    SDL_Texture* textTexture2;
    SDL_Texture* textTexture3;
    SDL_Texture* textTexture4;
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
    const char* divided_path[15] = {
        "assets/static_and_menu/Divided_Static/4.png",
        "assets/static_and_menu/Divided_Static/6.png",
        "assets/static_and_menu/Divided_Static/8.png",
        "assets/static_and_menu/Divided_Static/9.png",
        "assets/static_and_menu/Divided_Static/10.png",
        "assets/static_and_menu/Divided_Static/21.png",
        "assets/static_and_menu/Divided_Static/22.png",
        "assets/static_and_menu/Divided_Static/25.png",
        "assets/static_and_menu/Divided_Static/430.png",
        "assets/static_and_menu/Divided_Static/434.png",
        "assets/static_and_menu/Divided_Static/435.png",
        "assets/static_and_menu/Divided_Static/436.png",
        "assets/static_and_menu/Divided_Static/437.png",
        "assets/static_and_menu/Divided_Static/438.png",
        "assets/static_and_menu/Divided_Static/439.png",
    };
    SDL_FRect dest;
    SDL_FRect dest2;
    SDL_FRect dst = {100,100,450,100};
    SDL_FRect dst2 = {100,300,200,50};
    SDL_FRect dst3 = {100,400,200,50};
    SDL_FRect dst4 = {100,300,300,50};
    SDL_FRect dst5 = {100,400,300,50};
    SDL_Color color = {255,255,255,255};


};