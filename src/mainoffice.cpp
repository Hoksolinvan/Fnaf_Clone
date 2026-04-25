#include "mainoffice.h"

int animstart = 0;

const int delay = 150;
const int doordelay = 50;



bool leftdoorclosed = false;
bool rightdoorclosed = false;
Uint32 leftDoorAnimStart = 0;
Uint32 rightDoorAnimStart = 0;


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

    SDL_Surface* main_camera = IMG_Load("assets/Office/Map/145.png");
    main_camera_texture = SDL_CreateTextureFromSurface(renderer,main_camera);
    SDL_DestroySurface(main_camera);

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
    


    const char* backstage_path[5]={
        "assets/Locations/Backstage/83.png",
         "assets/Locations/Backstage/205.png",
          "assets/Locations/Backstage/354.png",
           "assets/Locations/Backstage/358.png",
            "assets/Locations/Backstage/555.png",

    };

    for(int i=0; i<5;i++){
        SDL_Surface* temp = IMG_Load(backstage_path[i]);
        Backstage[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* dining_hall_path[6]={
        "assets/Locations/Dining Hall/48.png",
         "assets/Locations/Dining Hall/90.png",
          "assets/Locations/Dining Hall/120.png",
           "assets/Locations/Dining Hall/215.png",
            "assets/Locations/Dining Hall/222.png",
            "assets/Locations/Dining Hall/492.png"

    };

    for(int i=0; i<6;i++){
        SDL_Surface* temp = IMG_Load(dining_hall_path[i]);
        DiningHall[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* E_hall_path[9]={
        "assets/Locations/E. Hall Corner/49.png",
        "assets/Locations/E. Hall Corner/220.png",
        "assets/Locations/E. Hall Corner/451.png",
        "assets/Locations/E. Hall Corner/476.png",
        "assets/Locations/E. Hall Corner/486.png",
        "assets/Locations/E. Hall Corner/549.png",
        "assets/Locations/E. Hall Corner/550.png",
        "assets/Locations/E. Hall Corner/551.png",
        "assets/Locations/E. Hall Corner/552.png",

         

    };

    for(int i=0; i<9;i++){
        SDL_Surface* temp = IMG_Load(E_hall_path[i]);
        E_Hall_Corner[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }



    const char* E_hall_path_2[6]={
        "assets/Locations/East Hall/67.png",
        "assets/Locations/East Hall/221.png",
        "assets/Locations/East Hall/226.png",
        "assets/Locations/East Hall/487.png",
        "assets/Locations/East Hall/546.png",
        "assets/Locations/East Hall/554.png",
     
    };

    for(int i=0; i<6;i++){
        SDL_Surface* temp = IMG_Load(E_hall_path_2[i]);
        East_Hall[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }



    const char* Names_path[12]={
        "assets/Locations/Names/50.png",
        "assets/Locations/Names/54.png",
        "assets/Locations/Names/70.png",
        "assets/Locations/Names/71.png",
        "assets/Locations/Names/72.png",
        "assets/Locations/Names/73.png",
        "assets/Locations/Names/74.png",
        "assets/Locations/Names/75.png",
        "assets/Locations/Names/76.png",
        "assets/Locations/Names/77.png",
        "assets/Locations/Names/78.png",
        "assets/Locations/Names/79.png"
     
    };

    for(int i=0; i<12;i++){
        SDL_Surface* temp = IMG_Load(Names_path[i]);
        Names[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* Pirate_path[5]={
        "assets/Locations/Pirate Cove/66.png",
       "assets/Locations/Pirate Cove/211.png",
       "assets/Locations/Pirate Cove/240.png",
       "assets/Locations/Pirate Cove/338.png",
       "assets/Locations/Pirate Cove/553.png",
     
    };

    for(int i=0; i<5;i++){
        SDL_Surface* temp = IMG_Load(Pirate_path[i]);
        PirateCover[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* Restroom_path[4]={
        "assets/Locations/Restrooms/41.png",
       "assets/Locations/Restrooms/217.png",
       "assets/Locations/Restrooms/219.png",
       "assets/Locations/Restrooms/494.png"
     
    };

    for(int i=0; i<4;i++){
        SDL_Surface* temp = IMG_Load(Restroom_path[i]);
        Restrooms[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* showstage_path[7]={
        "assets/Locations/Show Stage/2.png",
       "assets/Locations/Show Stage/19.png",
       "assets/Locations/Show Stage/68.png",
       "assets/Locations/Show Stage/223.png",
    "assets/Locations/Show Stage/224.png",
       "assets/Locations/Show Stage/355.png",
       "assets/Locations/Show Stage/484.png"
    };

    for(int i=0; i<7;i++){
        SDL_Surface* temp = IMG_Load(showstage_path[i]);
        Showstage[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* supply_closet_path[2]={
        "assets/Locations/Supply Closet/62.png",
       "assets/Locations/Supply Closet/190.png",
      
    };

    for(int i=0; i<2;i++){
        SDL_Surface* temp = IMG_Load(supply_closet_path[i]);
        Supply_closet[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }

    const char* W_H_path[6]={
        "assets/Locations/W. Hall Corner/0.png",
       "assets/Locations/W. Hall Corner/188.png",
       "assets/Locations/W. Hall Corner/478.png",
       "assets/Locations/W. Hall Corner/479.png",
       "assets/Locations/W. Hall Corner/540.png",
       "assets/Locations/W. Hall Corner/571.png",
      
    };

    for(int i=0; i<6;i++){
        SDL_Surface* temp = IMG_Load(W_H_path[i]);
        W_Hall_Corner[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }
 

    const char* W_H_path2[3]={
        "assets/Locations/West Hall/43.png",
        "assets/Locations/West Hall/44.png",
         "assets/Locations/West Hall/206.png"
       
      
    };

    for(int i=0; i<3;i++){
        SDL_Surface* temp = IMG_Load(W_H_path2[i]);
        WestHall[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* Foxy[31]={
        "assets/Locations/West Hall/Foxy Run/241.png",
        "assets/Locations/West Hall/Foxy Run/244.png",
        "assets/Locations/West Hall/Foxy Run/245.png",
        "assets/Locations/West Hall/Foxy Run/246.png",
        "assets/Locations/West Hall/Foxy Run/247.png",
        "assets/Locations/West Hall/Foxy Run/248.png",
        "assets/Locations/West Hall/Foxy Run/250.png",
        "assets/Locations/West Hall/Foxy Run/280.png",
        "assets/Locations/West Hall/Foxy Run/282.png",
        "assets/Locations/West Hall/Foxy Run/283.png",
        "assets/Locations/West Hall/Foxy Run/284.png",
        "assets/Locations/West Hall/Foxy Run/285.png",
        "assets/Locations/West Hall/Foxy Run/286.png",
        "assets/Locations/West Hall/Foxy Run/287.png",
        "assets/Locations/West Hall/Foxy Run/288.png",
        "assets/Locations/West Hall/Foxy Run/289.png",
        "assets/Locations/West Hall/Foxy Run/290.png",
        "assets/Locations/West Hall/Foxy Run/292.png",
        "assets/Locations/West Hall/Foxy Run/302.png",
        "assets/Locations/West Hall/Foxy Run/306.png",
        "assets/Locations/West Hall/Foxy Run/327.png",
        "assets/Locations/West Hall/Foxy Run/329.png",
        "assets/Locations/West Hall/Foxy Run/330.png",
        "assets/Locations/West Hall/Foxy Run/331.png",
        "assets/Locations/West Hall/Foxy Run/332.png",
        "assets/Locations/West Hall/Foxy Run/333.png",
        "assets/Locations/West Hall/Foxy Run/334.png",
        "assets/Locations/West Hall/Foxy Run/335.png",
        "assets/Locations/West Hall/Foxy Run/336.png",
        "assets/Locations/West Hall/Foxy Run/337.png",
        "assets/Locations/West Hall/Foxy Run/340.png",

    };
 

    for(int i=0; i<31;i++){
        SDL_Surface* temp = IMG_Load(Foxy[i]);
        FoxyRun[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    const char* static_path[8]= {
        "assets/static_and_menu/Full_Static/12.png",
        "assets/static_and_menu/Full_Static/13.png",
        "assets/static_and_menu/Full_Static/14.png",
        "assets/static_and_menu/Full_Static/15.png",
        "assets/static_and_menu/Full_Static/16.png",
        "assets/static_and_menu/Full_Static/17.png",
        "assets/static_and_menu/Full_Static/18.png",
        "assets/static_and_menu/Full_Static/20.png"
    };

    for(int i=0; i<8;i++){
        SDL_Surface* temp = IMG_Load(static_path[i]);
        
        static_animation[i]= SDL_CreateTextureFromSurface(renderer,temp);
        SDL_SetTextureAlphaMod(static_animation[i], 20);
        SDL_DestroySurface(temp);
    }


    const char* RedPath[2]={
        "assets/Office/Monitor/Red.png",
        "assets/Office/Monitor/Red2.png"
    };

    for(int i=0; i<2;i++){
        SDL_Surface* temp = IMG_Load(RedPath[i]);
        Red[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }



    SDL_Surface* Showstage = IMG_Load("assets/Locations/Names/54.png");
    texts[0]=SDL_CreateTextureFromSurface(renderer,Showstage);
    SDL_DestroySurface(Showstage);
    SDL_Surface* DiningArea = IMG_Load("assets/Locations/Names/72.png");
    texts[1]=SDL_CreateTextureFromSurface(renderer,DiningArea);
    SDL_DestroySurface(DiningArea);
    SDL_Surface* Backstage = IMG_Load("assets/Locations/Names/71.png");
    texts[2]=SDL_CreateTextureFromSurface(renderer,Backstage);
    SDL_DestroySurface(Backstage);
    SDL_Surface* PirateCove = IMG_Load("assets/Locations/Names/73.png");
    texts[3]=SDL_CreateTextureFromSurface(renderer,PirateCove);
    SDL_DestroySurface(PirateCove);
    SDL_Surface* WestHall = IMG_Load("assets/Locations/Names/74.png");
    texts[4]=SDL_CreateTextureFromSurface(renderer,WestHall);
    SDL_DestroySurface(WestHall);
    SDL_Surface* Restrooms = IMG_Load("assets/Locations/Names/77.png");
    texts[5]=SDL_CreateTextureFromSurface(renderer,Restrooms);
    SDL_DestroySurface(Restrooms);
    SDL_Surface* Kitchen = IMG_Load("assets/Locations/Names/78.png");
    texts[6]=SDL_CreateTextureFromSurface(renderer,Kitchen);
    SDL_DestroySurface(Kitchen);
    SDL_Surface* EastHall = IMG_Load("assets/Locations/Names/79.png");
    texts[7]=SDL_CreateTextureFromSurface(renderer,EastHall);
    SDL_DestroySurface(EastHall);
    SDL_Surface* SupplyCloset = IMG_Load("assets/Locations/Names/50.png");
    texts[8]=SDL_CreateTextureFromSurface(renderer,SupplyCloset);
    SDL_DestroySurface(SupplyCloset);
    SDL_Surface* EHallCorner = IMG_Load("assets/Locations/Names/75.png");
    texts[9]=SDL_CreateTextureFromSurface(renderer,EHallCorner);
    SDL_DestroySurface(EHallCorner);
    SDL_Surface* WHallCorner = IMG_Load("assets/Locations/Names/76.png");
    texts[10]=SDL_CreateTextureFromSurface(renderer,WHallCorner);
    SDL_DestroySurface(WHallCorner);

    // SDL_Surface* camera_green = IMG_Load("assets/Numbers_and_Night/Camera_and_Nights/576.png");
    
    // camera_green_texture = SDL_CreateTextureFromSurface(renderer,camera_green);

    // SDL_DestroySurface(camera_green);


    SDL_Surface* ending_1 = IMG_Load("assets/Office/Office_Inside/304.png");
    ending_1_texture = SDL_CreateTextureFromSurface(renderer,ending_1);
    SDL_Surface* ending_2 = IMG_Load("assets/Office/Office_Inside/305.png");
    ending_2_texture = SDL_CreateTextureFromSurface(renderer,ending_2);
    SDL_DestroySurface(ending_1);
    SDL_DestroySurface(ending_2);


    return;
}


void MainOffice::RenderOffice(bool screen_camera, bool leftdoorbottom, bool leftdoorup, bool rightdoorbottom, bool rightdoorup, bool ending, bool bonnie, bool chika){

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

    }
    else if(leftdoorbottom && !rightdoorbottom){
    
    if(!bonnie){
     Uint32 elapsed = SDL_GetTicks() - animstart;
    animFrame = (elapsed / delay) %2;


    
    if(animFrame>=2) {
        animFrame = 1;
    }
    SDL_RenderTexture(renderer,officeTextures[animFrame],NULL,&dst);
}
else{
    Uint32 elapsed = SDL_GetTicks()-animstart;
    animFrame = (elapsed/delay) % 2;

    // if(!MIX_TrackPlaying(lightdoor)){
    //     MIX_SetTrackAudio(lightdoor,windowscare);
    //     MIX_PlayTrack(lightdoor, 0);
    // }

    SDL_RenderTexture(renderer,officeTextures[animFrame? 1: 3],NULL,&dst);
}

}
    
    else if(!leftdoorbottom && rightdoorbottom ){

    if(!chika){
    Uint32 elapsed_time = SDL_GetTicks() - animstart;
    animFrame = (elapsed_time/delay) % 2 + 1;

    if(animFrame>=2){
        animFrame=2;
    }
    SDL_RenderTexture(renderer,officeTextures[animFrame],NULL,&dst);
    }
    else{
        Uint32 elapsed_time = SDL_GetTicks()-animstart;
        animFrame = (elapsed_time/delay) % 2;

        

        SDL_RenderTexture(renderer,officeTextures[animFrame*4],NULL,&dst);
    }
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
        Uint32 elapsed_time = SDL_GetTicks() - leftDoorAnimStart;
        animFrame = (elapsed_time/doordelay);

        if(animFrame>=11){
            animFrame=10;
            leftdoorclosed= true;
        }

        SDL_RenderTexture(renderer,leftDoorFrame[animFrame],NULL,&leftdoor);
    }
    else if(leftdoorclosed && !leftdoorup){
    // opening: play 12 -> 0
    Uint32 elapsed_time = SDL_GetTicks() - leftDoorAnimStart;
    int frame = 11 - (int)(elapsed_time / doordelay);

    if(frame <= 0){
        frame = 0;
        leftdoorclosed = false;
    }
    SDL_RenderTexture(renderer, leftDoorFrame[frame], NULL, &leftdoor);
}
    else if(leftdoorup){
        SDL_RenderTexture(renderer,leftDoorFrame[11],NULL,&leftdoor);
    }

    if(!rightdoorclosed && rightdoorup){
         Uint32 elapsed_time = SDL_GetTicks() - rightDoorAnimStart;
        animFrame = (elapsed_time/doordelay);

        if(animFrame>12){
            animFrame=12;
            rightdoorclosed= true;
        }

        SDL_RenderTexture(renderer,rightDoorFrame[animFrame],NULL,&rightdoor);

    }
    else if(rightdoorclosed && !rightdoorup){
        Uint32 elapsed_time = SDL_GetTicks() - rightDoorAnimStart;
        int frame = 11 - (int)(elapsed_time/doordelay);

        if(frame <=0){
            frame = 0;
            rightdoorclosed = false;
        }
        SDL_RenderTexture(renderer,rightDoorFrame[frame],NULL,&rightdoor);
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


void MainOffice::RenderCamera(int state,int cameralocation){


    Uint32 elapsed = SDL_GetTicks() - animStartFrame;
    animFrame = elapsed/delayPerItem;

    if (dstCam.x >= dstCam.w / 128) {
    cameradirection = -1;
}
// Left bound: when camera has moved far enough left, go right
else if (dstCam.x <= -dstCam.w / 6) {
    cameradirection = 1;
}

    dstCam.x+=cameradirection* 0.10;
    
   

    switch(state){
        case 0:
        SDL_RenderTexture(renderer,Showstage[1],0,&dstCam);
        break;
        case 1:
        SDL_RenderTexture(renderer,DiningHall[0],0,&dstCam);
        break;
        case 2:
        SDL_RenderTexture(renderer,Backstage[0],0,&dstCam);
        break;
        case 3:
        SDL_RenderTexture(renderer,Restrooms[0],0,&dstCam);
        break;
        case 4:
        SDL_RenderTexture(renderer,PirateCover[0],0,&dstCam);
        break;
        case 5:
        SDL_RenderTexture(renderer,Supply_closet[0],0,&dstCam);
        break;
        case 6:
        SDL_RenderTexture(renderer,NULL,0,&dstCam);
        break;
        case 7:
        SDL_RenderTexture(renderer,WestHall[0],0,&dstCam);
        break;
        case 8:
        SDL_RenderTexture(renderer,W_Hall_Corner[0],0,&dstCam);
        break;
        case 9:
        SDL_RenderTexture(renderer,East_Hall[0],0,&dstCam);
        break;
        case 10:
        SDL_RenderTexture(renderer,E_Hall_Corner[0],0,&dstCam);
        break;
        case 11: 
        SDL_RenderTexture(renderer,Showstage[2],0,&dstCam);
        break;
        case 12:
        SDL_RenderTexture(renderer,Showstage[3],0,&dstCam);
        break;
        case 13:
        SDL_RenderTexture(renderer,Showstage[4],0,&dstCam);
        break;
        case 14:
        SDL_RenderTexture(renderer,Showstage[5],0,&dstCam);
        break;
        case 15:
        SDL_RenderTexture(renderer,Showstage[6],0,&dstCam);
        break;
        case 16:
        SDL_RenderTexture(renderer,DiningHall[1],0,&dstCam);
        break;
        case 17:
        SDL_RenderTexture(renderer,DiningHall[3],0,&dstCam);
        break;
        case 18:
        SDL_RenderTexture(renderer,DiningHall[2],0,&dstCam);
        break;
        case 19:
        SDL_RenderTexture(renderer,DiningHall[4],0,&dstCam);
        break;
        case 20:
        SDL_RenderTexture(renderer,DiningHall[5],0,&dstCam);
        break;
        case 21:
        SDL_RenderTexture(renderer,Backstage[2],0,&dstCam);
        break;
        case 22:
        SDL_RenderTexture(renderer,Backstage[1],0,&dstCam);
        break;
        case 23:
        SDL_RenderTexture(renderer,Backstage[4],0,&dstCam);
        break;
        case 24:
        SDL_RenderTexture(renderer,Restrooms[1],0,&dstCam);
        break;
        case 25:
        SDL_RenderTexture(renderer,Restrooms[2],0,&dstCam);
        break;
        case 26:
        SDL_RenderTexture(renderer,Restrooms[3],0,&dstCam);
        break;
        case 27:
        SDL_RenderTexture(renderer,Supply_closet[1],0,&dstCam);
        break;
        case 28:
        if(animstart%2){
        SDL_RenderTexture(renderer,WestHall[1],0,&dstCam);
        }
        else{
            SDL_RenderTexture(renderer,WestHall[2],0,&dstCam);
        }
        break;
        case 29:
            SDL_RenderTexture(renderer,W_Hall_Corner[2],0,&dstCam);
        break;
        case 30:
        SDL_RenderTexture(renderer,East_Hall[2],0,&dstCam);
        break;
        case 31:
        SDL_RenderTexture(renderer,East_Hall[2],0,&dstCam);
        break;
        case 32:
        SDL_RenderTexture(renderer,E_Hall_Corner[1],0,&dstCam);
        break;
    }
         SDL_RenderTexture(renderer,main_camera_texture,0,&cameradst2);

    switch(cameralocation){
        case 0:
        SDL_RenderTexture(renderer,texts[0],0,&textdst);
       
        break;
        case 1:
        SDL_RenderTexture(renderer,texts[1],0,&textdst);
        break;
        case 2:
        SDL_RenderTexture(renderer,texts[2],0,&textdst);
        break;
        case 3:
        SDL_RenderTexture(renderer,texts[3],0,&textdst);
        break;
        case 4:
        SDL_RenderTexture(renderer,texts[4],0,&textdst);
        break;
        case 5:
        SDL_RenderTexture(renderer,texts[5],0,&textdst);
        break;
        case 6:
        SDL_RenderTexture(renderer,texts[6],0,&textdst);
        break;
        case 7:
        SDL_RenderTexture(renderer,texts[7],0,&textdst);
        break;
        case 8:
        SDL_RenderTexture(renderer,texts[8],0,&textdst);
        break;
        case 9:
        SDL_RenderTexture(renderer,texts[9],0,&textdst);
        break;
        case 10:
        SDL_RenderTexture(renderer,texts[10],0,&textdst);
        break;

        }

    auto elapsed_time_2 = SDL_GetTicks() - animStartFrame;
    secondanimFrame = elapsed_time_2/400;

     SDL_RenderTexture(renderer,Red[secondanimFrame%2],0,&topLeft);

     SDL_RenderTexture(renderer,static_animation[animFrame%8],0,&dest);

    //SDL_RenderTexture(renderer,camera_green_texture,0,&cam1a);


    return;
}

void MainOffice::RenderEnding(){



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
    
    SDL_RenderTexture(renderer,ending_1_texture,0,&dst);
    SDL_RenderTexture(renderer, leftDoorButton[0], NULL, &leftdst);
    SDL_RenderTexture(renderer,rightDoorButton[0],NULL,&rightdst);



    return;
}