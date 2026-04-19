#include "mainmenu.h"


#include <SDL3/SDL.h>


const int window_x = 1000;
const int window_y = 1000;
bool running = true;
bool main_menu = true;
bool default_main_menu = true;
int main_menu_state = 0;

int main(int argc, char* argv[]){
    srand(time(0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    std::uniform_int_distribution<int> dist2(0, 9);
    std::uniform_int_distribution<int> random_number(0,100);
    SDL_Event event;
    

    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
        std::cerr << SDL_GetError() << "\n";

        return -1;
    }


    // Load the WAV file
    SDL_AudioSpec spec;
    Uint8* wav_data;
    Uint32 wav_length;
    SDL_LoadWAV("assets/sounds/static.wav", &spec, &wav_data, &wav_length);

    SDL_AudioSpec spec2;
    Uint8* wav_data2;
    Uint32 wav_length2;
    SDL_LoadWAV("assets/sound/static2.wav",&spec2,&wav_data2,&wav_length2);

    // Create a stream and bind it to the default device
    SDL_AudioStream* stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);


    // Put the audio data into the stream
    SDL_PutAudioStreamData(stream, wav_data, wav_length);
    SDL_PutAudioStreamData(stream, wav_data2, wav_length2);



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

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    

    SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);


    if(!renderer){
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::cerr << SDL_GetError() << "\n";
        return -1;
    }

    MainMenu* main_menu_object = new MainMenu(w,h,renderer);
    Uint64 last_time = SDL_GetTicks();

    uint32_t frame =0;

    while(running){
        frame++;

        SDL_RenderClear(renderer);
        Uint64 now = SDL_GetTicks();
        float dt = (now - last_time) / 1000.0f;
        last_time = now;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                running = false;
            }

        }

        
        if(main_menu){

           SDL_ResumeAudioStreamDevice(stream);
           if (SDL_GetAudioStreamAvailable(stream) < (int)wav_length+wav_length2) {
            SDL_PutAudioStreamData(stream, wav_data, wav_length);
            SDL_PutAudioStreamData(stream, wav_data2, wav_length2);
            
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

            main_menu_object->staticTexture(dist2(rd));
        }


        SDL_RenderPresent(renderer);
    }





    // Clean up

    SDL_DestroyAudioStream(stream);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}