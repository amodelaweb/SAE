#ifndef __TAD__DEPARTAMENTO__HXX__
#define __TAD__DEPARTAMENTO__HXX__
#include "TadDepartamento.h"

Departamento::Departamento(std::string nombredept , std::string orgacd , std::string catalogo ) {
  this->nombredept = nombredept ;
  this->orgacd = orgacd ;
  this->catalogo = catalogo ;
}
/*=============================================================================================================================*/
void Departamento::AgregarAsigantura(std::string Idcurso , std::string NombreAsignatura , std::string Grado){
  Asignatura *a = new Asignatura(Idcurso , NombreAsignatura , Grado) ;
  this->asignaturas.push_back(a) ;

}
/*=============================================================================================================================*/
std::string Departamento::Getnombredept()
{
  return this->nombredept;
}
/*=============================================================================================================================*/
std::string Departamento::Getorgacd()
{
  return this->orgacd;
}
/*=============================================================================================================================*/
std::string Departamento::Getcatalogo()
{
  return this->catalogo;
}
/*=============================================================================================================================*/
std::list<Asignatura*>  Departamento::Getasignaturas()
{
  return this->asignaturas;
}
/*=============================================================================================================================*/
void Departamento::Setnombredept(std::string nombredept)
{
  this->nombredept=nombredept;
}
/*=============================================================================================================================*/
void Departamento::Setorgacd(std::string orgacd)
{
  this->orgacd=orgacd;
}
/*=============================================================================================================================*/
void Departamento::Setcatalogo(std::string catalogo)
{
  this->catalogo=catalogo;
}
/*=============================================================================================================================*/
Asignatura* Departamento::VerificarAsignatura(std::string Idcurso)
{
  bool esta=false;

  std::list<Asignatura*>::iterator itasig=this->asignaturas.begin();

  while(!esta && itasig!=this->asignaturas.end())
  {

    if((*itasig)->GetIdCurso()==Idcurso)
    {
      esta=true;
    }else{
      itasig++;
    }
  }
  if(esta==true)
  {
    return *itasig;
  }
  else
  {
    return(nullptr);
  }
}
/*=============================================================================================================================*/
#endif
