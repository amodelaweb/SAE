#ifndef __TAD_NODOESTU_HXX__
#define __TAD_NODOESTU_HXX__
#include "NodoEstud.h"

/*=============================================================================================================================*/
NodoEstud::NodoEstud(){
  this->dato = nullptr ;
}
/*=============================================================================================================================*/
NodoEstud::NodoEstud(Asignatura* dato , std::string CicloElectivo){
  this->dato = nullptr ;
  this->CicloElectivo = CicloElectivo ;
}
/*=============================================================================================================================*/
std::list< NodoEstud* > NodoEstud::obtenerDesc(){
  return this->desc ;
}
/*=============================================================================================================================*/
Asignatura* NodoEstud::obtenerDato(){
  return this->dato ;
}
/*=============================================================================================================================*/
void NodoEstud::fijarDato(Asignatura* val){
  this->dato = val ;
}
/*=============================================================================================================================*/
bool NodoEstud::adicionarDesc(Asignatura* asignatura , std::string CicloElectivo){
  //ADICIONAR CON CRITERIO
}
/*=============================================================================================================================*/
bool NodoEstud::eliminarDesc(Asignatura* asign){
  //TOAMR ANTERIOR
}
/*=============================================================================================================================*/
void NodoEstud::imprimirpreOrden(){

}
/*=============================================================================================================================*/
std::string NodoEstud::GetCicloElctivo() {
  return this->CicloElectivo ;
}
/*=============================================================================================================================*/
Asignatura* NodoEstud::buscarNodo(Asignatura* asign , std::string semestre){
  if(this->dato == asign && this->CicloElectivo == semestre){
    return this ;
  }
  if (!(this->desc.empty()))
  {
    Asignatura* aux ;
    bool ya = false ;
    for (std::list<NodoEstud*>::iterator it = this->desc.begin() ; it != this->desc.end()  && !ya ; it++ ){
      aux = (*it)->buscarNodo(asign , semestre);
      if(aux != nullptr){
        ya = true ;
      }
    }
    if(!ya){
      return nullptr ;
    }else{
      return aux ;
    }
  }else{
    return nullptr ;
  }
}
/*=============================================================================================================================*/
#endif
