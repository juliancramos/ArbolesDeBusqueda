#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <map>
#include "song.h"


class ArbolRN {
  private:
    std::map<std::string, Song> arbolRN; // mapa actua como arbol almacenamiento
  public:
    ArbolRN() = default;
    ~ArbolRN() = default;
    std::map<std::string, Song>& getArbolRN(); // Ref. al arbol
    void insert(Song& song);
    void remove(std::string id);
    Song* search(std::string id);

};
#include "RN.hxx"


#endif // ARBOLRN_H

