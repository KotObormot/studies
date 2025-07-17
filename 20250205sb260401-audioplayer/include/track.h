#pragma once

class Track {
  private:
    std::tm creationDate;
    int recDurationSecond;
    std::string title;
  public:
    Track();
    Track(std::tm crD, int recDur, std::string tttl);
    void printTrack();
    std::tm getCreationDate();
    int getRecDuration();
    std::string getTitle();
};
