#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H


#include <iostream>

template< class T >
class bntree_iterator;

template< class T >
class ArbolBinarioAVL;

template< class T >

class NodoBinario{

protected:
  friend class bntree_iterator<T> ;
  friend class ArbolBinarioAVL<T> ;
  T dato;
  NodoBinario<T> *hijoIzq ;
  NodoBinario<T> *hijoDer ;
public:
  NodoBinario();
  ~NodoBinario() = default ;
  NodoBinario(T& val);
  NodoBinario(T& val , NodoBinario<T> *izqq , NodoBinario<T> *der);
  T& obtenerDato();
  bool esNull() ;
  int altura();
  void fijarDato(T& val) ;
  int tamano(int aux);
  bool insertar(T& val);
  NodoBinario<T>* eliminar(T& val);
  NodoBinario<T>* obtenerNodomayor();
  void fiJarHijoDer(NodoBinario<T> *der);
  void fijarHijoIzq(NodoBinario<T> *izq);
  bool verificarAVL();
  void preOrden() ;
  void posOrden() ;
  void inOrden() ;
  bool cambiarPadre(NodoBinario<T>*& root , NodoBinario<T>* n_padre , NodoBinario<T>* padre);
  T& minimo();
  T& maximo();
  NodoBinario<T>* obtenerHijoIzq();
  NodoBinario<T>* obtenerHijoDer();
  NodoBinario<T>* obtenerPadre(NodoBinario* nodo) ;
  NodoBinario<T>* rotIzq();
  NodoBinario<T>* rotDer();
  bool balancear2(T& val , NodoBinario<T>*& root) ;
  bool balancear(T& val , NodoBinario<T>*& root) ;
  void rotizqder(NodoBinario<T>*& root);
  void rotderizq(NodoBinario<T>*& root);

};

#include "NodoBinario.hxx"
#endif
