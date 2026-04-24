#pragma once

#include <random>
#include <cstdlib>
#include <SDL3_mixer/SDL_mixer.h>

class Animatronic {
public:
    bool playerDeath = false;
    virtual void Tick(bool OfficeDoor, bool monitor, int b, int c)=0;
    virtual int isInRoom() =0;
    virtual ~Animatronic() = default;
};


class Bonnie : public Animatronic {

public:
    

    Bonnie(int aiLevel) : aiLevel(aiLevel), inRoom(0), doorBlockTimer(0){
    }

    void Tick(bool OfficeDoor, bool monitor, int dummy1, int dummy2){

        if(inRoom == 8 && !OfficeDoor){
            doorBlockTimer++;
            if(doorBlockTimer > 300){
                inRoom = 0;
                doorBlockTimer = 0;
            }
            return;
        }

        if(inRoom == 8 && OfficeDoor){
            playerDeath = true;
            return;
        }

        doorBlockTimer = 0;

        // roll 1-20, move if roll <= aiLevel
        int roll = 1 + std::rand() % 20;
        if(roll <= aiLevel){
            inRoom++;
        }
    }

    int isInRoom(){
        return inRoom;
    }

private:
    int aiLevel;
    int inRoom;
    int doorBlockTimer;
};


class Chika : public Animatronic {

public:
    

    Chika(int aiLevel) : aiLevel(aiLevel), inRoom(0), doorBlockTimer(0){
    }

    void Tick(bool OfficeDoor, bool monitor, int dummy1, int dummy2){

        if(inRoom == 8 && !OfficeDoor){
            doorBlockTimer++;
            if(doorBlockTimer > 300){
                inRoom = 0;
                doorBlockTimer = 0;
            }
            return;
        }

        if(inRoom == 8 && OfficeDoor){
            playerDeath = true;
            return;
        }

        doorBlockTimer = 0;

        // roll 1-20, move if roll <= aiLevel
        int roll = 1 + std::rand() % 20;
        if(roll <= aiLevel){
            inRoom++;
        }
    }

    int isInRoom(){
        return inRoom;
    }

private:
    int aiLevel;
    int inRoom;
    int doorBlockTimer;
};


class Freddy : public Animatronic {

public:
    

    Freddy(int aiLevel) : aiLevel(aiLevel), inRoom(0), doorBlockTimer(0){
    }

    void Tick(bool OfficeDoor, bool monitor, int dummy1, int dummy2){

        if(inRoom == 8 && !OfficeDoor){
            doorBlockTimer++;
            if(doorBlockTimer > 300){
                inRoom = 0;
                doorBlockTimer = 0;
            }
            return;
        }

        if(inRoom == 8 && OfficeDoor){
            playerDeath = true;
            return;
        }

        doorBlockTimer = 0;

        // freddy only moves when camera is NOT on his current room
        // monitor == true means player is watching cameras
        // in real fnaf freddy only moves in the dark
        if(monitor){
            return;
        }

        // roll 1-20, move if roll <= aiLevel
        int roll = 1 + std::rand() % 20;
        if(roll <= aiLevel){
            inRoom++;
        }
    }

    int isInRoom(){
        return inRoom;
    }

private:
    int aiLevel;
    int inRoom;
    int doorBlockTimer;
};


class Foxy : public Animatronic {

public:
  

    Foxy(int aiLevel) : aiLevel(aiLevel), stage(0), checkCount(0), runTimer(0){
    }

    // call this whenever the player looks at pirate cove camera
    void OnCameraCheck(){
        checkCount++;
    }

    void Tick(bool OfficeDoor, bool monitor, int dummy1, int dummy2){

        // roll 1-20, if fail do nothing
        int roll = 1 + std::rand() % 20;
        if(roll > aiLevel){
            return;
        }

        // how often player has checked pirate cove determines run speed
        // more checks = slower foxy
        // fewer checks = faster foxy
        int runThreshold;
        if(checkCount >= 10){
            runThreshold = 500;   // checked a lot, foxy is slow
        } else if(checkCount >= 5){
            runThreshold = 300;
        } else if(checkCount >= 2){
            runThreshold = 150;
        } else {
            runThreshold = 50;    // barely checked, foxy is very fast
        }

        runTimer++;

        if(stage == 0){
            // peeking out slightly
            if(runTimer >= runThreshold){
                stage = 1;
                runTimer = 0;
            }
        }
        else if(stage == 1){
            // peeking out more
            if(runTimer >= runThreshold){
                stage = 2;
                runTimer = 0;
            }
        }
        else if(stage == 2){
            // about to run
            if(runTimer >= runThreshold){
                stage = 3;
                runTimer = 0;
            }
        }
        else if(stage == 3){
            // running at the door
            if(!OfficeDoor){
                // door is closed, blocked
                stage = 0;
                checkCount = 0;
                runTimer = 0;
            }
            else{
                playerDeath = true;
            }
        }
    }

    int getStage(){
        return stage;
    }

    int isInRoom(){
        return -1;
    }

private:
    int aiLevel;
    int stage;
    int checkCount;
    int runTimer;
};