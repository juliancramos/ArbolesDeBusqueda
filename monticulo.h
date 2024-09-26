#ifndef _MONTICULO_H__
#define _MONTICULO_H__

#include <deque>
#include <algorithm>

template <class T>

#include <deque>
#include <algorithm>

class Monticulo{
    protected:
    std::deque<T> vec;

    public:
    Monticulo();
    ~Monticulo();
    bool esVacio();
    bool insert(T val);
    bool eliminar(T val);
    bool buscar(T val);

    void inOrden() const;
};
#include "monticulo.hxx"

#endif
