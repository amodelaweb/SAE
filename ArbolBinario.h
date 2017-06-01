
#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "BNTreeIterator.h"
#include "NodoBinario.h"
#include <iostream>
#include <queue>

template< class T >
class bntree_iterator;

template< class T >
class NodoBinario;


template< class T >

class ArbolBinarioAVL{
  friend class bntree_iterator<T> ;
protected:
  NodoBinario<T> *raiz ;

public:
  typedef bntree_iterator<T> iterator ;
  iterator find(const T& item);
  iterator begin();
  iterator end();

  ArbolBinarioAVL();
  ArbolBinarioAVL(T& val);
  ~ArbolBinarioAVL() = default;
  bool esVacio() ;
  T& datoRaiz();
  void preOrden() ;
  void inOrden() ;
  void posOrden();
  void nivelOrder();
  int altura();
  int tamano();
  bool buscar(T& val) ;
  bool insertar(T& val);
  bool eliminar(T& val);
  T& minimo();
  T& maximo();

};



#include "ArbolBinario.hxx"
#endif
