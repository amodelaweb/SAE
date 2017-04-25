#ifndef __TAD__CLASE__H__
#define __TAD__CLASE__H__

#include "TadSesion.h"
#include <iostream>
#include <string>
#include <list>


class Clase
{
public:
	Clase(std::string nClase, int seccion , std::string EstadoClase , std::string EstadoInscripcion , std::string FFinal , std::string FInicial , std::string TotalInscritos , int aulasoli  , std::string Descrp , std::string nombreclas , std::string ciclolectivo);
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
};

#include "TadClase.hxx"
#endif// __TAD__CLASE__H__
