#ifndef __TAD__CLASE__H__
#define __TAD__CLASE__H__

#include "TadSesion.h"
#include <iostream>
#include <string>
#include <list>

//===================================================
const std::string red2("\x1B[31m");
const std::string blue2("\x1B[34m") ;
const std::string green2("\033[1;32m");
const std::string yellow2("\033[1;33m");
const std::string cyan2("\033[0;36m");
const std::string magenta2("\033[0;35m");
const std::string reset2("\033[0m");
const std::string bold2("\x1B[1m") ;
const std::string white2("\x1B[37m");
const std::string underline2("\x1B[4m");
const std::string backgroundblue2("\x1B[44m");
const std::string backgroundblack2("\x1B[49m");
const std::string backgroundwhite2("\x1B[47m");
//===================================================


class Clase
{
public:
	Clase(std::string nClase, int seccion , std::string EstadoClase , std::string EstadoInscripcion , std::string FFinal , std::string FInicial , std::string TotalInscritos , int aulasoli  , std::string Descrp , std::string nombreclas , std::string ciclolectivo , std::string idasign);
	~Clase()=default;
	std::string GetnClase();
	std::string GetEstadoClase();
	std::string GetCicloElctivo() ;
	std::string GetEstadoInscripcion();
	std::string GetFIncial();
	std::string GetFFinal();
	std::string GetTotalInscritos();
	std::string Getnombreclas();
	int Getcpacidadiscrp() ;
	int Getseccion() ;
	std::string GetDescrp() ;
	int GetCapacidadsoli() ;
	std::list< Sesion* > GetSesiones() ;

	void GetCapacidadsoli(int soli) ;
	void SetDescrp(std::string a) ;
	void Setcpacidadiscrp(int inscrp) ;
	void SetnClase(std::string nClase);
	void SetEstadoClase(std::string EstadoClase);
	void SetEstadoInscripcion(std::string EstadoInscripcion);
	void SetFIncial(std::string FIncial);
	void SetFFinal(std::string FFinal);
	void SetTotalInscritos(std::string TotalInscritos);
	void SetSeccion(int seccion) ;
	void AgregarSesion(std::string HoraInicioClase,std::string Componenete , std::string HoraFinClase , std::string TipoSesion , std::string Dia , std::string Idaula );
	Sesion* VerificarSesion(std::string Dia);
	std::string Getidasig() ;
//=========================================================================
	friend std::ostream& operator << (std::ostream &o, const Clase* e1);
protected:
	std::list<Sesion*> ListaSesion;
	std::string ciclolectivo ;
	std::string nClase;
	int seccion ;
	int aulasoli ;
	int capacidadinscrp ;
	std::string EstadoClase;
	std::string EstadoInscripcion;
	std::string FFinal;
	std::string FIncial;
	std::string TotalInscritos;
	std::string Descrp ;
	std::string nombreclas ;
	std::string idasign ;
};

#include "TadClase.hxx"
#endif// __TAD__CLASE__H__
