#include "song.h"

// Constructor
Song::Song(std::string id, std::string name, std::string genre,
           std::string artists, std::string album,
           int popularity, int durationMs, bool explicitContent)
    : id(id), name(name), genre(genre), artists(artists),
      album(album), popularity(popularity),
      durationMs(durationMs), explicitContent(explicitContent) {}


// Getters
std::string Song::getId() const {
    return id;
}

std::string Song::getName() const {
    return name;
}

std::string Song::getGenre() const {
    return genre;
}

std::string Song::getArtists() const {
    return artists;
}

std::string Song::getAlbum() const {
    return album;
}

int Song::getPopularity() const {
    return popularity;
}

int Song::getDurationMs() const {
    return durationMs;
}

bool Song::isExplicitContent() const {
    return explicitContent;
}

// Setters
void Song::setId(const std::string& newId) {
    id = newId;
}

void Song::setName(const std::string& newNombre) {
    name = newNombre;
}

void Song::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void Song::setArtists(const std::string& newArtists) {
    artists = newArtists;
}

void Song::setAlbum(const std::string& newAlbum) {
    album = newAlbum;
}

void Song::setPopularity(int newPopularity) {
    popularity = newPopularity;
}

void Song::setDurationMs(int newDurationMs) {
    durationMs = newDurationMs;
}

void Song::setExplicitContent(bool newExplicitContent) {
    explicitContent = newExplicitContent;
}


// Overloaded operators
bool Song::operator>(const Song& other) const {
    return this->getId() > other.getId();
}

bool Song::operator<(const Song& other) const {
    return this->getId() < other.getId();
}

bool Song::operator==(const Song& other) const {
    return this->getId() == other.getId();
}