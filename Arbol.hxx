#ifndef _ARBOL_HXX_
#define _ARBOL_HXX_

#include "Arbol.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "song.h" 

template<class TArbol>
bool addData(TArbol& arbol, const std::string& nomArch) {
    std::ifstream entrada(nomArch);
    if (!entrada)
        return false;

    std::string header;
    std::getline(entrada, header); // Para saltar la primera fila que tiene los nombres de las columnas

    std::string linea;
    while (std::getline(entrada, linea)) {
        if (linea.empty())
            continue; // Para saltar líneas vacías para evitar errores de lectura

        // Tokenizar y crear canción
        std::stringstream ss(linea);
        std::string id, name, genre, artists, album, popularitytxt, durationMstxt, explicitContenttxt;

        std::getline(ss, id, ';');
        std::getline(ss, name, ';');
        std::getline(ss, genre, ';');
        std::getline(ss, artists, ';'); 
        std::getline(ss, album, ';');
        std::getline(ss, popularitytxt, ';');
        std::getline(ss, durationMstxt, ';');
        std::getline(ss, explicitContenttxt, ';');

        try {
            // Convertir strings a int
            int popularity = std::stoi(popularitytxt);
            int durationMs = std::stoi(durationMstxt);
            bool explicitContent = (explicitContenttxt == "VERDADERO" || explicitContenttxt == "FALSO");

            // Crear la canción
            Song song(id, name, genre, artists, album, popularity, durationMs, explicitContent);

            // Insertar la canción en el árbol
            arbol->insert(song); // Asegúrate de que la inserción se llame correctamente
        }
        // Manejo de excepciones
        catch (const std::invalid_argument& e) {
            std::cerr << "Argumento inválido: " << e.what() << " para la línea: " << linea << std::endl;
            continue;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error número fuera de rango: " << e.what() << " para la línea: " << linea << std::endl;
            continue;
        }
    }
    entrada.close();
    return true;
}

template <class TArbol>
bool searchData(TArbol& arbol, const std::string& id) {
    // Llama al método search del árbol
    return arbol->search(Song(id)); 
}
template <class TArbol>
bool deleteData(TArbol& arbol, const std::string& id) {
    // Llama al método search del árbol para verificar si la canción existe
    bool esta = arbol->search(Song(id)); 

    if (esta) {
        // Si la canción existe, la elimina
        arbol->remove(Song(id));
        return true;  
    }
    return false; 
}


#endif // _ARBOL_HXX_
