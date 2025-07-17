#include <iostream>
#include <ctime>
#include "track.h"
#include "player.h"
#include "cci.h"

int main() {
    std::cout << "Hello!\n";
    std::srand(std::time(nullptr));
    Player myPlayer {};
    if(myPlayer.onPlauer() == false) {
        std::cout << "The player is not turned on!\n";
        return 1;
    }
    myPlayer.printPlailist();
    bool isGameOver {false};
    while(!isGameOver) {
        std::cout << "Command:\n\t(PLAY / PAUSE / STOP / NEXT / OFF)--> ";
        std::string command {correctCommandInput()};
        while(command != "play" 
                && command != "pause"
                && command != "stop"
                && command != "next"
                && command != "off") {
            std::cout << "--> ";
            command = correctCommandInput();
        }
        if(command == "play") {
            myPlayer.playTrack();
        } else if(command == "off") {
            std::cout << "Goodbye!\n";
            isGameOver = true;
        } else if(command == "pause") {
            myPlayer.pauseTrack();
        } else if(command == "stop") {
            myPlayer.stopTrack();
        } else if (command == "next") {
            myPlayer.nextTrack();
        }

    }

    return 0;
}