#ifndef __TAD__AULA__H__
#define __TAD__AULA__H__

#include <iostream>
#include <string>
#include <list>

class Aula{
public:
  Aula(std::string idaula , int capacidad) ;
  ~Aula() = default ;
  std::string Getidaula();
  int Getcapacidad_aula();
  void Setidaula(std::string idaula);
  void Setcapacidad_aula(int capcidad_aula);
protected:
  std::string idaula ;
  int capcidad_aula ;
};
#include "TadAula.hxx"
#endif
