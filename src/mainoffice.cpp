#include "mainoffice.h"



void MainOffice::initOffice(){

    SDL_Surface* office = IMG_Load("assets/Office/Office_Inside/126.png");

    default_office=SDL_CreateTextureFromSurface(renderer,office);

    

    SDL_DestroySurface(office);
    return;
}


void MainOffice::RenderOffice(){

    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseX >= width * 0.75f && mouseX<=width) {
        if (dst.x + dst.w > width) // clamp right
            dst.x -= 5;
    }
    // pan left
    if (mouseX>=0 && mouseX <= width * 0.25f) {
        if (dst.x < 0) // clamp left
            dst.x += 5;
    }

    SDL_RenderTexture(renderer,default_office,NULL,&dst);

    return;
}