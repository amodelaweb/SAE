#ifndef __TAD_ASIGNATURA_HXX__
#define __TAD_ASIGNATURA_HXX__
#include "TadClase.h"

/*=============================================================================================================================*/
Clase::Clase(std::string nClase, int seccion , std::string EstadoClase , std::string EstadoInscripcion , std::string FFinal , std::string FInicial , std::string TotalInscritos , int aulasoli  , std::string Descrp , std::string nombreclas , std::string ciclolectivo  , std::string idasign)
{
  this->nClase = nClase ;
  this->seccion = seccion ;
  this->EstadoClase = EstadoClase ;
  this->EstadoInscripcion = 	EstadoInscripcion ;
  this->FFinal = FFinal ;
  this->FIncial = FInicial ;
  this->TotalInscritos = TotalInscritos ;
  this->aulasoli = aulasoli ;
  this->Descrp = Descrp ;
  this->nombreclas = nombreclas ;
  this->ciclolectivo = ciclolectivo ;
  this->idasign = idasign ;
}
/*=============================================================================================================================*/
std::string Clase::GetnClase()
{
  return this->nClase;
}
/*=============================================================================================================================*/
std::string Clase::GetEstadoClase()
{
  return this->EstadoClase;
}
/*=============================================================================================================================*/
std::string Clase::GetEstadoInscripcion()
{
  return this->EstadoInscripcion;
}
/*=============================================================================================================================*/
std::string Clase::GetFIncial()
{
  return this->FIncial;
}
/*=============================================================================================================================*/
std::string Clase::GetFFinal()
{
  return this->FFinal;
}
/*=============================================================================================================================*/
std::string Clase::GetTotalInscritos()
{
  return this->TotalInscritos;
}
/*=============================================================================================================================*/
int Clase::Getseccion(){
  return this->seccion ;
}
/*=============================================================================================================================*/
void Clase::SetnClase(std::string nClase)
{
  this->nClase=nClase;
}
/*=============================================================================================================================*/
void Clase::SetEstadoClase(std::string EstadoClase)
{
  this->EstadoClase=EstadoClase;
}
/*=============================================================================================================================*/
void Clase::SetEstadoInscripcion(std::string EstadoInscripcion)
{
  this->EstadoInscripcion=EstadoInscripcion;
}
/*=============================================================================================================================*/
void Clase::SetFIncial(std::string FIncial)
{
  this->FIncial=FIncial;
}
/*=============================================================================================================================*/
void Clase::SetFFinal(std::string FFinal)
{
  this->FFinal=FFinal;
}
/*=============================================================================================================================*/
void Clase::SetTotalInscritos(std::string TotalInscritos)
{
  this->TotalInscritos=TotalInscritos;
}
/*=============================================================================================================================*/
void Clase::SetSeccion(int seccion){
  this->seccion = seccion ;
}
/*=============================================================================================================================*/
void Clase::AgregarSesion(std::string HoraInicioClase,std::string Componenete , std::string HoraFinClase , std::string TipoSesion , std::string Dia , std::string Idaula)
{
  std::list<Sesion*>::iterator It;
  bool esta=false;
  for(It  = this->ListaSesion.begin() ;It != this->ListaSesion.end();It++)
  {
    if((*It)->GetDia()==Dia)
    {
      esta=true;
    }
  }
  this->ListaSesion.push_back(new Sesion (HoraInicioClase , Componenete , HoraFinClase , TipoSesion , Dia , Idaula)) ;

}
/*=============================================================================================================================*/
int Clase::Getcpacidadiscrp() {
  return this->capacidadinscrp ;
}
/*=============================================================================================================================*/
void Clase::Setcpacidadiscrp(int inscrp) {
  this->capacidadinscrp = inscrp ;

}
/*=============================================================================================================================*/
std::string Clase::GetDescrp() {
  return this->Descrp ;
}
/*=============================================================================================================================*/
void Clase::SetDescrp(std::string a) {
  this->Descrp = a ;
}
/*=============================================================================================================================*/
int Clase::GetCapacidadsoli() {
  return this->aulasoli ;
}
/*=============================================================================================================================*/
void Clase::GetCapacidadsoli(int soli) {
  this->aulasoli = soli ;
}
/*=============================================================================================================================*/
Sesion* Clase::VerificarSesion(std::string Dia){
  bool esta=false;
  std::list<Sesion*>::iterator itsclase=this->ListaSesion.begin();
  while(!esta && itsclase!=this->ListaSesion.end())
  {

    if((*itsclase)->GetDia()==Dia)
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
std::list< Sesion* > Clase::GetSesiones() {
  return this->ListaSesion ;
}
/*=============================================================================================================================*/
std::string Clase::Getnombreclas(){
  return this->nombreclas;
}
/*=============================================================================================================================*/
std::string Clase::GetCicloElctivo(){
  return this->ciclolectivo ;
}
/*=============================================================================================================================*/
std::string Clase::Getidasig() {
  return this->idasign ;
}
/*=============================================================================================================================*/
std::ostream& operator << (std::ostream &o, const Clase* e1){
  return o <<e1->nombreclas <<" , "<<e1->nClase;
}
/*=============================================================================================================================*/
#endif // __TAD_Sesion_H__
