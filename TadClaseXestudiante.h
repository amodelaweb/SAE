#ifndef __TAD__CLASEXESTUDIANTE__H__
#define __TAD__CLASEXESTUDIANTE__H__

#include "TadEstudiante.h"
#include "TadClase.h"
#include <iostream>
#include <string>
#include <list>


class ClaseXestudiante
{
public:
	ClaseXestudiante(Clase* clase , float nota , std::string estadoinscrp ,int creditosinscrp ,std::string sistemacalf , std::string finscrp , std::string fretiro);
	~ClaseXestudiante()=default;
	Clase* Getclase();
	float GetNota();
	void SetClase(Clase* clase);
	void SetNota(float Nota);
protected:
	Clase* clase;
	float Nota;
	std::string estadoinscrp ;
	int creditosinscrp ;
	std::string sistemacalf ;
	std::string finscrp ;
	std::string fretiro ;
};
#include "TadClaseXestudiante.hxx"

#endif
