#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include "track.h"

/*Track::Track() {
    for (int i {0}; i < ((std::rand() % 7) + 6); ++i) {
        char letter = (char)((std::rand() % 26) + 97);            
        title.push_back(letter);
    }
    recDurationSecond = std::rand() % 120 + 180; 
    creationDate.tm_year = std::rand() % 125;
    creationDate.tm_mon = std::rand() % 12 + 1;
    creationDate.tm_mday = std::rand() % 27 + 1;
}*/

Track::Track(std::tm crD, int recDur, std::string tttl) {
    creationDate = crD;
    recDurationSecond = recDur;
    title = tttl; 
}

Track::Track() {}

void Track::printTrack() {
    std::time_t tRec = std::mktime(&creationDate);
    std::cout << title << ", duration "
              << recDurationSecond << " sec, created "
              << std::put_time(std::gmtime(&tRec), "%d.%m.%Y") << ", ";
}

std::tm Track::getCreationDate() {
    return creationDate;
}

int Track::getRecDuration() {
    return recDurationSecond;
}

std::string Track::getTitle() {
    return title;
}
