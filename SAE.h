#ifndef __TAD__SAE__H__
#define __TAD__SAE__H__

#include "TadAula.h"
#include "TadSemestre.h"
#include "TadArchivo.h"
#include "TadDepartamento.h"
#include "TadAsignatura.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>

const std::string red1("\x1B[31m");
const std::string blue1("\x1B[34m") ;
const std::string green1("\033[1;32m");
const std::string yellow1("\033[1;33m");
const std::string cyan1("\033[0;36m");
const std::string magenta1("\033[0;35m");
const std::string reset1("\033[0m");
const std::string bold1("\x1B[1m") ;
const std::string white1("\x1B[37m");
const std::string underline1("\x1B[4m");
const std::string backgroundblack1("\x1B[49m");
const std::string backgroundwhite1("\x1B[47m");

struct comparatorAsign{
  bool operator()(Asignatura* a1 , Asignatura* a2)const{
    return a1->GetIdCurso() < a2->GetIdCurso();
  }
};

class SAE
{
public:
  SAE() ;
  ~SAE() = default ;
  std::string RealizarClaseAsign(std::vector<std::string> vector1);
  std::list<Semestre*> GetlistaSemestres() ;
  std::list<Departamento*> Getdepartamentos() ;
  std::list<Aula*> Getaulas ();
  void SetlistaSemestres(std::list<Semestre*> listaSemestres) ;
  void Setdepartamentos(std::list<Departamento*> departamentos) ;
  void Setaulas(std::list<Aula*> aulas);
  bool VerificarAula(std::string Idaula);
  Semestre* VerificarSemestre(std::string CicloElectivo);
  Departamento* VerificarDept(std::string nombredept) ;
  bool RealizarEstuclase(std::vector<std::string> vector1) ;
  Departamento* VerificarDept2(std::string idorg) ;
  std::string horarioestud(std::string idestud) ;
  std::string convertirhora(std::string hora);
  bool compararhora(std::string hora1 , std::string hora2);
  std::string siguientehora(std::string hora);
  bool AgregarTupla(std::string id1 , std::string id2);
  Asignatura* VerificarAsignaturas(std::string idasign);
  int DemandaAsign(std::string semestre  , std::string idasign);
  std::string ultimoSemestre();
  void Demandaestud(std::string idestud);
  std::string siguienteSemestre(std::string& semestre) ;
  bool verificarsiesPrerrequisito(Asignatura* asign , Asignatura* asign2) ;
  bool esprerrequisito(Asignatura* asign , std::set<Asignatura* , comparatorAsign > &set1) ;
protected:
  std::list<Semestre*> listaSemestres ;
  std::list<Departamento*> departamentos ;
  std::list<Aula*> aulas ;
  std::multimap<  Asignatura* , Asignatura* , comparatorAsign > prerequisitos ;

};

#include "SAE.hxx"
#endif
