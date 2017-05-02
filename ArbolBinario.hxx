#ifndef ARBOL_BINARIO_HXX
#define ARBOL_BINARIO_HXX

#include "ArbolBinario.h"

template< class T >
ArbolBinarioAVL<T>::ArbolBinarioAVL(){
  this->raiz = nullptr;
}

template< class T >
ArbolBinarioAVL<T>::ArbolBinarioAVL(T& val){
  this->raiz = new NodoBinario<T>(val) ;
}

template< class T >
bool ArbolBinarioAVL<T>::esVacio(){
  if(this->raiz == nullptr)
  {
    return true ;
  }else
  {
    return false ;
  }
}

template< class T >
T& ArbolBinarioAVL<T>::datoRaiz()
{
  return this->raiz->obtenerDato();
}

template< class T >
void ArbolBinarioAVL<T>::preOrden(){
  this->raiz->preOrden();
}

template< class T >
void ArbolBinarioAVL<T>::inOrden(){
  this->raiz->inOrden() ;
}

template< class T >
void ArbolBinarioAVL<T>::posOrden(){
  this->raiz->posOrden();
}

template< class T >
void ArbolBinarioAVL<T>::nivelOrder(){
  std::queue<NodoBinario<T>*> colaaux;
  std::cout<<std::endl;
  if(this->raiz != nullptr){
    colaaux.push(this->raiz);
    while(!colaaux.empty()){
      if(colaaux.front()->obtenerHijoIzq()!= nullptr){
        colaaux.push(colaaux.front()->obtenerHijoIzq());
      }
      if(colaaux.front()->obtenerHijoDer()!=nullptr){
        colaaux.push(colaaux.front()->obtenerHijoDer());
      }
      std::cout<<std::endl<<colaaux.front()->obtenerDato();
      colaaux.pop();
    }
  }else{
    std::cout<<"\t === ARBOL VACIO ===";
  }
}

template< class T >
int ArbolBinarioAVL<T>::altura(){
  if(this->raiz != nullptr)
  return this->raiz->altura() ;
  else
  return -1 ;
}

template< class T >
int ArbolBinarioAVL<T>::tamano(){
  return this->raiz->tamano(0);
}

template< class T >
bool ArbolBinarioAVL<T>::insertar(T& val){
  if(!esVacio()){
    bool a = this->raiz->insertar(val);
    if(a){
      this->raiz->balancear(val , this->raiz);
    }
    return a ;
  }
  this->raiz = new NodoBinario<T>(val);

  return true ;
}

template< class T >
bool ArbolBinarioAVL<T>::eliminar(T& val){
  if(this->raiz->obtenerDato() != val){
    NodoBinario<T>* auxi = this->raiz->eliminar(val) ;
    if( auxi != nullptr){
      this->raiz->balancear2(auxi->obtenerDato() , this->raiz);
      return true ;
    }else{
      return false ;
    }
  }else{
    NodoBinario<T>* aux = this->raiz;
    NodoBinario<T>* aux2 ;
    NodoBinario<T>* aux3 = this->raiz->obtenerHijoDer() ;
    NodoBinario<T>* aux4 = this->raiz->obtenerHijoIzq() ;

    if(this->raiz->obtenerHijoIzq()->obtenerHijoDer() == nullptr){
      this->raiz  = aux->obtenerHijoIzq() ;
    }else{
      aux2 = this->raiz->obtenerHijoIzq()->obtenerNodomayor();
      this->raiz = aux2->obtenerHijoDer() ;

      aux2->fiJarHijoDer(nullptr);
      this->raiz->fijarHijoIzq(aux4);
    }
    this->raiz->fiJarHijoDer(aux3);
    delete aux ;
    if(this->raiz->obtenerHijoIzq() != nullptr)
    this->raiz->balancear2(this->raiz->obtenerHijoDer()->obtenerDato() , this->raiz ) ;
    if(this->raiz->obtenerHijoDer() != nullptr )
    this->raiz->balancear2(this->raiz->obtenerHijoIzq()->obtenerDato() , this->raiz  ) ;
    return true ;
  }
}

template< class T >
T& ArbolBinarioAVL<T>::minimo(){
  return this->raiz->minimo();
}

template< class T >
T& ArbolBinarioAVL<T>::maximo(){
  return this->raiz->maximo();
}

template <class T>
typename ArbolBinarioAVL<T>::iterator ArbolBinarioAVL<T>::begin()
{
  NodoBinario<T> *curr = this->raiz;
  if (curr != nullptr){
    while (curr->hijoIzq != nullptr){
      curr = curr->hijoIzq;
    }
  }
  return iterator(curr, this);
}

template <class T>
typename ArbolBinarioAVL<T>::iterator ArbolBinarioAVL<T>::end()
{
  return iterator(nullptr, this);
}
#endif
