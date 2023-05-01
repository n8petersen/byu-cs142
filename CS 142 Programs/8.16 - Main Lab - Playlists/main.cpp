#include <iostream>
#include <string>
#include <vector>

#include "Song.h"
#include "Playlist.h"

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(std::vector<Song*>& songs);
void ListSongsMenuOption(std::vector<Song*> songs);
void AddPlaylistMenuOption(std::vector<Playlist>& playlists);
void AddSongToPlaylistMenuOption(std::vector<Playlist>& playlists, std::vector<Song*> songs);
void ListPlaylistsMenuOption(std::vector<Playlist> playlists);
void PlayPlaylistMenuOption(std::vector<Playlist> playlists);
void RemovePlaylistMenuOption(std::vector<Playlist>& playlists);
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist>& playlists, std::vector<Song*> songs);
void RemoveSongFromLibraryMenuOption(std::vector<Playlist>& playlists, std::vector<Song*>& songs);
void OptionsMenuOption();
void QuitMenuOption();
void ClearMemory(std::vector<Playlist>& playlists, std::vector<Song*>& songs);

int main() {
    std::vector<Song*> songs;
    std::vector<Playlist> playlists;

    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songs);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(songs);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(playlists, songs);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlists);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlists, songs);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(playlists, songs);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "clear") {
            ClearMemory(playlists, songs);
        }
        else if (userMenuChoice == "quit") {
            ClearMemory(playlists, songs);
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}

std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(std::vector<Song*>& songs) {
    Song* ptrSong;
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");

    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        ptrSong = new Song(songName, firstLine);
        songs.push_back(ptrSong);

        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(std::vector<Song*> songs) {
    for (unsigned int i = 0; i < songs.size(); i++) {
        std::cout << songs[i]->GetName() << ": \"" << songs[i]->GetLine() << "\", " << songs[i]->GetPlays() << " play(s)." << std::endl;
    }
}

void AddPlaylistMenuOption(std::vector<Playlist>& playlists) {
    std::string userPlaylistName = "none";

    userPlaylistName = GetUserString("Playlist Name: ");

    Playlist item(userPlaylistName);
    playlists.push_back(item);
}

void AddSongToPlaylistMenuOption(std::vector<Playlist>& playlists, std::vector<Song*> songs) {
    int playlistIndex;
    int songIndex;

    for (unsigned int i = 0; i < playlists.size(); i++) {
        std::cout << i << ": " << playlists[i].GetName() << std::endl;
    }
    playlistIndex = GetUserInt("Pick a playlist index number: ");
    Playlist* playlist = &playlists.at(playlistIndex);

    for (unsigned int i = 0; i < songs.size(); i++) {
        std::cout << i << ": " << songs[i]->GetName() << std::endl;
    }
    songIndex = GetUserInt("Pick a song index number: ");
    Song* song = songs.at(songIndex);

    playlist->AddSong(song);
}

void ListPlaylistsMenuOption(std::vector<Playlist> playlists) {
    for (unsigned int i = 0; i < playlists.size(); i++) {
        std::cout << i << ": " << playlists[i].GetName() << std::endl;
    }
}

void PlayPlaylistMenuOption(std::vector<Playlist> playlists) {
    int playlistIndex;

    for (unsigned int i = 0; i < playlists.size(); i++) {
        std::cout << i << ": " << playlists[i].GetName() << std::endl;
    }

    playlistIndex = GetUserInt("Pick a playlist index number: ");
    Playlist userPlaylist = playlists.at(playlistIndex);


    std::cout << "Playing songs from playlist: " << userPlaylist.GetName() << std::endl;
    userPlaylist.PlaySongs();
}

void RemovePlaylistMenuOption(std::vector<Playlist>& playlists) {
    int playlistIndex;

    for (unsigned int i = 0; i < playlists.size(); i++) {
        std::cout << i << ": " << playlists[i].GetName() << std::endl;
    }
    playlistIndex = GetUserInt("Pick a playlist index number to remove: ");

    playlists.erase(playlists.begin() + playlistIndex);                                               // Frees memory
}

void RemoveSongFromPlaylistMenuOption(std::vector<Playlist>& playlists, std::vector<Song*> songs) {
    int playlistIndex;
    int songIndex;

    for (unsigned int i = 0; i < playlists.size(); i++) {
        std::cout << i << ": " << playlists[i].GetName() << std::endl;
    }
    playlistIndex = GetUserInt("Pick a playlist index number: ");
    Playlist* playlist = &playlists.at(playlistIndex);

    playlist->ListSongs();

    songIndex = GetUserInt("Pick a song index number to remove: ");
    Song* song = songs.at(songIndex);

    playlist->RemoveSong(song, songIndex);                                                          // (Frees memory)
}

void RemoveSongFromLibraryMenuOption(std::vector<Playlist>& playlists, std::vector<Song*>& songs) {
    int songIndex;

    for (unsigned int i = 0; i < songs.size(); i++) {
        std::cout << i << ": " << songs[i]->GetName() << std::endl;
    }
    songIndex = GetUserInt("Pick a song index number to remove: ");
    Song* song = songs.at(songIndex);

    for (unsigned int i = 0; i < playlists.size(); i++) {
        Playlist* playlist = &playlists.at(i);
        playlist->DeleteSong(song);                                                               // (Frees memory)
    }

    songs.erase(songs.begin() + songIndex);                                                       // Frees memory
    delete song;                                                                                    // Frees memory
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye!" << std::endl;
}

void ClearMemory(std::vector<Playlist>& playlists, std::vector<Song*>& songs) {                         // Frees Memory
    playlists.clear();
    songs.clear();
}
