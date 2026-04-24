#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <random>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <string>


extern bool leftdoorclosed;
extern bool rightdoorclosed;
extern Uint32 leftDoorAnimStart;
extern Uint32 rightDoorAnimStart;

class MainOffice{

    public:

    MainOffice(int width, int height, SDL_Renderer* renderer): width(width), height(height),renderer(renderer){
        dst = {0,0,static_cast<float>(width*1.5),(float)height};
        dstCam={0,0,1600,720};
        initOffice();

    }

    ~MainOffice(){
        SDL_DestroyTexture(default_office);
    }

    void initOffice();
    void RenderOffice(bool screen_camera, bool leftdoorbottom=false, bool leftdoorup=false, bool rightdoorbottom=false, bool rightdoorup=false, bool ending=false);
    void RenderCamera(int state=0,int cameralocation = 0);
    void RenderEnding();




    private:
    SDL_Renderer* renderer;
    SDL_Texture* default_office;
    SDL_Texture* main_camera_texture;
    SDL_Texture* ending_1_texture;
    SDL_Texture* ending_2_texture;
    SDL_Texture* Fan[3];
    SDL_Texture* leftDoorButton[4];
    SDL_Texture* rightDoorButton[4];
    SDL_Texture* officeTextures[7];
    SDL_Texture* rightDoorFrame[13];
    SDL_Texture* leftDoorFrame[13];
    SDL_Texture* Red[2];

    SDL_Texture* Backstage[5];
    SDL_Texture* DiningHall[6];
    SDL_Texture* E_Hall_Corner[9];
    SDL_Texture* East_Hall[6];
    SDL_Texture* Names[12];
    SDL_Texture* PirateCover[5];
    SDL_Texture* Restrooms[4];
    SDL_Texture* Showstage[7];
    SDL_Texture* Supply_closet[2];
    SDL_Texture* W_Hall_Corner[6];
    SDL_Texture* WestHall[3];
    SDL_Texture* FoxyRun[31];

    SDL_Texture* static_animation[8];

    SDL_Texture* texts[11];
    
    int width;
    int height;
    SDL_FRect dst;
    SDL_FRect dstCam;
    const int delayPerItem = 25;
    int animFrame = 0;
    int secondanimFrame =0;
    Uint64 animStartFrame = SDL_GetTicks();
    bool animating =false;
    int cameradirection = -1;
    SDL_FRect cameradst={935,299,165,200};
    SDL_FRect textdst = {955,350,200,50};
    SDL_FRect leftdst={0,250,100,200};
    SDL_FRect rightdst={1800,250,100,200};
    SDL_FRect leftdoor= {115,0,223,720};
    SDL_FRect cameradst2={875,400,400,300};
    SDL_FRect dest = {0,0,1280,720};
    SDL_FRect topLeft = {10,10,50,50};

    // SDL_FRect cam1a = {500,405,65,30};
    // SDL_FRect cam1b = {990,455,65,30};
    // SDL_FRect cam5 = {890,475,65,30};
    // SDL_FRect cam7 = {1190,475,65,30};
    // SDL_FRect cam1c = {960,525,65,30};
    // SDL_FRect cam3 = {930,595,65,30};
    // SDL_FRect cam6 = {1190,585,65,30};
    // SDL_FRect cam2a = {1000,605,65,30};
    // SDL_FRect cam2b = {1000,645,65,30};
    // SDL_FRect cam4a = {1100,615,65,30};
    // SDL_FRect cam4b = {1100,645,65,30};
    
    SDL_FRect rightdoor={static_cast<float>(width+260),0,223,720};
    

};