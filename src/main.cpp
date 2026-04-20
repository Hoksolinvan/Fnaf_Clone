#include "mainmenu.h"
#include "mainoffice.h"
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

const int window_x = 1280;
const int window_y = 720;
bool running = true;
bool main_menu = true;
bool main_game = false;
bool main_office = false;
bool default_main_menu = true;
int main_menu_state = 0;
int alpha = 240;
bool pressed_E = false;


int main(int argc, char* argv[]){
    srand(time(0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    std::uniform_int_distribution<int> dist2(0, 9);
    std::uniform_int_distribution<int> dist3(0,14);
    std::uniform_int_distribution<int> random_number(0,100);
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
    MIX_Audio* ambience = MIX_LoadAudio(mixer, "assets/sounds/ambience2.wav", false);
    MIX_Audio* staticSound  = MIX_LoadAudio(mixer, "assets/sounds/static.wav", false);
    MIX_Audio* staticSound2 = MIX_LoadAudio(mixer, "assets/sounds/static2.wav", false);
    MIX_Audio* blip         = MIX_LoadAudio(mixer, "assets/sounds/blip3.wav", false);
    MIX_Audio* night1 = MIX_LoadAudio(mixer,"assets/sounds/voiceover1c.wav",false);
    MIX_Track* sfxTrack = MIX_CreateTrack(mixer);
    MIX_Track* sfxTrack1 = MIX_CreateTrack(mixer);
    MIX_Track* ambienceTrack = MIX_CreateTrack(mixer);
    MIX_SetTrackAudio(ambienceTrack, ambience);

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetNumberProperty(props, MIX_PROP_PLAY_LOOPS_NUMBER, -1); // -1 = loop forever
    MIX_PlayTrack(ambienceTrack, props);
    SDL_DestroyProperties(props);


    TTF_Font* font =  TTF_OpenFont("external/textfiles/consolas.ttf",64);
    SDL_Color color = {255,255,255,255};
    SDL_FRect dst = {1075/2,500/2,200,50};
    SDL_FRect dst1 = {1075/2,600/2,200,50};
    SDL_Surface* textSurface = TTF_RenderText_Blended(font,"12:00",0,color);
    SDL_Surface* textSurface1 = TTF_RenderText_Blended(font,"Night 1",0,color);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer,textSurface);
    SDL_Texture* text_texture1 = SDL_CreateTextureFromSurface(renderer,textSurface1);

    TTF_CloseFont(font);
    SDL_DestroySurface(textSurface);
    SDL_DestroySurface(textSurface1);
   

    while(running){


        frame++;

        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        Uint64 now = SDL_GetTicks();
        float dt = (now - last_time) / 1000.0f;
        last_time = now;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                running = false;
            }
             if(event.type==SDL_EVENT_MOUSE_BUTTON_DOWN){

                if(main_menu){
            
                int mouseX_button = event.button.x;
                int mouseY_button = event.button.y;
               if(mouseX_button>=75 && mouseX_button<=450 && mouseY_button>=300 && mouseY_button<=500){
                main_menu = false;
                main_game = true;
                MIX_SetTrackAudio(sfxTrack, blip);
                MIX_PlayTrack(sfxTrack, 0);

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
                main_game=false;
                main_office = true;
            }
        }
        else if(main_office){


            if(pressed_E){
                MIX_StopTrack(sfxTrack1,0);
            }

            else if(!MIX_TrackPlaying(sfxTrack1)){
            
            if(!pressed_E){
              MIX_SetTrackAudio(sfxTrack1, night1);
            MIX_PlayTrack(sfxTrack1, 0);
            }
        }
      
          
            

            mainoffice->RenderOffice();

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
    MIX_Quit();
    return 0;
}