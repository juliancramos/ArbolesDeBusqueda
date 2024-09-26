#ifndef _ARBOL_RN_H
#define _ARBOL_RN_H

#include <map>

template<class T>
class ArbolRN {
protected:
    std::map<std::string, T> arbolRN; // El mapa actúa como árbol de almacenamiento
public:
    ArbolRN();
    ~ArbolRN(); 

    std::map<std::string, T>& getArbolRN(); // Ref. al árbol
    void insert(T& item);
    bool remove(T val);
    T* search(T val);

    void inOrden() const; // función inorden
    void inOrden(typename std::map<std::string, T>::const_iterator it) const;
    
};

#include "RN.hxx"

#endif // _ARBOL_RN_H
