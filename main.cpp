#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> //Para std::remove
#include <cctype>
#include "song.h"
//To do #7,8,9
#include "RN.h"
#include "monticulo.h"
#include "ArbolAVL.h"
#include "Arbol.h"

int main() {
    std::string csvFileName = "test_all/add.csv"; 

    
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
    if (addData(myAVLTree, csvFileName)) {
        std::cout << "\nSe añadieron los datos correctamente al árbol AVL" << std::endl;
    }

    // Para el árbol Roji-Negro
    if (addData(myRNTree, csvFileName)) {
        std::cout << "\nSe añadieron los datos correctamente al árbol Rojo-Negro" << std::endl;
    }

    //Para el montículo
    if (addData(myHeap, csvFileName)) {  
        std::cout << "\nSe añadieron los datos correctamente al montículo" << std::endl;
    }

    //To do #18
    myRNTree->inOrden();
    myAVLTree->inOrden();
    myHeap->inOrden();


    

    return 0;
}
