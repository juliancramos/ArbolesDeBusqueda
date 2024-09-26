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

// Elimina un nodo del árbol.
template<class T>
void ArbolRN<T>::remove(std::string id) {
    arbolRN.erase(id); // Elimina el elemento con el id dado
}

// Busca un nodo en el árbol.
template<class T>
T* ArbolRN<T>::search(std::string id) {
    auto it = arbolRN.find(id);
    if (it != arbolRN.end()) {
        return &it->second;
    } else {
        return nullptr;
    }
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
ArbolRN<T>::ArbolRN() {
}

template<class T>
ArbolRN<T>::~ArbolRN() {
    // Puedes inicializar algo si es necesario
}
