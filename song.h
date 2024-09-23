#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
    // Constructor
    Song(int id, std::string name, std::string genre,
         std::string artists, std::string album,
         int popularity, int durationMs, bool explicitContent);

    // Getters
    // TODO #2: Definir las funciones getters de cada uno de los campos que definen una cancion. (Total de getters: 8)
    // Setters
    // TODO #3: Definir las funciones setters de cada uno de los campos que definen una cancion. (Total de setters: 8)

    // Overloaded operators
    bool operator>(const Song& other) const;
    bool operator<(const Song& other) const;
    bool operator==(const Song& other) const;

private:
    // TODO #1: Definir cada uno de los campos de la cancion. (Total de campos: 8)
};

#endif // SONG_H