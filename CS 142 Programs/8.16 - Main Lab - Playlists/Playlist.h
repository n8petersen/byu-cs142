#ifndef INC_8_16_MAIN_LAB___PLAYLISTS_PLAYLIST_H
#define INC_8_16_MAIN_LAB___PLAYLISTS_PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"

class Playlist {
public:
    Playlist(); // Default Constructor
    Playlist(std::string userPlaylistName);

    void AddSong(Song* song);
    void RemoveSong(Song* song, int index);
    void DeleteSong(Song* song);
    void PlaySongs();
    void ListSongs();

    std::string GetName() const;

private:
    std::string name;
    std::vector<Song*> playlist;
};

#endif //INC_8_16_MAIN_LAB___PLAYLISTS_PLAYLIST_H
