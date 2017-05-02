#ifndef BNTREE_ITERATOR_H
#define BNTREE_ITERATOR_H

#include "ArbolBinario.h"
#include "NodoBinario.h"
#include <iostream>


template< class T >
class ArbolBinarioAVL;

template< class T >
class NodoBinario;

template< class T >
class bntree_iterator{
  friend class ArbolBinarioAVL<T>;
  friend class NodoBinario<T>;
public:
  bntree_iterator();
  bntree_iterator(NodoBinario<T>* p, ArbolBinarioAVL<T> *t);
  ~bntree_iterator() = default ;

  bool operator == (const bntree_iterator& rhs) const;
  bool operator!= (const bntree_iterator& rhs) const;
  T& operator* () const;
  bntree_iterator& operator++ ();
  bntree_iterator operator++ (int);
  bntree_iterator& operator-- ();
  bntree_iterator operator-- (int);
  const T* operator->() const ;
private:
  ArbolBinarioAVL<T> *arbol ;
  NodoBinario<T> *act ;
};

#include "BNTreeIterator.hxx"

#endif
