#ifndef __TAD__ASIGNATURA__HXX__
#define __TAD__ASIGNATURA__HXX__

#include "TadAsignatura.h"

/*=============================================================================================================================*/
Asignatura::Asignatura(std::string Idcurso , std::string NombreAsignatura , std::string Grado  ){
	this->Idcurso = Idcurso ;
	this->NombreAsignatura = NombreAsignatura ;
	this->Grado = Grado ;

}
/*=============================================================================================================================*/
std::string Asignatura::GetIdCurso()
{
	return(this->Idcurso);
}
/*=============================================================================================================================*/
std::string Asignatura::GetNombreAsignatura()
{
	return(this->NombreAsignatura);
}
/*=============================================================================================================================*/
std::string Asignatura::GetGrado()
{
	return(this->Grado);
}
/*=============================================================================================================================*/
void Asignatura::SetIdcurso(std::string Idcurso)
{
	this->Idcurso=Idcurso;
}
/*=============================================================================================================================*/
void Asignatura::SetNombreAsignatura(std::string NombreAsignatura)
{
	this->NombreAsignatura=NombreAsignatura;
}
/*=============================================================================================================================*/
void Asignatura::SetGrado(std::string Grado)
{
	this->Grado=Grado;
}
/*=============================================================================================================================*/
void Asignatura::AgregarClase(std::string nClase, int seccion , std::string EstadoClase , std::string EstadoInscripcion , std::string FFinal , std::string FInicial , std::string TotalInscritos ,int aulasoli  , std::string Descrp , std::string nombreclas , std::string ciclolectivo , std::string idasign){
	bool b = false ;
	for (std::list<Clase*>::iterator it = this->listaclase.begin() ; it != this->listaclase.end() ;it++	){
		if((*it)->GetnClase() == nClase){
			b = true ;
		}
	}
	if(!b){
		this->listaclase.push_back(new Clase(nClase , seccion , EstadoClase , EstadoInscripcion , FFinal , FInicial , TotalInscritos , aulasoli ,Descrp , nombreclas , ciclolectivo , idasign)) ;
	}
}
/*=============================================================================================================================*/
Clase* Asignatura::VerificarClase(std::string nClase)
{

	bool esta=false;
	std::list<Clase*>::iterator itsclase=this->listaclase.begin();
	while(!esta && itsclase!=this->listaclase.end())
	{

		if((*itsclase)->GetnClase()==nClase)
		{
			esta=true;
		}else{
			itsclase++;
		}
	}
	if(esta==true)
	{
		return(*itsclase);
	}
	else
	{
		return(nullptr);
	}
}
/*=============================================================================================================================*/
std::list<Clase*> Asignatura::GetListaClases() {
 return this->listaclase;
}
#endif // __TAD_Asignatura_H__
