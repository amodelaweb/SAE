#ifndef __TAD_ARBOLESTUD_H__
#define __TAD_ARBOLESTUD_H__

#include <iostream>
#include <list>
#include "NodoEstud.h"

class ArbolEstud{
protected:
NodoEstud* raiz ;
public:
  ArbolEstud();
  ArbolEstud(Asignatura* dato , std::string semestre);
  ~ArbolEstud() = default ;
  bool esVacio();
  void fijarRaiz(NodoEstud* nraiz) ;
  bool insertarNodo(Asignatura* dato , std::string semestre);
  bool eliminarNodo(Asignatura* dato) ;
  void imprimirpreOrden() ;
};

#include "ArbolEstud.hxx"
#endif
