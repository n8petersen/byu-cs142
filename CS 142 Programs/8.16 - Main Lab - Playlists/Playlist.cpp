#include <iostream>
#include <iomanip>
#include "Playlist.h"

// CONSTRUCTORS
Playlist::Playlist() { // Default Constructor
    name = "none";
}

Playlist::Playlist(std::string userPlaylistName) { // Main Constructor
    name = userPlaylistName;
}

// FUNCTIONS
std::string Playlist::GetName() const {
    return name;
}

void Playlist::AddSong(Song* song) {
    playlist.push_back(song);
}

void Playlist::RemoveSong(Song* song, int index) {
    playlist.erase(playlist.begin() + index);                                                           // Frees memory
}

void Playlist::DeleteSong(Song* song) {
    for (unsigned int i = 0; i < playlist.size(); i ++) {
        if (playlist.at(i) == song) {
            playlist.erase(playlist.begin() + i);                                                       // Frees Memory
            break;
        }
    }
}

void Playlist::PlaySongs() {
    Song* song;

    for (unsigned int i = 0; i < playlist.size(); i++) {
        song = playlist.at(i);
        std::cout << song->GetLine() << std::endl;
        song->AddPlay();
    }
}

void Playlist::ListSongs() {
    Song* song;
    for (unsigned int i = 0; i < playlist.size(); i++) {
        song = playlist.at(i);
        std::cout << i << ": " << song->GetName() << std::endl;
    }
}