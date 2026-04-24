#include "mainmenu.h"
#include "mainoffice.h"
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include "Animatronics.hpp"

const int window_x = 1280;
const int window_y = 720;
const int delayPerItem = 25;
const int jumpscaredelay=200;
bool running = true;
bool main_menu = true;
bool main_game = false;
bool main_office = false;
bool default_main_menu = true;
int main_menu_state = 0;
int alpha = 240;
bool pressed_E = false;
bool screen_camera = false;
Uint64 previous_camera_time =0;
SDL_Texture* camera_array[11];
bool animating =false;
bool cameraMode = false;
int animFrame = 0;
Uint64 animStartFrame = SDL_GetTicks();
bool leftdoorbottom =false;
bool leftdoorup = false;
SDL_FRect timeText = {1120, 10, 125,50};
SDL_FRect nightText = {1120, 50, 125,50};
SDL_FRect powerleft = {20,590,100,35};
SDL_FRect usage = {20,640,100,35};
SDL_FRect powerleft1 = {140,640,100,35};
SDL_FRect percentage_coordinate = {135,590,100,35};
SDL_FRect flipper_coordinate = {300,590,600,100};
SDL_FRect deathdest = {0,0,1280,720};

bool rightdoorbottom = false;
bool rightdoorup = false;
bool inner_E = false;
int globalPowerUsage = 0;
SDL_Texture* powerbar[5];
int cur_default = 5000;
int state =0;
bool ending=false;
Uint64 lastAiTick = 0;
Uint64 deathanimFrame=0;

int percentage = 100;
int difficulty=5;
int cameralocation = 0;

