#include "mainoffice.h"


Uint32 animstart = SDL_GetTicks();
const int delay = 150;
bool leftdoorclosed = false;
bool rightdoorclosed = false;



void MainOffice::initOffice(){

    const char* path_two[4]={
        "assets/Office/Door_Lights/L_Light/122.png",
        "assets/Office/Door_Lights/L_Light/124.png",
        "assets/Office/Door_Lights/L_Light/125.png",
        "assets/Office/Door_Lights/L_Light/130.png",

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

    
    const char* office_path[7]={
        "assets/Office/Office_Inside/58.png",
        "assets/Office/Office_Inside/126.png",
        "assets/Office/Office_Inside/127.png",
        "assets/Office/Office_Inside/225.png",
        "assets/Office/Office_Inside/227.png",
        "assets/Office/Office_Inside/304.png",
        "assets/Office/Office_Inside/305.png"
        
    };

    const char* leftdoor[13]={
        "assets/Office/Door_Lights/L_Door_Frame/89.png",
        "assets/Office/Door_Lights/L_Door_Frame/91.png",
        "assets/Office/Door_Lights/L_Door_Frame/92.png",
        "assets/Office/Door_Lights/L_Door_Frame/93.png",
        "assets/Office/Door_Lights/L_Door_Frame/94.png",
        "assets/Office/Door_Lights/L_Door_Frame/95.png",
        "assets/Office/Door_Lights/L_Door_Frame/96.png",
        "assets/Office/Door_Lights/L_Door_Frame/97.png",
        "assets/Office/Door_Lights/L_Door_Frame/98.png",
        "assets/Office/Door_Lights/L_Door_Frame/99.png",
        "assets/Office/Door_Lights/L_Door_Frame/101.png",
        "assets/Office/Door_Lights/L_Door_Frame/102.png",
        "assets/Office/Door_Lights/L_Door_Frame/103.png",
    };

    const char* rightdoor[13]={
        "assets/Office/Door_Lights/R_Door_Frame/106.png",
        "assets/Office/Door_Lights/R_Door_Frame/107.png",
        "assets/Office/Door_Lights/R_Door_Frame/108.png",
        "assets/Office/Door_Lights/R_Door_Frame/109.png",
        "assets/Office/Door_Lights/R_Door_Frame/110.png",
        "assets/Office/Door_Lights/R_Door_Frame/111.png",
        "assets/Office/Door_Lights/R_Door_Frame/112.png",
        "assets/Office/Door_Lights/R_Door_Frame/113.png",
        "assets/Office/Door_Lights/R_Door_Frame/114.png",
        "assets/Office/Door_Lights/R_Door_Frame/115.png",
        "assets/Office/Door_Lights/R_Door_Frame/116.png",
        "assets/Office/Door_Lights/R_Door_Frame/117.png",
        "assets/Office/Door_Lights/R_Door_Frame/118.png"

    };

    for(int i=0; i<7; i++){
        SDL_Surface* office = IMG_Load(office_path[i]);
        
        officeTextures[i]=SDL_CreateTextureFromSurface(renderer,office);


        SDL_DestroySurface(office);
    }


    for(int i=0; i<13;i++){
        SDL_Surface* lefttemp = IMG_Load(leftdoor[i]);
        SDL_Surface* righttemp = IMG_Load(rightdoor[i]);

        leftDoorFrame[i]=SDL_CreateTextureFromSurface(renderer,lefttemp);
        rightDoorFrame[i]=SDL_CreateTextureFromSurface(renderer,righttemp);

        SDL_DestroySurface(lefttemp);
        SDL_DestroySurface(righttemp);
    }
   


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


void MainOffice::RenderOffice(bool screen_camera, bool leftdoorbottom, bool leftdoorup, bool rightdoorbottom, bool rightdoorup){

    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

   

    if (mouseX >= width * 0.75f && mouseX<=width) {
        if (dst.x + dst.w > width){// clamp right
            dst.x -= 5;
            leftdst.x-=5;
            rightdoor.x-=5;
            leftdoor.x-=5;
            cameradst.x-=5;
            rightdst.x-=5;
        }
    }
    // pan left
    if (mouseX>=0 && mouseX <= width * 0.25f) {
        if (dst.x < 0) {// clamp left
            dst.x += 5;
            leftdst.x+=5;
            rightdoor.x+=5;
            leftdoor.x+=5;
            cameradst.x+=5;
        rightdst.x+=5;}
    }



    if(!screen_camera){


    if(!leftdoorbottom && !rightdoorbottom){
   SDL_RenderTexture(renderer,officeTextures[1],NULL,&dst);

           SDL_RenderTexture(renderer,leftDoorFrame[9],NULL,&leftdoor);



    }
    else if(leftdoorbottom && !rightdoorbottom){
    

     Uint32 elapsed = SDL_GetTicks() - animstart;
    animFrame = (elapsed / delay) %2;


    
    if(animFrame>=2) {
        animFrame = 1;
    }
    SDL_RenderTexture(renderer,officeTextures[animFrame],NULL,&dst);

}
    
    else if(!leftdoorbottom && rightdoorbottom ){


    Uint32 elapsed_time = SDL_GetTicks() - animstart;
    animFrame = (elapsed_time/delay) % 2 + 1;

    if(animFrame>=2){
        animFrame=2;
    }
    SDL_RenderTexture(renderer,officeTextures[animFrame],NULL,&dst);
    }

    else if(leftdoorbottom && rightdoorbottom){
        Uint32 elapsed_time = SDL_GetTicks() - animstart;
        animFrame = (elapsed_time/delay)%1;

        if(animFrame>=2){
            animFrame=2;
        }
        SDL_RenderTexture(renderer,officeTextures[animFrame],NULL,&dst);
    }
    

    if(!leftdoorclosed && leftdoorup){
        Uint32 elapsed_time = SDL_GetTicks() - animstart;
        animFrame = (elapsed_time/delay);

        if(animFrame>12){
            animFrame=12;
            leftdoorclosed= true;
        }

        SDL_RenderTexture(renderer,leftDoorFrame[animFrame],NULL,&leftdoor);
    }
    else if(leftdoorup){
        SDL_RenderTexture(renderer,leftDoorFrame[12],NULL,&leftdoor);
    }
    // else{

    // }

    if(!rightdoorclosed && rightdoorup){
         Uint32 elapsed_time = SDL_GetTicks() - animstart;
        animFrame = (elapsed_time/delay);

        if(animFrame>12){
            animFrame=12;
            rightdoorclosed= true;
        }

        SDL_RenderTexture(renderer,rightDoorFrame[animFrame],NULL,&rightdoor);

    }
    else if(rightdoorup){
        SDL_RenderTexture(renderer,rightDoorFrame[12],NULL,&rightdoor);
    }
    

   
    Uint32 elapsed = SDL_GetTicks() - animStartFrame;
    animFrame = elapsed / delayPerItem;
    SDL_RenderTexture(renderer, Fan[animFrame%3], NULL, &cameradst);


  if(leftdoorbottom && leftdoorup){
    SDL_RenderTexture(renderer, leftDoorButton[3], NULL, &leftdst);
  }
  else if(!leftdoorbottom && leftdoorup){
    SDL_RenderTexture(renderer, leftDoorButton[1], NULL, &leftdst);
  }
  else if(leftdoorbottom && !leftdoorup){
    SDL_RenderTexture(renderer,leftDoorButton[2],NULL,&leftdst);
  }
  else{
    SDL_RenderTexture(renderer, leftDoorButton[0], NULL, &leftdst);
  }



  if(rightdoorbottom && rightdoorup){
    SDL_RenderTexture(renderer,rightDoorButton[1],NULL,&rightdst);
  }
  else if(!rightdoorbottom && rightdoorup){
    SDL_RenderTexture(renderer,rightDoorButton[3],NULL,&rightdst);
  }
  else if(rightdoorbottom && !rightdoorup){
    SDL_RenderTexture(renderer,rightDoorButton[2],NULL,&rightdst);
  }
  else{
     SDL_RenderTexture(renderer,rightDoorButton[0],NULL,&rightdst);
  }
   


    }
    

    

    return;
}


void MainOffice::RenderCamera(){




    return;
}