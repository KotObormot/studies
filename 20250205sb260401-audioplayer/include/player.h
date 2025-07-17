#pragma once
#include <fstream>
#include <map>
#include <track.h>

class Player {
  private:
    std::map<size_t, Track> play_list;
    int playerMode;
    std::map<size_t, Track>::iterator iterFound {};       
    bool loadPlaylist();
    bool searchTrack(std::string nameTrack);
    void searchNum();
    //void createPlaylist(int playlistVolume);
  public:
    void printPlailist();
    bool onPlauer();
    void playTrack();
    void pauseTrack();
    void stopTrack();
    void nextTrack();
};