int main(int argc, char* argv[]){
    srand(time(0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    std::uniform_int_distribution<int> dist2(0, 9);
    std::uniform_int_distribution<int> dist3(0,14);
    std::uniform_int_distribution<int> random_number(0,100);
    std::bernoulli_distribution d(0.25);
    SDL_Event event;
    

    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
        std::cerr << SDL_GetError() << "\n";

        return -1;
    }


     if(!(TTF_Init())){
        std::cerr << SDL_GetError() << "\n";
    }



    SDL_Window* window = SDL_CreateWindow(
        "Fnaf 1 Clone",
        window_x,
        window_y,
        0
    );

    if(!window){
        SDL_Quit();
        std::cerr << SDL_GetError() << "\n";
        return -1;
    }

    SDL_SetWindowSize(window, 1280, 720);
   

    SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);


    if(!renderer){
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::cerr << SDL_GetError() << "\n";
        return -1;
    }

    MainMenu* main_menu_object = new MainMenu(window_x,window_y,renderer);
    MainOffice* mainoffice = new MainOffice(window_x,window_y,renderer);

    Uint64 last_time = SDL_GetTicks();

    uint32_t frame =0;


    MIX_Init();
    MIX_Mixer* mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    MIX_Audio* darkness = MIX_LoadAudio(mixer,"assets/sounds/darkness_music.wav",false);
    MIX_Audio* ambience = MIX_LoadAudio(mixer, "assets/sounds/ambience2.wav", false);
    MIX_Audio* buzzfan = MIX_LoadAudio(mixer,"assets/sounds/Buzz_Fan_Florescent2.wav",false);
    MIX_Audio* staticSound  = MIX_LoadAudio(mixer, "assets/sounds/static.wav", false);
    MIX_Audio* staticSound2 = MIX_LoadAudio(mixer, "assets/sounds/static2.wav", false);
    MIX_Audio* blip         = MIX_LoadAudio(mixer, "assets/sounds/blip3.wav", false);
    MIX_Audio* night1 = MIX_LoadAudio(mixer,"assets/sounds/voiceover1c.wav",false);
    MIX_Audio* hum = MIX_LoadAudio(mixer,"assets/sounds/BallastHumMedium2.wav",false);
    MIX_Audio* door_close = MIX_LoadAudio(mixer,"assets/sounds/SFXBible_12478.wav",false);
    MIX_Audio* bonniescream = MIX_LoadAudio(mixer,"assets/sounds/XSCREAM.wav",false);


    MIX_Track* bonniejumpscaretrack = MIX_CreateTrack(mixer);
    MIX_Track* sfxTrack = MIX_CreateTrack(mixer);
    MIX_Track* sfxTrack1 = MIX_CreateTrack(mixer);
    MIX_Track* darknessTrack = MIX_CreateTrack(mixer);
    MIX_Track* ambienceTrack = MIX_CreateTrack(mixer);
    MIX_Track* buzzfan_track = MIX_CreateTrack(mixer);
    MIX_SetTrackAudio(sfxTrack,staticSound);
    MIX_SetTrackAudio(sfxTrack1,staticSound2);
    MIX_SetTrackAudio(ambienceTrack, ambience);
    MIX_SetTrackAudio(buzzfan_track,buzzfan);
    MIX_SetTrackAudio(darknessTrack,darkness);
    MIX_SetTrackGain(buzzfan_track, 0.2f);
    

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetNumberProperty(props, MIX_PROP_PLAY_LOOPS_NUMBER, -1); // -1 = loop forever
    MIX_PlayTrack(ambienceTrack, props);
    SDL_DestroyProperties(props);


    
    TTF_Font* font =  TTF_OpenFont("external/textfiles/consolas.ttf",64);
    SDL_Color color = {255,255,255,255};
    SDL_FRect dst = {1075/2,500/2,200,50};

    SDL_FRect cameradst={0,0,1280,720};
    SDL_FRect dst1 = {1075/2,600/2,200,50};
    SDL_Surface* textSurface = TTF_RenderText_Blended(font,"12:00",0,color);
    SDL_Surface* textSurface1 = TTF_RenderText_Blended(font,"Night 1",0,color);
    
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer,textSurface);
    SDL_Texture* text_texture1 = SDL_CreateTextureFromSurface(renderer,textSurface1);

    std::string percentage_string = std::to_string(percentage) + "%";
    SDL_Surface* percentageSurface = TTF_RenderText_Blended(font,percentage_string.c_str(),0,color);
    SDL_Texture* percentage_texture = SDL_CreateTextureFromSurface(renderer,percentageSurface);
    SDL_DestroySurface(percentageSurface);

    SDL_Surface* flipper = IMG_Load("assets/Office/Monitor/flipper.png");

    SDL_Texture* flipper_texture = SDL_CreateTextureFromSurface(renderer,flipper);
    SDL_DestroySurface(flipper);

    
    const char* path[11]={
        "assets/Office/Monitor/46.png",
        "assets/Office/Monitor/132.png",
        "assets/Office/Monitor/133.png",
        "assets/Office/Monitor/136.png",
        "assets/Office/Monitor/137.png",
        "assets/Office/Monitor/138.png",
        "assets/Office/Monitor/139.png",
        "assets/Office/Monitor/140.png",
        "assets/Office/Monitor/141.png",
        "assets/Office/Monitor/142.png",
        "assets/Office/Monitor/144.png"
    };

    for(int i =0; i<11;i++){

        SDL_Surface* camera_surface = IMG_Load(path[i]);
        camera_array[i]=SDL_CreateTextureFromSurface(renderer,camera_surface);
        SDL_DestroySurface(camera_surface);
    }

    SDL_Surface* usage_icon = IMG_Load("assets/Numbers_and_Nights/Camera and Nights/189.png");
    SDL_Surface* power_left = IMG_Load("assets/Numbers_and_Nights/Camera and Nights/207.png");

    SDL_Texture* usage_texture = SDL_CreateTextureFromSurface(renderer,usage_icon);
    SDL_Texture* power_left_texture = SDL_CreateTextureFromSurface(renderer,power_left);



    const char* powerpath[5] ={
        "assets/Office/Door_Lights/Power/212.png",
        "assets/Office/Door_Lights/Power/213.png",
        "assets/Office/Door_Lights/Power/214.png",
        "assets/Office/Door_Lights/Power/456.png",
        "assets/Office/Door_Lights/Power/455.png"

    };

    for(int i=0; i<5;i++){
        SDL_Surface* temp = IMG_Load(powerpath[i]);

        powerbar[i]=SDL_CreateTextureFromSurface(renderer,temp);

        SDL_DestroySurface(temp);
    }


    SDL_Texture* BonnieJumpscare[11];

    const char* BonnieJumpscarePath[11] = {
        "assets/Jumpscares/Bonnie/291.png",
        "assets/Jumpscares/Bonnie/293.png",
        "assets/Jumpscares/Bonnie/294.png",
        "assets/Jumpscares/Bonnie/295.png",
        "assets/Jumpscares/Bonnie/296.png",
        "assets/Jumpscares/Bonnie/297.png",
        "assets/Jumpscares/Bonnie/298.png",
        "assets/Jumpscares/Bonnie/299.png",
        "assets/Jumpscares/Bonnie/300.png",
        "assets/Jumpscares/Bonnie/301.png",
        "assets/Jumpscares/Bonnie/303.png"
    };

    for(int i=0; i<11;i++){
        SDL_Surface* temp = IMG_Load(BonnieJumpscarePath[i]);
        BonnieJumpscare[i]=SDL_CreateTextureFromSurface(renderer,temp);
        SDL_DestroySurface(temp);
    }


    
    SDL_DestroySurface(textSurface);
    SDL_DestroySurface(textSurface1);
    SDL_DestroySurface(usage_icon);
    SDL_DestroySurface(power_left);
   
    Animatronic* bonnie = new Bonnie(difficulty);
    Animatronic* freddy = new Freddy(difficulty);
    Animatronic* chika = new Chika(difficulty);
    Animatronic* foxy = new Foxy(difficulty);
    

    while(running){


        frame++;

        int chikaroom = chika->isInRoom();
        int bonnieroom = bonnie->isInRoom();
        int freddyroom = freddy->isInRoom();

       if (bonnie->playerDeath) {

    Uint64 elapsed = SDL_GetTicks() - animStartFrame;

    deathanimFrame = elapsed / 50;

    if (deathanimFrame >= 12) {

        deathanimFrame = 11;
    } else {
        // animation finished
        main_office = false;
        main_menu = true;
    }

    SDL_RenderTexture(renderer, BonnieJumpscare[deathanimFrame], 0, &deathdest);

    // play sound ONCE
    if (!MIX_TrackPlaying(bonniejumpscaretrack) && !main_menu) {
        MIX_SetTrackAudio(bonniejumpscaretrack, bonniescream);
        MIX_PlayTrack(bonniejumpscaretrack, 0);
    }
}
        else if(freddy->playerDeath){

        }
        else if(bonnie->playerDeath){

        }
        else if(foxy->playerDeath){

        }



        if(SDL_GetTicks()-lastAiTick >=500 && main_office){
        bonnie->Tick(!leftdoorup,cameraMode,chikaroom,freddyroom);
        freddy->Tick(rightdoorup,cameraMode,bonnieroom,chikaroom);
        chika->Tick(rightdoorup,cameraMode,bonnieroom,freddyroom);
        foxy->Tick(cameraMode,(state==4),leftdoorup, leftdoorup);
            lastAiTick = SDL_GetTicks();
            std::cout << bonnieroom << " " << chikaroom << " " << freddyroom << "\n";
        }

        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        Uint64 now = SDL_GetTicks();
        float dt = (now - last_time) / 1000.0f;
        last_time = now;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                running = false;
            }

            if (event.type == SDL_EVENT_MOUSE_MOTION) {
                float mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if(main_office){
                     if(mouseX>=window_x*0.25 && mouseX <= window_x*0.65 && mouseY>=window_y*0.75 && mouseY<window_y && SDL_GetTicks()-previous_camera_time>=900 && percentage>0){
                        screen_camera = !screen_camera;

                        if(screen_camera){
                             globalPowerUsage++;
                        }
                        else{
                            globalPowerUsage--;
                        }
                        
                        previous_camera_time = SDL_GetTicks();
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                         animating=true;
                        animFrame=0;
                         animStartFrame = SDL_GetTicks();
                         cameraMode= false;

                       
                }

                    
                }
            }

             if(event.type==SDL_EVENT_MOUSE_BUTTON_DOWN){

                if(main_menu){


                    if(!MIX_TrackPlaying(darknessTrack)){
                         MIX_PlayTrack(darknessTrack, 0);
                          }
                         
            
                int mouseX_button = event.button.x;
                int mouseY_button = event.button.y;
               if(mouseX_button>=75 && mouseX_button<=450 && mouseY_button>=300 && mouseY_button<=500){
                

                main_menu = false;
                main_game = true;
                MIX_StopTrack(darknessTrack,0);
                MIX_SetTrackAudio(sfxTrack, blip);
                MIX_PlayTrack(sfxTrack, 0);

               }

               
            
            }

            if(main_office){
                
                  int mouseX_button = event.button.x;
                int mouseY_button = event.button.y;
                if(mouseX_button>=0 && mouseX_button<=100 && mouseY_button>=360 && mouseY_button<=400 && percentage>0){
                        
                          if (!MIX_TrackPlaying(sfxTrack)) {
                        MIX_SetTrackAudio(sfxTrack, hum);
                        MIX_PlayTrack(sfxTrack, 0);
                          }
                          else{
                            MIX_StopTrack(sfxTrack,0);
                          }



                          leftdoorbottom = !leftdoorbottom;

                          if(leftdoorbottom){
                            globalPowerUsage++;
                        }
                        else{
                            globalPowerUsage--;
                        }
                    }

                if(mouseX_button>=0 && mouseX_button<=100 && mouseY_button>=290 && mouseY_button<=350 && percentage>0){

                     if (!MIX_TrackPlaying(sfxTrack)) {
                        MIX_SetTrackAudio(sfxTrack, door_close);
                        MIX_PlayTrack(sfxTrack, 0);
                          }
                          else{
                            MIX_SetTrackAudio(sfxTrack, door_close);
                             MIX_PlayTrack(sfxTrack, 0);
                            // MIX_StopTrack(sfxTrack,0);
                          }

                          leftdoorup = !leftdoorup;
                          if(leftdoorup){    
                            globalPowerUsage++;                      // only when opening the door
                            leftdoorclosed = false;
                            // reset timer HERE
                        }
                        else{
                            globalPowerUsage--;
                        }
                         leftDoorAnimStart = SDL_GetTicks(); 
                }

                if(mouseX_button>=1180 && mouseX_button<=1250 && mouseY_button>=290 && mouseY_button<=340 && percentage>0){

                       if (!MIX_TrackPlaying(sfxTrack)) {
                        MIX_SetTrackAudio(sfxTrack, door_close);
                        MIX_PlayTrack(sfxTrack, 0);
                          }
                          else{
                            MIX_SetTrackAudio(sfxTrack, door_close);
                             MIX_PlayTrack(sfxTrack, 0);
                            // MIX_StopTrack(sfxTrack,0);
                          }

                          rightdoorup = !rightdoorup;
                          if(rightdoorup){
                            rightdoorclosed = false;
                            globalPowerUsage++;
                            
                        }
                        else{
                            globalPowerUsage--;
                        }
                        rightDoorAnimStart = SDL_GetTicks();
                }

                if(mouseX_button>=1180 && mouseX_button<=1250 && mouseY_button>=360 && mouseY_button<=400 && percentage>0){
                      if (!MIX_TrackPlaying(sfxTrack)) {
                    MIX_SetTrackAudio(sfxTrack, hum);
                        MIX_PlayTrack(sfxTrack, 0);
                      }
                       else{
                            MIX_StopTrack(sfxTrack,0);
                          }

                          rightdoorbottom = !rightdoorbottom;

                            if(rightdoorbottom){
                            globalPowerUsage++;
                        }
                        else{
                            globalPowerUsage--;
                        }
                }

               


            
            }
             if(cameraMode){
                int mouseX_button = event.button.x;
                int mouseY_button = event.button.y;

                    if(mouseX_button>=1000 && mouseX_button<=1065 && mouseY_button>=405 && mouseY_button <= 435){
                        //cam1a
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation=0;
                        

                        
                
                        
                        
                        
                        if(bonnieroom>=1 && chikaroom>=1 && freddyroom>=3){
                            state=15;
                        }
                        else if(bonnieroom>=1 && chikaroom>=1){
                            state = 13; //freddy only
                        }
                        else if(bonnieroom>=1 && chikaroom>=1){
                            state=14; //freddy only
                        }
                        else if(bonnieroom>=0 && chikaroom>=1){
                            state = 12;
                        }
                        else if(bonnieroom>=1 && chikaroom>=0){
                            state = 11;
                           
                        }
                        else{
                            state = 0;
                           
                        }

                        //if(){}
                        
                
                    }
                    if(mouseX_button>=990 && mouseX_button<=1055 && mouseY_button>=455 && mouseY_button <= 485){
                        //cam1b
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 1;


                        

                        if(bonnieroom>=2 && bonnieroom <3){
                            state=18;
                        }
                        else if(bonnieroom>=1 && bonnieroom < 2){
                            state=16;
                        }
                        else if(chikaroom>=2 && bonnieroom<3){
                            state=19;
                        }
                        else if(chikaroom>=1 && chikaroom < 2){
                            state=17;
                        }
                        
                        else if(freddyroom >=3 && freddyroom < 4){
                            state = 20;
                        }

                        else{
                        state = 1;
                        }
                    }
                    if(mouseX_button>=890 && mouseX_button<=955 && mouseY_button>=475 && mouseY_button <= 505){
                        //cam5
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 2;
                        state = 2;


                        if(bonnieroom>=4 && bonnieroom < 5){
                            state = 23;
                        }
                        else if(bonnieroom >=3 && bonnieroom < 4){

                            if(d(gen)< 0.25){
                                state =22;

                            }
                            else{
                                state=21;
                            }
                       
                        
                        }
                       
                    }
                    if(mouseX_button>=1190 && mouseX_button<=1255 && mouseY_button>=475 && mouseY_button <= 505){
                        //cam7
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 5;

                        if(chikaroom>=4 && chikaroom< 4){
                            state=25;
                        }
                        else if(chikaroom >= 3 && chikaroom < 4){
                           
                                state = 24;
                           
                        }
                        else if(freddyroom>=4 && freddyroom<5){
                            state = 26;
                        }

                        else{
                        state= 3;
                        }
                    }
                    if(mouseX_button>=960 && mouseX_button<=1025 && mouseY_button>=525 && mouseY_button <= 555){
                        //cam1c
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 3;
                        state=4;

                        
                    }

                    if(mouseX_button>=930 && mouseX_button<=995 && mouseY_button>=595 && mouseY_button <= 625){
                        //cam3
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 8;
                       

                        if(bonnieroom >=5 && bonnieroom < 6){
                            state=27;
                        }
                        else{
                            state=5;
                        }
                    }

                    if(mouseX_button>=1190 && mouseX_button<=1255 && mouseY_button>=585 && mouseY_button <= 615){
                        //cam6
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 6;


                        state=6;
                        
                    }

                    if(mouseX_button>=1000 && mouseX_button<=1065 && mouseY_button>=605 && mouseY_button <= 635){
                        //cam2a
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 4;


                        if(bonnieroom>=6 && bonnieroom<7){
                            state=28;
                        }
                        else{
                        state=7;
                        }
                    }

                    if(mouseX_button>=1000 && mouseX_button<=1065 && mouseY_button>=645 && mouseY_button <= 675){
                        //cam2b
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 10;


                        if(bonnieroom>=7 && bonnieroom<8){
                            state=29;
                        }
                        else{
                        state=8;
                        }
                    }

                    if(mouseX_button>=1100 && mouseX_button<=1165 && mouseY_button>=615 && mouseY_button <= 645){
                        //cam4a
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 7;

                        if(chikaroom>=7 && chikaroom<8){
                            state=31;
                        }
                        else if(chikaroom>=6 && chikaroom<7){
                            state=30;
                        }
                        else{
                            state=9;
                        }
                        
                    }

                    if(mouseX_button>=1100 && mouseX_button<=1165 && mouseY_button>=645 && mouseY_button <= 675){
                        //cam4b
                        MIX_SetTrackAudio(sfxTrack, blip);
                        MIX_PlayTrack(sfxTrack, 0);
                        cameralocation = 9;

                        if(chikaroom>=8 && chikaroom<9){
                            state=32;
                        }
                        else{
                             state=10;
                        }
                    }

                }

            
            }
            if(event.type==SDL_EVENT_KEY_DOWN){
                if(event.key.key == SDLK_E){
                    pressed_E=true;
                }
            }

        }

        
        if(main_menu){

       

                      if (!MIX_TrackPlaying(sfxTrack)) {
            MIX_SetTrackAudio(sfxTrack, staticSound);
            MIX_PlayTrack(sfxTrack, 0);
            
        }


          if(!MIX_TrackPlaying(darknessTrack)){
            MIX_SetTrackAudio(darknessTrack,darkness);
            MIX_PlayTrack(darknessTrack,0);
          }
            if(default_main_menu){
               
            main_menu_object->default_main_menu();
            }
            else{   
            main_menu_object->main_menu_state(main_menu_state,frame);
            }

             

            if(!(frame%900)){
                frame = 0;
                if(random_number(gen) <= 50){
                    default_main_menu=true;
                }
                else{
                    default_main_menu=false;
                    main_menu_state = dist(gen);
                }

            }

           

            main_menu_object->staticTexture(dist2(gen) % 9);

            if (!(frame%100)){
            main_menu_object->divided_staticTexture(frame);
            }

            main_menu_object->render_text();

            
        }



        else if(main_game){
            if(!(frame%150)){
            if(alpha>0){
            alpha-=20;
            }
            }

            if(frame % 1800){

 
              
                SDL_SetTextureAlphaMod(text_texture, alpha);
                SDL_SetTextureAlphaMod(text_texture1, alpha);
                SDL_RenderTexture(renderer, text_texture,NULL, &dst);
                SDL_RenderTexture(renderer,text_texture1,NULL,&dst1);
             

            }
            else{
                 SDL_SetTextureAlphaMod(text_texture, 240);
                SDL_SetTextureAlphaMod(text_texture1, 240);
                main_game=false;
                main_office = true;
            }
        }


        else if(main_office){
          
            cur_default = 5000 - globalPowerUsage*1000;

        
            if(!(frame%cur_default) && percentage>0){
                percentage--;
             
                std::string temp_string_percentage = std::to_string(percentage)+"%";

                SDL_DestroyTexture(percentage_texture);
                SDL_Surface* temp = TTF_RenderText_Blended(font,temp_string_percentage.c_str(),0,color);
                percentage_texture = SDL_CreateTextureFromSurface(renderer,temp);
                SDL_DestroySurface(temp);
            }
            else{
                ending=true;
            }
           
             

            if(!MIX_TrackPlaying(buzzfan_track) && percentage>0){
                   MIX_PlayTrack(buzzfan_track, props);
                   
                
            }


            if(pressed_E || inner_E){
                MIX_StopTrack(sfxTrack1,0);
            }

            else if(!MIX_TrackPlaying(sfxTrack1)){
            
            if(!pressed_E){
              MIX_SetTrackAudio(sfxTrack1, night1);
            MIX_PlayTrack(sfxTrack1, 0);
            inner_E=true;
            }
        }
      
          
            
            if(!screen_camera){
            
            if(percentage>0){
            mainoffice->RenderOffice(screen_camera,leftdoorbottom,leftdoorup,rightdoorbottom,rightdoorup,ending);
            }
            else{
                mainoffice->RenderEnding();
                
            }
            }
            else{
                if (animating) {
    Uint32 elapsed = SDL_GetTicks() - animStartFrame;
    animFrame = elapsed / delayPerItem;

    if (animFrame >= 9) {
        animFrame = 8;     // clamp to last frame
        animating = false;  // animation done
        cameraMode=true;
    }

    SDL_RenderTexture(renderer, camera_array[animFrame], NULL, &cameradst);
}

}

        if(cameraMode){

            mainoffice->RenderCamera(state,cameralocation);

        }
      

        if(percentage>0){
        SDL_RenderTexture(renderer,text_texture,0,&timeText);
        SDL_RenderTexture(renderer,text_texture1,0,&nightText);

        SDL_RenderTexture(renderer,usage_texture,0,&usage);
        SDL_RenderTexture(renderer,power_left_texture,0,&powerleft);
        SDL_RenderTexture(renderer,powerbar[globalPowerUsage],0,&powerleft1);
        SDL_RenderTexture(renderer,percentage_texture,0,&percentage_coordinate);
        SDL_RenderTexture(renderer,flipper_texture,0,&flipper_coordinate);
        }
        
        }
        


        SDL_RenderPresent(renderer);
    }





    // Clean up
   
    MIX_DestroyTrack(ambienceTrack);
    MIX_DestroyTrack(sfxTrack1);
    MIX_DestroyTrack(sfxTrack);
    MIX_DestroyAudio(night1);
    MIX_DestroyAudio(ambience);
    MIX_DestroyAudio(staticSound);
    MIX_DestroyAudio(staticSound2);
    MIX_DestroyAudio(blip);
    MIX_DestroyMixer(mixer);
    TTF_CloseFont(font);
    MIX_Quit();
    return 0;
}