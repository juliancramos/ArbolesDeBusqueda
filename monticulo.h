#ifndef _MONTICULO_H__
#define _MONTICULO_H__

template class <T>

#include <deque>
#include <algorithm>

class Monticulo{
    protected:
    std::deque<T> vec;

    public:
    Monticulo();
    ~Monticulo();
    bool esVacio();
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
}
