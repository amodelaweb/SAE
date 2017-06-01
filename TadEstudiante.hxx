#ifndef __TAD_ESTUDIANTE_HXX__
#define __TAD_ESTUDIANTE_HXX__

#include "TadEstudiante.hxx"

/*=============================================================================================================================*/
Estudiante::Estudiante(std::string idestud , std::string Nombre , std::string Apellido , std::string GradoAcademico , std::string Grado , std::string CdProgAcadBase , std::string NombreActualPrograma , std::string cd_actual_baja ){
	this->idestud = idestud ;
	this->Nombre = Nombre ;
	this->Apellido = Apellido ;
	this->GradoAcademico = GradoAcademico ;
	this->Grado = Grado ;
	this->CdProgAcadBase = CdProgAcadBase ;
	this->NombreActualPrograma = NombreActualPrograma ;
	this->cd_actual_baja = cd_actual_baja ;
}
/*=============================================================================================================================*/
std::string Estudiante::Getidestud() {
	return this->idestud ;
}
/*=============================================================================================================================*/
void Estudiante::AgregarClasenotas(Clase* clase , float nota , std::string estadoinscrp ,int creditosinscrp ,std::string sistemacalf , std::string finscrp , std::string fretiro) {
	this->clases.push_back(new ClaseXestudiante(clase , nota , estadoinscrp , creditosinscrp , sistemacalf , finscrp , fretiro)) ;
}
/*=============================================================================================================================*/
std::string Estudiante::GetNombreComp(){
	return (this->Nombre + " " +this->Apellido );
}
/*=============================================================================================================================*/
std::list<ClaseXestudiante*> Estudiante::GetClases() {
	return this->clases ;
}
/*=============================================================================================================================*/
bool Estudiante::verificarclasenota(Clase* clase) {
	bool esta = false ;
	for(std::list<ClaseXestudiante*>::iterator it = this->clases.begin() ; it != this->clases.end() && !esta ;it++){
		if((*it)->Getclase() == clase){
			esta = true ;
		}
	}
	return esta ;
}
/*=============================================================================================================================*/
bool operator == (const Estudiante &e1, const Estudiante &e2){
	return e1.idestud == e2.idestud ;
}
/*=============================================================================================================================*/
bool operator != (const Estudiante &e1, const Estudiante &e2){
	return e1.idestud != e2.idestud ;
}
/*=============================================================================================================================*/
bool operator <  (const Estudiante &e1, const Estudiante &e2){
	return e1.idestud < e2.idestud ;
}
/*=============================================================================================================================*/
bool operator >  (const Estudiante &e1, const Estudiante &e2){
	return e1.idestud > e2.idestud ;
}
/*=============================================================================================================================*/
bool operator >= (const Estudiante &e1, const Estudiante &e2){
	return e1.idestud >= e2.idestud ;
}
/*=============================================================================================================================*/
bool operator <= (const Estudiante &e1, const Estudiante &e2){
	return e1.idestud <= e2.idestud ;
}
/*=============================================================================================================================*/
std::ostream& operator << (std::ostream &o, const Estudiante* e1){
	return o <<bold2<<white2<<" El estudiante "<<bold2<<yellow2<<e1->Nombre<<" "<<e1->Apellido<<bold2<<white2<<" con el id "<<bold2<<red2<<e1->idestud<<bold2<<white2 ;
}
/*=============================================================================================================================*/
#endif
