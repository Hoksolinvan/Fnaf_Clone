#include "mainoffice.h"



void MainOffice::initOffice(){

    const char* path_two[4]={
        "assets/Office/Door_Lights/L_Light/122.png",
        "assets/Office/Door_Lights/L_Light/image2_nobg.png",
        "assets/Office/Door_Lights/L_Light/image3_nobg.png",
        "assets/Office/Door_Lights/L_Light/image4_nobg.png",

    };

    const char* path_three[4]={
        "assets/Office/Door_Lights/R_Light/134.png",
        "assets/Office/Door_Lights/R_Light/47.png",
        "assets/Office/Door_Lights/R_Light/131.png",
        "assets/Office/Door_Lights/R_Light/135.png",

    };

    const char* path[3] = {
        "assets/Office/Fan/57.png",
        "assets/Office/Fan/59.png",
        "assets/Office/Fan/60.png",
    };


    SDL_Surface* office = IMG_Load("assets/Office/Office_Inside/126.png");
    default_office=SDL_CreateTextureFromSurface(renderer,office);
    SDL_DestroySurface(office);

    

    for(int i=0; i<3;i++){
        SDL_Surface* fan = IMG_Load(path[i]);
        Fan[i]=SDL_CreateTextureFromSurface(renderer,fan);
        SDL_DestroySurface(fan);
    }

    
    for(int i=0; i<4;i++){
        SDL_Surface* temp_surface = IMG_Load(path_two[i]);
        leftDoorButton[i]=SDL_CreateTextureFromSurface(renderer,temp_surface);
        SDL_DestroySurface(temp_surface);
    }

    for(int i=0; i<4;i++){
        SDL_Surface* temp_surface = IMG_Load(path_three[i]);
        rightDoorButton[i]=SDL_CreateTextureFromSurface(renderer,temp_surface);
        SDL_DestroySurface(temp_surface);
    }
    

    return;
}


void MainOffice::RenderOffice(bool screen_camera){

    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseX >= width * 0.75f && mouseX<=width) {
        if (dst.x + dst.w > width){// clamp right
            dst.x -= 5;
            leftdst.x-=5;
            cameradst.x-=5;
            rightdst.x-=5;
        }
    }
    // pan left
    if (mouseX>=0 && mouseX <= width * 0.25f) {
        if (dst.x < 0) {// clamp left
            dst.x += 5;
            leftdst.x+=5;
            cameradst.x+=5;
        rightdst.x+=5;}
    }



    if(!screen_camera){
   SDL_RenderTexture(renderer,default_office,NULL,&dst);

   
    Uint32 elapsed = SDL_GetTicks() - animStartFrame;
    animFrame = elapsed / delayPerItem;
    SDL_RenderTexture(renderer, Fan[animFrame%3], NULL, &cameradst);

  
SDL_RenderTexture(renderer, leftDoorButton[0], NULL, &leftdst);
    SDL_RenderTexture(renderer,rightDoorButton[0],NULL,&rightdst);


    }
    

    

    return;
}


void MainOffice::RenderCamera(){




    return;
}