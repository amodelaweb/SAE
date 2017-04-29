#ifndef __TAD_NODOESTU_H__
#define __TAD_NODOESTU_H__

#include "Asignatura.h"
#include <iostream>
#include <list>

class NodoEstud{
protected:
	Asignatura* dato ;
	std::string CicloElectivo ;
	std::list< NodoEstud* > desc ;
public:
 	NodoEstud();
	NodoEstud(Asignatura* dato , std::string CicloElectivo);
	~NodoEstud() = default;
	std::string GetCicloElctivo() ;
	std::list< NodoEstud* > obtenerDesc() ;
	Asignatura* obtenerDato();
	void fijarDato(Asignatura* val);
	bool adicionarDesc(Asignatura* asignatura , std::string CicloElectivo);
	bool eliminarDesc(Asignatura* asign);
	Asignatura* buscarNodo(Asignatura* asign , std::string semestre);
	void imprimirpreOrden();
};

#include "NodoEstud.hxx"
#endif
