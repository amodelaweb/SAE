#ifndef __TAD_Sesion_HXX__
#define __TAD_SESION_HXX__
#include "TadSesion.h"


/*=============================================================================================================================*/
Sesion::Sesion(std::string HoraInicioClase,std::string Componenete , std::string HoraFinClase , std::string TipoSesion , std::string Dia , std::string Idaula)
{
  this->HoraInicioClase = HoraInicioClase ;
  this->HoraFinClase = HoraFinClase ;
  this->TipoSesion = TipoSesion ;
  this->Dia = Dia ;
  this->Idaula = Idaula ;
  this->Componenete = Componenete ;
}
/*=============================================================================================================================*/
std::string Sesion::GetHoraInicioClase()
{
  return(this->HoraInicioClase);
}
/*=============================================================================================================================*/
std::string Sesion::GetHoraFinClase()
{
  return(this->HoraFinClase);
}
/*=============================================================================================================================*/
std::string Sesion::GetIdaula(){
  return (this->Idaula) ;
}
/*=============================================================================================================================*/
std::string Sesion::GetDia()
{
  return(this->Dia);
}
/*=============================================================================================================================*/
void Sesion::SetHoraInicioClase(std::string HoraInicioClase)
{
  this->HoraInicioClase=HoraInicioClase;
}
/*=============================================================================================================================*/
void Sesion::SetHoraFinClase(std::string GetHoraFinClase)
{
  this->HoraFinClase=HoraFinClase;
}
/*=============================================================================================================================*/
void Sesion::SetDia(std::string Dia)
{
  this->Dia=Dia;
}
/*=============================================================================================================================*/
void Sesion::SetIdaula(std::string Idaula)
{
  this->Idaula=Idaula;
}
/*=============================================================================================================================*/
std::string Sesion::GetComponenete() {
  return this->Componenete ;
}
/*=============================================================================================================================*/
void Sesion::SetComponenete(std::string Componenete) {
  this->Componenete = Componenete ;
}
/*=============================================================================================================================*/
#endif // __TAD_Sesion_H__
