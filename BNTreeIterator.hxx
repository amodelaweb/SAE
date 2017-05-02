#ifndef BNTREE_ITERATOR_HXX
#define BNTREE_ITERATOR_HXX
#include "BNTreeIterator.h"
//=============================================================================================================
template <class T>
bntree_iterator<T>::bntree_iterator(NodoBinario<T>* p, ArbolBinarioAVL<T> *t) : act(p), arbol(t)
{

}
//=============================================================================================================
template <class T>
bntree_iterator<T>::bntree_iterator(): act(nullptr) , arbol(nullptr) {

}
//=============================================================================================================
template <class T>
bntree_iterator<T>& bntree_iterator<T>::operator ++ ()
{
  NodoBinario<T> *p;
  if (act == nullptr)
  {
    act = arbol->raiz;
    while (act->hijoIzq != nullptr) {
      act = act->hijoIzq;
    }
  }
  else{
    if (act->hijoDer != nullptr)
    {
      act = act->hijoDer;
      while (act->hijoIzq != nullptr) {
        act = act->hijoIzq;
      }
    }
    else
    {
      p = this->arbol->raiz->obtenerPadre(this->act);
      while (p != nullptr && act == p->hijoDer)
      {
        act = p;
        p = this->arbol->raiz->obtenerPadre(p);
      }
      act = p;
    }
  }
  return *this;
}
//=============================================================================================================
template <class T>
bool bntree_iterator<T>::operator == (const bntree_iterator& rhs) const{
  return (this->act == rhs.act && this->arbol == rhs.arbol) ;
}
//=============================================================================================================
template <class T>
bool bntree_iterator<T>::operator != (const bntree_iterator& rhs) const{
  return (this->act != rhs.act || this->arbol != rhs.arbol) ;
}
//=============================================================================================================
template <class T>
T& bntree_iterator<T>::operator* () const{
  return this->act->obtenerDato() ;
}
//=============================================================================================================
template <class T>
bntree_iterator<T> bntree_iterator<T>::operator++ (int){
  bntree_iterator<T> old = *this ;
  ++(*this);
  return old ;
}
//=============================================================================================================
template <class T>
bntree_iterator<T>& bntree_iterator<T>::operator-- (){
  if(this->act == nullptr){
    this->act = this->arbol->raiz ;
    while(act->hijoDer != nullptr){
      act = act->hijoDer ;
    }
    return *this ;
  }else{
    if(this->act == this->arbol->raiz->obtenerPadre(this->act)->hijoDer() ){
      this->act == this->arbol->raiz->obtenerPadre(this->act) ;
    }
    return *this ;
    if(this->act->hijoIzq == nullptr && this->act == this->arbol->raiz->obtenerPadre(this->act)->hijoIzq){
      this->act = nullptr ;
    }
    return *this ;
    if(this->act->hijoIzq != nullptr){
      this->act = this->act->hijoIzq ;
    }
    return *this ;
  }
}
//=============================================================================================================
template <class T>
const T* bntree_iterator<T>::operator->() const{
  return &(this->act->obtenerDato()) ;
}
#endif
