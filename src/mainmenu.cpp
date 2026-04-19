#include "mainmenu.h"

void MainMenu::init_menu(SDL_Renderer* renderer){

    SDL_Surface* surface = IMG_Load("assets/static_and_menu/Menu/431.png");
    SDL_Surface* surface2 = IMG_Load("assets/static_and_menu/Menu/440.png");
    SDL_Surface* surface3 = IMG_Load("assets/static_and_menu/Menu/441.png");
    SDL_Surface* surface4 = IMG_Load("assets/static_and_menu/Menu/442.png");

    textures[0]= SDL_CreateTextureFromSurface(renderer, surface);
    textures[1]=SDL_CreateTextureFromSurface(renderer, surface2);
    textures[2]=SDL_CreateTextureFromSurface(renderer, surface3);
    textures[3]=SDL_CreateTextureFromSurface(renderer, surface4);

        
    SDL_DestroySurface(surface);
    SDL_DestroySurface(surface2);
    SDL_DestroySurface(surface3);
    SDL_DestroySurface(surface4);



   

    for(int i=0; i<9;i++){
        SDL_Surface* temp_texture = IMG_Load(path[i]);
        static_textures[i]=SDL_CreateTextureFromSurface(renderer,temp_texture);
       SDL_SetTextureAlphaMod(static_textures[i], 50);

        SDL_DestroySurface(temp_texture);
    }


    return;
}


void MainMenu::default_main_menu() {
    SDL_RenderTexture(renderer, textures[0], NULL, &dest);
    return;
}

void MainMenu::main_menu_state(int state,int frame){


    switch(state){
                    case 1:
                    if(frame<=400){
                        SDL_RenderTexture(this->renderer, this->textures[1], NULL, &dest);
                    }
                    else if(frame <=500){
                        SDL_RenderTexture(this->renderer, this->textures[2], NULL, &dest);
                    }
                    else if(frame<=700){
                        SDL_RenderTexture(this->renderer, this->textures[1], NULL, &dest);
                    }
                    else if(frame<=900){
                        SDL_RenderTexture(this->renderer, this->textures[0], NULL,&dest);
                    }
                    break;

                    case 2:
                    if(frame<=100){
                        SDL_RenderTexture(this->renderer, this->textures[0], NULL, &dest);
                    }
                    else if(frame <=200){
                        SDL_RenderTexture(this->renderer, this->textures[3], NULL,&dest);
                    }
                    else if(frame <=300){
                        SDL_RenderTexture(this->renderer, this->textures[0], NULL, &dest);
                    }
                    else if(frame <=400){
                        SDL_RenderTexture(this->renderer, this->textures[3], NULL, &dest);
                    }
                    else if(frame <=500){
                        SDL_RenderTexture(this->renderer, this->textures[2], NULL, &dest);
                    }
                    else if(frame <=900){
                        SDL_RenderTexture(this->renderer, this->textures[0], NULL, &dest);
                    }   
                    break;

                    case 3:
                    if(frame <=400){
                        SDL_RenderTexture(this->renderer, this->textures[3], NULL,&dest);
                    }
                    else if(frame<=700){
                        SDL_RenderTexture(this->renderer, this->textures[0], NULL, &dest);
                    }
                    else if(frame<=900){
                        SDL_RenderTexture(this->renderer, this->textures[1], NULL, &dest);
                    }
                    break;
                    default:
                    SDL_RenderTexture(this->renderer, this->textures[0], NULL, &dest);
                    break;



                }

    return;
}


void MainMenu::staticTexture(int state){

    SDL_RenderTexture(this->renderer, static_textures[state], NULL, &dest);

    return;
}