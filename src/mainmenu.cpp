#include "mainmenu.h"

void MainMenu::init_menu(SDL_Renderer* renderer){

   
    TTF_Font *font = TTF_OpenFont("external/textfiles/consolas.ttf",64);
    if(!(font)){
        std::cerr << SDL_GetError() << "\n";
    }


    SDL_Surface* textSurface = TTF_RenderText_Blended(
        font,
        "Five Night's At Freddy",
        0,
        color
    );

    SDL_Surface* textSurface2 = TTF_RenderText_Blended(
        font,
        "New Game",
        0,
        color
    );

    SDL_Surface* textSurface3 = TTF_RenderText_Blended(
        font,
        "Continue",
        0,
        color
    );

    SDL_Surface* textSurface4 = TTF_RenderText_Blended(
        font,
        ">> New Game",
        0,
        color
    );

    SDL_Surface* textSurface5 = TTF_RenderText_Blended(
        font,
        ">> Continue",
        0,
        color
    );

    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    textTexture1 = SDL_CreateTextureFromSurface(renderer,textSurface2);
    textTexture2 = SDL_CreateTextureFromSurface(renderer,textSurface3);
    textTexture3 = SDL_CreateTextureFromSurface(renderer,textSurface4);
    textTexture4 = SDL_CreateTextureFromSurface(renderer,textSurface5);
    
    TTF_CloseFont(font);
    SDL_DestroySurface(textSurface);
    SDL_DestroySurface(textSurface2);
    SDL_DestroySurface(textSurface3);
    SDL_DestroySurface(textSurface4);
    SDL_DestroySurface(textSurface5);

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



   
    // regular static
    for(int i=0; i<9;i++){
        SDL_Surface* temp_texture = IMG_Load(path[i]);
        static_textures[i]=SDL_CreateTextureFromSurface(renderer,temp_texture);
       SDL_SetTextureAlphaMod(static_textures[i], 50);

        SDL_DestroySurface(temp_texture);
    }

    // divided static
    for(int i=0; i<15; i++){
        SDL_Surface* temp_surface = IMG_Load(divided_path[i]);
        divided_static_texture[i]=SDL_CreateTextureFromSurface(renderer,temp_surface);
        SDL_SetTextureAlphaMod(divided_static_texture[i], 50);


        SDL_DestroySurface(temp_surface);
    }


    return;
}


bool MainMenu::render_text(){

    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

  

    SDL_RenderTexture(renderer,textTexture,NULL, &dst);

    if((mouseX>=dst2.x && mouseX<=dst2.x+dst.w && mouseY>=dst2.y && mouseY<=dst2.y+dst2.h)){
        SDL_RenderTexture(renderer,textTexture3, NULL, &dst4);
    }
    else{
       SDL_RenderTexture(renderer,textTexture1, NULL, &dst2);
    }
    if((mouseX>=dst3.x && mouseX<=dst3.x+dst.w && mouseY>=dst3.y && mouseY<=dst3.y+dst3.h)){
    
     SDL_RenderTexture(renderer,textTexture4, NULL, &dst5);
    }
    else{
       SDL_RenderTexture(renderer,textTexture2, NULL, &dst3);
    }
   


    return false;
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

void MainMenu::divided_staticTexture(int frame){

    int index = (frame / 50) % 15;
   
    SDL_RenderTexture(this->renderer, divided_static_texture[index], NULL, &dest2);
    

    return;
}