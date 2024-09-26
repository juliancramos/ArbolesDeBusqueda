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
bool Monticulo<T>:: insert(T val){
 vec.push_back(val);
 std::push_heap(vec.begin(), vec.end());
 
 return true;
}

template<class T>
bool Monticulo<T>:: remove(T val){
    // Buscar el dato en el vector con un for
    typename std::deque<T>::iterator it;
     for(it=vec.begin(); it!= vec.end() ; it++){
        if(*it == val){
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
bool Monticulo<T>:: search(T val){
typename std::deque<T>::iterator it;
for(it=vec.begin() ; it!=vec.end(); it++){
    if(*it == val){
        return true;
    }
}

return false;
}

template <class T>
void Monticulo<T>::inOrden() const {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}