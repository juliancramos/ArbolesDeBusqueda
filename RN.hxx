#include "RN.h"

// Devuelve una referencia al árbol de tipo map.
template<class T>
std::map<std::string, T>& ArbolRN<T>::getArbolRN() {
    return arbolRN;
}

// Inserta un nuevo nodo en el árbol.
template<class T>
void ArbolRN<T>::insert(T& item) {
    arbolRN.insert({ item.getId(), item }); 
}

template<class T>
void ArbolRN<T>::inOrden() const {
    inOrden(arbolRN.cbegin());
}

template<class T>
void ArbolRN<T>::inOrden(typename std::map<std::string, T>::const_iterator it) const {
    if (it == arbolRN.cend()) {
        return; // Caso base para terminar la recursión
    }
    std::cout << "ID: " << it->first << ", Nombre: " << it->second.getName() << std::endl;
    inOrden(++it); // Avanza al siguiente elemento y llama recursivamente
}

template<class T>
bool ArbolRN<T>::remove(T val) {
    std::string key = val.getKey();
    auto it = arbolRN.fin(key);
    if (it != arbolRN.end()) {
        arbolRN.erase(it); 
        return true; 
    }
    return false; 
}

// RN.hxx
template <class T>
T* ArbolRN<T>::search(T val) {
    std::string key = val.getKey();
    auto it = arbolRN.find(key); 

    if (it != arbolRN.end()) {
        return &it->second; 
    }
    return nullptr;
}


template<class T>
ArbolRN<T>::ArbolRN() {
}
template<class T>
ArbolRN<T>::~ArbolRN() {
}
