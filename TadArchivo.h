#ifndef __TAD_ARCHIVO_H__
#define __TAD_ARCHIVO_H__

#include "SAE.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

class Archivo{
public:
  Archivo(std::string nombrearch , SAE* sae);
  ~Archivo() {};
  std::string Nextline();
  std::string separarPalabra(bool a) ;
  std::string separarPalabra2() ;
  std::string separartupla();
  std::string llenarArch() ;
  std::string llenarArch2() ;
  std::string llenarprereq();

  bool archopen() ;
  void archclose();
protected:
  std::fstream arch ;
  std::string lineact ;
  SAE* sae ;
};

#include "TadArchivo.hxx"

#endif
