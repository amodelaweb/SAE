#ifndef __TAD__SESION__H__
#define __TAD__SESION__H__

#include "TadAula.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>


class Sesion
{
public:
	Sesion(std::string HoraInicioClase,std::string Componenete , std::string HoraFinClase , std::string TipoSesion , std::string Dia , std::string Idaula);
	~Sesion()=default;

	std::string GetHoraInicioClase();
	std::string GetHoraFinClase();
	std::string GetSeccion();
	std::string GetDia();
	std::string GetIdaula();
	std::string Getsesion() ;
	std::string GetComponenete() ;
	void SetComponenete(std::string Componenete) ;
	void Setsesion(std::string sesion) ;
	void SetHoraInicioClase(std::string HoraInicioClase);
	void SetHoraFinClase(std::string GetHoraFinClase);
	void SetSeccion(std::string Seccion);
	void SetDia(std::string Dia);
	void SetIdaula(std::string Idaula);

protected:

	std::string Componenete ;
	std::string HoraInicioClase;
	std::string HoraFinClase;
	std::string TipoSesion ;
	std::string Dia;
	std::string Idaula ;
};
#include "TadSesion.hxx"
#endif
