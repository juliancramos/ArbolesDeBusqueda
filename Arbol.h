#ifndef _ARBOL_H
#define _ARBOL_H

#include <string>

template<class TArbol>
bool addData(TArbol& arbol, const std::string& nomArch);

template<class TArbol>
bool searchData(TArbol& arbol, const std::string& id);

#include "Arbol.hxx"
#endif // _ARBOL_H
