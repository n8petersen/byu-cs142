#include <iostream>
#include <iomanip>
#include "Song.h"

// CONSTRUCTORS
Song::Song() { // Default Constructor
    name = "none";
    line = "none";
    plays = 0;
}
Song::Song(std::string songName, std::string firstLine) { // Main Constructor
    name = songName;
    line = firstLine;
    plays = 0;
}

// FUNCTIONS
std::string Song::GetName() const {
    return name;
}

std::string Song::GetLine() const {
    return line;
}

int Song::GetPlays() const {
    return plays;
}

void Song::AddPlay() {
    plays = plays + 1;
}