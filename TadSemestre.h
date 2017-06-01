 #ifndef __TAD__SEMESTRE__H__
#define __TAD__SEMESTRE__H__

#include "TadEstudiante.h"
#include <iostream>
#include <string>
#include <list>

class Semestre
{
public:
	Semestre(std::string CicloElectivo);
	~Semestre()=default;
	std::string GetCicloElctivo();
	void SetCicloElectivo(std::string CicloElectivo);
	std::list<Estudiante*> Getestudiantes();
	void Setestudiantes(std::list<Estudiante*> estudiantes);
	void AgregarEstudiante(std::string idestud , std::string Nombre , std::string Apellido , std::string GradoAcademico , std::string Grado , std::string CdProgAcadBase , std::string NombreActualPrograma , std::string cd_actual_baja) ;
	bool VerificarEstudiante(std::string idestud);
	Estudiante* VerificarEstudiante2(std::string idestud);
protected:
	std::string CicloElectivo;
	std::list<Estudiante*> estudiantes ;

};
#include "TadSemestre.hxx"
#endif
