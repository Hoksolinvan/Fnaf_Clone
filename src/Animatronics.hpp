#pragma once

#include <random>
#include <cstdlib>
#include <SDL3_mixer/SDL_mixer.h>


class Animatronic {
public:
    virtual void Tick(bool OfficeDoor, bool monitor, int b, int c) = 0;
    virtual int isInRoom();
    virtual ~Animatronic() = default;
};



class Bonnie : public Animatronic {

    public:
    bool playerDeath = false;

    Bonnie(int Difficulty): Difficulty(Difficulty){

    }

    void Tick(bool OfficeDoor, bool monitor, int ChikaRoom, int FreddyRoom){
        if(inRoom == 8 && OfficeDoor && monitor){
            inRoom = 9;
            playerDeath=true;
        }
    
        int rand1 = 1 + std::rand() % Difficulty;

        if(rand1==Difficulty){
            return;
        }
        else{
            int rand2 = 1 + std::rand() % 8;
            if(rand2 >=4){
                if(rand2>=inRoom){
                    if(ChikaRoom == inRoom +1 || FreddyRoom == inRoom+1){
                        return;
                    }
                    else{
                        if(inRoom + 1 > 8){
                            return;
                        }
                        else{
                            inRoom++;
                        }
                    }
                }
                else{
                    return;
                }
            }

            else{
                if(rand2 >= inRoom){
                    if(ChikaRoom == inRoom +1 || FreddyRoom == inRoom+1){
                        return;
                    }
                    else{
                        if(inRoom + 1 > 8){
                            return;
                        }
                        else{
                            inRoom++;
                        }
                    }
                }
                else{
                    if(rand2==inRoom){
                        if(ChikaRoom == inRoom + 1 || FreddyRoom == inRoom + 1){


                            return;
                        }
                        else{

                            inRoom--;
                        }


                        return;



                    }

                    return;
                }
            }


        }

    }

    int isInRoom(){
        return inRoom;
    }



    private:
    int inRoom;
    int Difficulty;

};


class Chika : public Animatronic{


    public:
    bool playerDeath = false;

    Chika(int Difficulty): Difficulty(Difficulty){

    }


    void Tick(bool OfficeDoor, bool monitor, int BonnieRoom, int FreddyRoom){
        if(inRoom == 8 && OfficeDoor && monitor){
            inRoom = 9;
            playerDeath=true;
            return;
        }
    
        int rand1 = 1 + std::rand() % Difficulty;

        if(rand1==Difficulty){
            return;
        }
        else{
            int rand2 = 1 + std::rand() % 8;
            if(rand2 >=4){
                if(rand2>=inRoom){
                    if(BonnieRoom == inRoom +1 || FreddyRoom == inRoom+1){
                        return;
                    }
                    else{
                        if(inRoom + 1 > 8){
                            return;
                        }
                        else{
                            inRoom++;
                        }
                    }
                }
                else{
                    return;
                }
            }

            else{
                if(rand2 >= inRoom){
                    if(BonnieRoom == inRoom +1 || FreddyRoom == inRoom+1){
                        return;
                    }
                    else{
                        if(inRoom + 1 > 8){
                            return;
                        }
                        else{
                            inRoom++;
                        }
                    }
                }
                else{
                    if(rand2==inRoom){
                        if(BonnieRoom == inRoom + 1 || FreddyRoom == inRoom + 1){


                            return;
                        }
                        else{

                            inRoom--;
                        }


                        return;



                    }

                    return;
                }
            }


        }

    }




     int isInRoom(){
        return inRoom;
    }

    private:
    int inRoom;
    int Difficulty;

};



class Freddy: public Animatronic{


    public: 
    bool playerdeath  = false;


    Freddy(int Difficulty) : Difficulty(Difficulty){

    }
    int isInRoom(){
        return inRoom;
    }

    void Tick(bool OfficeDoor, bool monitor, int BonnieRoom, int ChikaRoom){

        if(inRoom==0 && BonnieRoom==0 && ChikaRoom==0){
            return;
        }
        if(monitor && OfficeDoor && inRoom==4){
            if(OfficeDoor==true){
                playerdeath = true;
                inRoom = 5;
            }

        }
        else{
            if(inRoom != 4){
                if(ChikaRoom == inRoom+1 || BonnieRoom == inRoom+1){
                    return;
                }
                else{
                    inRoom++;
                    return;
                }
            } else{
                if(ChikaRoom == inRoom+1 || BonnieRoom == inRoom+1){
                    return;
                }
                else{
                    inRoom--;
                    return;
                }
            }
        }
    }


    private:
    int Difficulty;
    int inRoom;

};


class Foxy : public Animatronic{


public:
bool playerdeath = false;

Foxy(int Difficulty) : Difficulty(Difficulty){

}

void tick(bool monitor, bool pirateCove, bool OfficeDoor,bool dummy){
    if(monitor && pirateCove){
        return;
    }
    else{
        if(stage!=3){
            stage++;

        }
        else{
            if(!OfficeDoor){
                stage = 1;
            }
            else{
                playerdeath=true;
            }
        }
    }
}


private:
int Difficulty;
int stage;
bool seen;
double startTime;

};