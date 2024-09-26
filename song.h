#ifndef SONG_H
#define SONG_H

#include <string>
#include <ostream>
class Song {

    private:
    std::string id;
    std::string name;
    std::string genre;
    std::string artists;
    std::string album;
    int popularity;
    int durationMs;
    bool explicitContent; //Identifica si la canción contiene contenido explicito

    public:
        // Constructor
        Song(std::string id, std::string name, std::string genre,
            std::string artists, std::string album,
            int popularity, int durationMs, bool explicitContent);

    Song() : id(""), name(""), genre(""), artists(""), album(""), popularity(0), durationMs(0), explicitContent(false) {}

        friend std::ostream& operator<<(std::ostream& os, const Song& song); //Se usa para imprimer los datos de tipo song

        // Getters
        std::string getId() const;
        std::string getName() const;
        std::string getGenre() const;
        std::string getArtists() const;
        std::string getAlbum() const;
        int getPopularity() const;
        int getDurationMs() const;
        bool isExplicitContent() const;

        // Setters
        void setId(const std::string& id);
        void setName(const std::string& nombre);
        void setGenre(const std::string& genre);
        void setArtists(const std::string& artists);
        void setAlbum(const std::string& album);
        void setPopularity(int popularity);
        void setDurationMs(int durationMs);
        void setExplicitContent(bool explicitContent);

        // Overloaded operators
        bool operator>(const Song& other) const;
        bool operator<(const Song& other) const;
        bool operator==(const Song& other) const;

};

#endif // SONG_H