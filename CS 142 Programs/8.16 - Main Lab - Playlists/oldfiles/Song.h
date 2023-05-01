#ifndef INC_8_16_MAIN_LAB___PLAYLISTS_SONG_H
#define INC_8_16_MAIN_LAB___PLAYLISTS_SONG_H

#include <string>

class Song {
public:
    Song(); // Default Constructor
    Song(std::string songName, std::string firstLine);

    std::string GetName() const;
    std::string GetLine() const;
    int GetPlays() const;

    void AddPlay();

private:
    std::string name;
    std::string line;
    int plays;

};

#endif //INC_8_16_MAIN_LAB___PLAYLISTS_SONG_H
