#include "RN.h"

//Devuelve una referencia al arbol de tipo map.
std::map<std::string, Song>& ArbolRN::getArbolRN() {
    return arbolRN;
}

//Inserta un nuevo nodo en el arbol.
void ArbolRN::insert(Song& song) {
    arbolRN.insert({ song.getId(), song }); 
}

//Para PROBAR DESPUES
//Elimina un nodo del árbol.
void ArbolRN::remove(std::string id) {
    arbolRN.erase(id); //Elimina la cancion con el id dado
}

//Busca un nodo en el árbol.
Song* ArbolRN::search(std::string id) {
    auto it = arbolRN.find(id);
    if (it != arbolRN.end()) {
        return &it->second;
    } else {
        return nullptr;
    }
}
