#ifndef __TAD__CLASEXESTUDIANTE__HXX__
#define __TAD__CLASEXESTUDIANTE__HXX__
#include "TadClaseXestudiante.h"


/*=============================================================================================================================*/
ClaseXestudiante::ClaseXestudiante(Clase* clase , float nota , std::string estadoinscrp ,int creditosinscrp ,std::string sistemacalf , std::string finscrp , std::string fretiro)
{
	this->clase = clase ;
	this->Nota = nota ;
	this->creditosinscrp = creditosinscrp ;
	this->estadoinscrp = estadoinscrp ;
	this->sistemacalf = sistemacalf ;
	this->finscrp = finscrp ;
	this->fretiro = fretiro ;
}
/*=============================================================================================================================*/
Clase* ClaseXestudiante::Getclase()
{
	return(this->clase);
}
/*=============================================================================================================================*/
float ClaseXestudiante::GetNota()
{
	return(this->Nota);
}
/*=============================================================================================================================*/
void ClaseXestudiante::SetClase(Clase* clase)
{
	this->clase=clase;
}
/*=============================================================================================================================*/
void ClaseXestudiante::SetNota(float Nota)
{
	this->Nota=Nota;
}
/*=============================================================================================================================*/
#endif
