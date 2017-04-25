#ifndef __TAD_ARCHIVO_HXX__
#define __TAD_ARCHIVO_HXX__
#include "TadArchivo.h"


/*=============================================================================================================================*/
Archivo::Archivo(std::string nombrearch , SAE* sae){
  arch.open(nombrearch , std::fstream::in);
  this->sae = sae ;
}
/*=============================================================================================================================*/
std::string Archivo::Nextline(){
  if(!arch.eof() ){
    getline(arch,lineact) ;
    return lineact ;
  }else{
    arch.close() ;
    lineact = "NULL" ;
    return "NULL";
  }
}
/*=============================================================================================================================*/
std::string Archivo::separarPalabra(bool a){
  std::vector < std::string > palabras;
  std::string  temp;

  while (lineact.find(",", 0) != std::string::npos)
  {
    size_t  pos = lineact.find(",", 0);
    temp = lineact.substr(0, pos);
    lineact.erase(0, pos + 1);
    temp.erase(0,1);
    temp.erase(temp.size() - 1  , temp.size() );
    palabras.push_back(temp);

  }
  if (lineact.size() != 0 )
  {
    lineact.erase(lineact.size() - 1  , lineact.size() );
    lineact.erase(0,1);

    palabras.push_back(lineact);
  }
  if(palabras.size() > 0){
    palabras.push_back(" ");
    if(sae->VerificarSemestre(palabras[0]) == nullptr || a){
      return sae->RealizarClaseAsign(palabras) ;
    }
    else{
      return "\t --- Semestre ya inicializado ---" ;
    }
  }
  return "\t El archivo se cargo correctamente" ;
}
/*=============================================================================================================================*/
std::string Archivo::llenarArch() {
  Nextline()  ;
  Nextline()  ;
  bool c = true ;
  bool b = false ;
  std::string a = " " ;
  while( lineact != "NULL" && c){
    a = separarPalabra(b) ;

    if(a == "\t --- Semestre ya inicializado ---"){
      c = false ;
    }
    if(a == "\t El archivo esta vacio !!"){
      c = false ;
    }

    b = true ;
    Nextline()  ;
  }
  return a ;
}
/*=============================================================================================================================*/
std::string Archivo::llenarArch2() {
  Nextline()  ;
  Nextline()  ;
  std::string a = "";
  while( lineact != "NULL" && !arch.eof()){;
    a = separarPalabra2() ;
    Nextline()  ;
  }
  return a ;
}
/*=============================================================================================================================*/
std::string Archivo::llenarprereq(){
  Nextline()  ;
  Nextline()  ;
  std::vector<std::string> vector1;
  while( lineact != "NULL" && !arch.eof()){;
    vector1.push_back(separartupla()) ;
    Nextline()  ;
  }
  int cont = 0 ;
  for(int i = 0 ; i < vector1.size() ; i++){
    if(vector1[i] == "\n \t === Resultado exitoso ===")
    cont++;
  }

  if(cont == vector1.size())
  return "\n \t ==== Se cargaron todos los datos correctamente ====";
  else
  return "\n \t ==== Se cargaron algunos datos , pero hay asignaturas no registradas ====";
}
/*=============================================================================================================================*/
std::string Archivo::separartupla(){

  std::string  id1;
  std::string  id2;
  size_t  pos = lineact.find(",", 0);
  id1 = lineact.substr(0, pos);
  lineact.erase(0,pos+1);
  id2 = lineact ;
  id2.erase(strlen(id2.c_str())-1 , strlen(id2.c_str()) );
  if(sae->AgregarTupla(id1,id2)){
    return "\n \t === Resultado exitoso ===" ;
  }else{
    return "\n \t === Informacion Errada ===";
  }
}
/*=============================================================================================================================*/
std::string Archivo::separarPalabra2(){

  std::vector < std::string > vector1;
  std::string  temp;

  while (lineact.find(",", 0) != std::string::npos)
  {
    size_t  pos = lineact.find(",", 0);
    temp = lineact.substr(0, pos);
    lineact.erase(0, pos + 1);
    vector1.push_back(temp);
  }
  if (lineact.size() > 0 )
  {
    vector1.push_back(lineact);
  }else{
    vector1.push_back(" ");
  }
  bool z = sae->RealizarEstuclase(vector1)  ;
  if(z){
    return "\n \t === Resultado exitoso ===" ;
  }else{
    return "\n \t === Informacion Errada ===";
  }
}
/*=============================================================================================================================*/
bool Archivo::archopen() {
  return arch.is_open() ;
}
/*=============================================================================================================================*/
void Archivo::archclose(){
  arch.close() ;
}
/*=============================================================================================================================*/
#endif
