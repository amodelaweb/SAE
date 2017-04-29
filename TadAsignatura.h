#ifndef __TAD__ASIGNATURA__H__
#define __TAD__ASIGNATURA__H__

#include "TadClase.h"
#include <iostream>
#include <string>
#include <list>
#include <string.h>


class Asignatura{
public:
	Asignatura(std::string Idcurso , std::string NombreAsignatura , std::string Grado  );
	~Asignatura()=default;
	void SetIdcurso(std::string Idcurso);
	std::string GetIdCurso();
	void SetNombreAsignatura(std::string NombreAsignatura);
	std::string GetNombreAsignatura();
	void SetGrado(std::string Grado);
	std::string GetGrado();
	void AgregarClase(std::string nClase, int seccion , std::string EstadoClase , std::string EstadoInscripcion , std::string FFinal , std::string FInicial , std::string TotalInscritos , int aulasoli  , std::string Descrp , std::string nombreclas , std::string ciclolectivo , std::string idasign);
	Clase* VerificarClase(std::string nClase);
	std::list<Clase*> GetListaClases() ;
protected:
	std::list <Clase*> listaclase;
	std::string Idcurso;
	std::string NombreAsignatura;
	std::string Grado;
};

#include "TadAsignatura.hxx"
#endif// __TAD__ASIGNATURA__H__
