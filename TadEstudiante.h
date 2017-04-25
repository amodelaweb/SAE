#ifndef __TAD_ESTUDIANTE_H__
#define __TAD_ESTUDIANTE_H__

#include "TadClaseXestudiante.h"
#include "TadClase.h"

#include <string>
#include <fstream>
#include <list>


class Estudiante
{
public:
	Estudiante(std::string idestud , std::string Nombre , std::string Apellido , std::string GradoAcademico , std::string Grado , std::string CdProgAcadBase , std::string NombreActualPrograma , std::string cd_actual_baja );
	~Estudiante()=default;
	std::string Getidestud() ;
	void AgregarClasenotas(Clase* clase , float nota , std::string estadoinscrp ,int creditosinscrp ,std::string sistemacalf , std::string finscrp , std::string fretiro) ;
	std::string GetNombreComp() ;
	std::list<ClaseXestudiante*> GetClases() ;
	bool verificarclasenota(Clase* clase) ;	
protected:
	std::string idestud ;
	std::string Nombre;
	std::string Apellido;
	std::string GradoAcademico;
	std::string Grado;
	std::string CdProgAcadBase;
	std::string cd_actual_baja ;
	std::string NombreActualPrograma;
	std::list<ClaseXestudiante*> clases;
};
#include "TadEstudiante.hxx"

#endif
