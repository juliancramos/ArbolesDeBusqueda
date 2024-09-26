#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> //Para std::remove
#include <cctype>
#include <ctime>
#include "song.h"
//To do #7,8,9
#include "RN.h"
#include "monticulo.h"
#include "ArbolAVL.h"
#include "Arbol.h"

int main(int argc, char* argv[]) {
    // std::string csvFileName = argv[1]; 
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <param1> <csv_file>" << std::endl;
        return 1; // Termina el programa con un código de error
    }

    
    //To do #10,11,12
    typedef ArbolAVL<Song> ArbolAVL_Song;
    typedef ArbolRN<Song> ArbolRN_Song;
    typedef Monticulo<Song> Monticulo_Song;
    //To do #13,14,15
    ArbolAVL_Song* myAVLTree = new ArbolAVL_Song();
    ArbolRN_Song* myRNTree = new ArbolRN_Song();
    Monticulo_Song* myHeap = new Monticulo_Song();

    

  
    //To do #16, 17. Se llama a la funcion addData, la cual tokeniza, crea un objeto de tipo song y la añade al arbol
    //Para el árbol AVL
    if (addData(myAVLTree, argv[1])) {
        std::cout << "\nSe añadieron los datos correctamente al árbol AVL" << std::endl;
    }

    // Para el árbol Roji-Negro
    if (addData(myRNTree, argv[1])) {
        std::cout << "\nSe añadieron los datos correctamente al árbol Rojo-Negro" << std::endl;
    }

    //Para el montículo
    if (addData(myHeap, argv[1])) {  
        std::cout << "\nSe añadieron los datos correctamente al montículo" << std::endl;
    }

    //To do #18
    // myRNTree->inOrden();
    // myAVLTree->inOrden();
    // myHeap->inOrden();

    //Falta el 19

    //Busqueda de datos
    //Heap
    std::clock_t inicioBusquedaHeap = std::clock();
    bool BusquedaHeap = searchData(myHeap, argv[2]);
    std::clock_t finBusquedaHeap = std::clock();
    
    double tiempoBusquedaHeap = (finBusquedaHeap - inicioBusquedaHeap) / double(CLOCKS_PER_SEC);

    if (BusquedaHeap) {
        std::cout << "Tiempo de busqueda monticulo = " << tiempoBusquedaHeap << " segs." << std::endl;
    } else {
        std::cout << "Error al leer \"" << argv[2] << "\" para busqueda en el monticulo." << std::endl;
    }
    //AVL
        std::clock_t inicioBusquedaAVL = std::clock();
    bool BusquedaAVL = searchData(myAVLTree, argv[2]);
    std::clock_t finBusquedaAVL = std::clock();
    
    double tiempoBusquedaAVL = (finBusquedaAVL - inicioBusquedaAVL) / double(CLOCKS_PER_SEC);
    
    if (BusquedaAVL) {
        std::cout << "Tiempo de busqueda AVL = " << tiempoBusquedaAVL << " segs." << std::endl;
    } else {
        std::cout << "Error al leer \"" << argv[2] << "\" para busqueda en el AVL." << std::endl;
    }
    
    //RN 
    std::clock_t inicioBusquedaRN = std::clock();
    bool BusquedaRN = searchData(myRNTree, argv[2]);
    std::clock_t finBusquedaRN = std::clock();
    
    double tiempoBusquedaRN = (finBusquedaRN - inicioBusquedaRN) / double(CLOCKS_PER_SEC);
    
    if (BusquedaRN) {
        std::cout << "Tiempo de busqueda Rojo-Negro = " << tiempoBusquedaRN << " segs." << std::endl;
    } else {
        std::cout << "Error al leer \"" << argv[2] << "\" para busqueda en el árbol Rojo-Negro." << std::endl;
    }
    

    
}
