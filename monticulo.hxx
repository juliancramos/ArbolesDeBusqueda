#include "monticulo.h"
#include <algorithm>

template <class T>
Monticulo<T>::Monticulo(){
    
}

template <class T>
Monticulo<T>:: ~Monticulo(){

}

template <class T>
bool Monticulo<T>:: esVacio(){
    return vec.empty();
}

template <class T>
bool Monticulo<T>:: insertar(T val){
 vec.push_back(val);
 vec.push_heap(vec.begin(), vec.end());
 
 return true;
}

template<class T>
bool Monticulo<T>:: eliminar(T val){
    // Buscar el dato en el vector con un for
     std::deque<T>::iterator it;
     for(it=vec.begin(); it!= vec.end(), it++){
        if(*it=val){
        std::pop_heap(vec.begin(), vec.end());
        T elim_data = vec.back();
        // Eliminar esa posicion del vector
        vec.pop_back();

        //Organizar denuevo el heap con la funcion 
        std::make_heap(vec.begin(), vec.end());
        
        return true;
        }
        
     }
     return true;
}

template <class T>
bool Monticulo<T>:: buscar(T val){
std::deque<T>::iterator it;
for(it=vec.begin ; it!=vec.end(); it++){
    if(*it == val){
        return true;
    }
}

return false;
}