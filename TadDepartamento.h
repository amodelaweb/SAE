#ifndef __TAD__DEPARTAMENTO__H__
#define __TAD__DEPARTAMENTO__H__
#include "TadAsignatura.h"
#include <iostream>
#include <list>
#include <string>


class Departamento{
public:
  Departamento(std::string nombredept , std::string orgacd , std::string catalogo ) ;
  ~Departamento() = default ;
  std::string Getnombredept() ;
  std::string Getorgacd() ;
  std::string Getcatalogo() ;
  std::list<Asignatura*>  Getasignaturas() ;
  void AgregarAsigantura(std::string Idcurso , std::string NombreAsignatura , std::string Grado) ;
  void Setnombredept(std::string nombredept) ;
  void Setorgacd(std::string orgacd) ;
  void Setcatalogo(std::string catalogo) ;
  Asignatura* VerificarAsignatura(std::string Idcurso);
protected:
  std::string nombredept ;
  std::string orgacd ;
  std::string catalogo ;
  std::list<Asignatura*> asignaturas;
};

#include "TadDepartamento.hxx"
#endif
