#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> //Para std::remove
#include <cctype>
#include "RN.h"
#include "song.h"

template<class TArbol>
bool addData(TArbol& arbol, const std::string& nomArch) {
    std::ifstream entrada(nomArch);
    if (!entrada)
        return false;

    std::string header;
    std::getline(entrada, header); //Para saltar la primera fila que tiene los nombres de las columnas

    std::string linea;
    while (std::getline(entrada, linea)) {
        if (linea.empty())
            continue; //Para saltar líneas vacías para evitar errores de lectura

        //Tokenizar y crear canción
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
            //Convertir strings a int porque había una confusión cuando había mas de 1 autor
            int popularity = std::stoi(popularitytxt);
            int durationMs = std::stoi(durationMstxt);
            bool explicitContent = (explicitContenttxt == "VERDADERO" || explicitContenttxt == "FALSO");

            //Crear la canción
            Song song(id, name, genre, artists, album, popularity, durationMs, explicitContent);

            //Insertar la canción en el árbol
            arbol.insert(song);
        }
        //Se pusieron estos catch para saber en que esta fallando lectura de ciertas lineas (resueltas)
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

int main() {
    std::string csvFileName = "test_all/add.csv"; 

    //Crear el árbol RN
    ArbolRN myTree;

    if (addData(myTree, csvFileName)) {
        std::cout << "Se añadieron los datos correctamente" << std::endl;

        //Imprimir el contenido del árbol
        std::cout << "Canciones en el árbol:" << std::endl;
        for (const auto& [id, song] : myTree.getArbolRN()) {
            std::cout << "ID: " << id << ", Nombre: " << song.getName() << std::endl;
        }
    }

    return 0;
}
