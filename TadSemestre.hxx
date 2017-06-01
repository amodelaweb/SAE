#ifndef __TAD_SEMESTRE_HXX__
#define __TAD_SESMESTRE_HXX__
#include "TadSemestre.h"

/*=============================================================================================================================*/
Semestre::Semestre(std::string CicloElectivo)
{
	this->CicloElectivo = CicloElectivo ;
}
/*=============================================================================================================================*/
std::string Semestre::GetCicloElctivo()
{
	return(this->CicloElectivo);
}
/*=============================================================================================================================*/
void Semestre::SetCicloElectivo(std::string CicloElectivo)
{
	this->CicloElectivo=CicloElectivo;
}
/*=============================================================================================================================*/
std::list<Estudiante*> Semestre::Getestudiantes()
{
	return(this->estudiantes);
}
/*=============================================================================================================================*/
void Semestre::Setestudiantes(std::list<Estudiante*> estudiantes)
{
	this->estudiantes=estudiantes;
}
/*=============================================================================================================================*/
bool Semestre::VerificarEstudiante(std::string idestud)
{
	bool esta=false;
	std::list<Estudiante*>::iterator itest=this->estudiantes.begin();
	while(!esta && itest!=this->estudiantes.end())
	{
		if((*itest)->Getidestud()==idestud)
		{
			esta=true;
		}else{
			itest++;
		}
	}
	return(esta);
}
/*=============================================================================================================================*/
Estudiante* Semestre::VerificarEstudiante2(std::string idestud)
{
	bool esta=false;
	std::list<Estudiante*>::iterator itest=this->estudiantes.begin();
	while(!esta && itest!=this->estudiantes.end())
	{
		if((*itest)->Getidestud()==idestud)
		{
			esta=true;
		}else{
			itest++;
		}
	}
	if(esta){
		return *itest ;
	}else{
		return nullptr ;
	}
}
/*=============================================================================================================================*/
void Semestre::AgregarEstudiante(std::string idestud , std::string Nombre , std::string Apellido , std::string GradoAcademico , std::string Grado , std::string CdProgAcadBase , std::string NombreActualPrograma , std::string cd_actual_baja){
	this->estudiantes.push_back(new Estudiante(idestud ,  Nombre ,  Apellido ,GradoAcademico , Grado , CdProgAcadBase ,	 NombreActualPrograma, cd_actual_baja));
}
/*=============================================================================================================================*/
#endif // __TAD_Semestre_H__
