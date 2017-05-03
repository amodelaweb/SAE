#ifndef __TAD__SAE__HXX__
#define __TAD__SAE__HXX__
#include "SAE.h"

/*=========HOLA====================================================================================================================*/
SAE::SAE(){

}
/*=============================================================================================================================*/
std::string SAE::RealizarClaseAsign(std::vector<std::string> vector1){
  bool w = false ;
  std::vector<std::string> dias ;
  dias.push_back("Lun") ;
  dias.push_back("Mart") ;
  dias.push_back("Mierc") ;
  dias.push_back("Jue") ;
  dias.push_back("Vier") ;
  dias.push_back("Sab") ;
  dias.push_back("Dom") ;
  dias.push_back("NOCLASE") ;
  if(vector1.size() > 0){
    for (int k = 1 ; k < vector1[5].size() ; k++){
      if(vector1[5][k-1] == '0' && !w){
        vector1[5].erase((k -1) , k) ;
      }
      if(vector1[5][(k-1)] != '0'){
        w = true ;
      }
    }
    if(vector1[5][0] == '0'){
      vector1[5].erase(0,1);
    }
    if( VerificarSemestre(vector1[0]) == nullptr && vector1[0] != " " && vector1[0] != ""){
      this->listaSemestres.push_back(new Semestre(vector1[0])) ;
    }

    if (VerificarDept(vector1[3])==nullptr) {
      this->departamentos.push_back(new Departamento(vector1[3] , vector1[2] , vector1[4])) ;
    }
    if(VerificarDept(vector1[3])->VerificarAsignatura(vector1[5]) == nullptr){
      VerificarDept(vector1[3])->AgregarAsigantura(vector1[5] , vector1[6] , vector1[1]) ;
    }
    if(VerificarDept(vector1[3])->VerificarAsignatura(vector1[5]) != nullptr){

      if(((VerificarDept(vector1[3])->VerificarAsignatura(vector1[5]))->VerificarClase(vector1[7])) == nullptr){
        VerificarDept(vector1[3])->VerificarAsignatura(vector1[5])->AgregarClase(vector1[7] , atoi(vector1[8].c_str()), vector1[11] , vector1[12] , vector1[23] , vector1[22] , vector1[29] , atoi(vector1[26].c_str()) ,vector1[28] , vector1[6] , vector1[0] , vector1[5]);
      }
      if(((VerificarDept(vector1[3])->VerificarAsignatura(vector1[5]))->VerificarClase(vector1[7])) != nullptr){
        int y = 7  ;

        int d = 0 ;
        for (int z = 13 ; z <= 19 ; z++){
          if(vector1[z] == "Y"){
            y = d ;
          }
          d++ ;
        }
        if((VerificarDept(vector1[3])->VerificarAsignatura(vector1[5])->VerificarClase(vector1[7])->VerificarSesion(dias[y])) == nullptr  ){
          VerificarDept(vector1[3])->VerificarAsignatura(vector1[5])->VerificarClase(vector1[7])->AgregarSesion(vector1[20] , vector1[10] , vector1[21] , vector1[9],dias[y] , vector1[24]) ;
        }
      }
      if(!VerificarAula(vector1[24])){
        this->aulas.push_back(new Aula(vector1[24] , atoi(vector1[25].c_str()))) ;
      }
    }

    return "\t El archivo se cargo correctamente" ;
  }else{
    return "\t El archivo esta vacio !!" ;
  }
  return "\t El archivo se cargo correctamente" ;
}
/*=============================================================================================================================*/
bool SAE::RealizarEstuclase(std::vector<std::string> vector1){
  if(vector1.size() >0){
    if( VerificarSemestre(vector1[0]) == nullptr && vector1[0] != " " && vector1[0] != ""){
      this->listaSemestres.push_back(new Semestre(vector1[0])) ;
    }
    std::string idstud  = vector1[2] ;
    while(idstud[0] == '0'){
      idstud.erase(0,1);
    }
    while(vector1[10][0] == '0'){
      vector1[10].erase(0,1);
    }

    if( !VerificarSemestre(vector1[0])->VerificarEstudiante(idstud) ){

      VerificarSemestre(vector1[0])->AgregarEstudiante(idstud , vector1[4].erase(vector1[4].size()-1  , vector1[4].size()) ,vector1[3], vector1[5] , vector1[6] , vector1[7] , vector1[9]  , vector1[1]) ;
    }
    if(VerificarSemestre(vector1[0])->VerificarEstudiante2(idstud) != nullptr){

      if(VerificarDept2(vector1[15]) != nullptr){
        if(VerificarDept2(vector1[15])->VerificarAsignatura(vector1[10]) != nullptr){
          if(VerificarDept2(vector1[15])->VerificarAsignatura(vector1[10])->VerificarClase(vector1[11]) != nullptr)
          {
            if( !VerificarSemestre(vector1[0])->VerificarEstudiante2(idstud)->verificarclasenota(VerificarDept2(vector1[15])->VerificarAsignatura(vector1[10])->VerificarClase(vector1[11]))){
              std::string dasd = vector1[18] ;
              if(vector1[18] == " " || vector1[18] == ""){
                dasd = "0" ;
              }
              VerificarSemestre(vector1[0])->VerificarEstudiante2(idstud)->AgregarClasenotas(VerificarDept2(vector1[15])->VerificarAsignatura(vector1[10])->VerificarClase(vector1[11]), std::stof(dasd.c_str()) , vector1[20] , atoi(vector1[17].c_str()),vector1[19] , vector1[21] , vector1[22 ] ) ;
            }
            return true ;

          }else{
            return true ;
          }
        }
      }else{
        return true ;
      }
    }else{
      return true;
    }
  }else{
    return false ;
  }
  return true ;
}
/*=============================================================================================================================*/
std::list<Semestre*> SAE::GetlistaSemestres()
{
  return this->listaSemestres;
}
/*=============================================================================================================================*/
std::list<Departamento*> SAE::Getdepartamentos()
{
  return this->departamentos;
}
/*=============================================================================================================================*/
std::list<Aula*> SAE::Getaulas ()
{
  return this->aulas;
}
/*=============================================================================================================================*/
void SAE::SetlistaSemestres(std::list<Semestre*> listaSemestres)
{
  this->listaSemestres=listaSemestres;
}

/*=============================================================================================================================*/
void SAE::Setdepartamentos(std::list<Departamento*> departamentos)
{
  this->departamentos=departamentos;
}
/*=============================================================================================================================*/
void SAE::Setaulas(std::list<Aula*> aulas)
{
  this->aulas=aulas;
}
/*=============================================================================================================================*/
bool SAE::VerificarAula(std::string Idaula)
{

  bool esta=false;
  std::list<Aula*>::iterator itaulas=this->aulas.begin();
  while(!esta && itaulas!=this->aulas.end())
  {
    if((*itaulas)->Getidaula()==Idaula)
    {
      esta=true;
    }else{
      itaulas++;
    }
  }
  return(esta);
}
/*=============================================================================================================================*/
Semestre* SAE::VerificarSemestre(std::string CicloElectivo)
{
  bool esta=false;
  std::list<Semestre*>::iterator itsemestres=this->listaSemestres.begin();
  while(!esta && itsemestres!=this->listaSemestres.end())
  {
    if((*itsemestres)->GetCicloElctivo()==CicloElectivo)
    {
      esta=true;
    }else{
      itsemestres++;
    }
  }
  if(esta==true)
  {
    return(*itsemestres);
  }
  else
  {
    return(nullptr);
  }
}
/*=============================================================================================================================*/
Departamento* SAE::VerificarDept(std::string nombredept) {
  bool esta  = false;
  std::list<Departamento*>::iterator it = this->departamentos.begin() ;
  std::list<Departamento*>::iterator itaux = this->departamentos.begin();
  for (;it != this->departamentos.end() ;it++){
    if((*it)->Getnombredept() == nombredept){
      esta = true ;
      itaux = it ;
    }
  }
  if(!esta){
    return nullptr ;
  }else{
    return *itaux ;
  }
}
/*=============================================================================================================================*/
Departamento* SAE::VerificarDept2(std::string idorg){
  bool esta  = false;
  std::list<Departamento*>::iterator it = this->departamentos.begin() ;
  std::list<Departamento*>::iterator itaux = this->departamentos.begin();
  for (;it != this->departamentos.end() ;it++){
    if((*it)->Getorgacd() == idorg){
      esta = true ;
      itaux = it ;
    }
  }
  // AQUI ESTOY
  if(!esta){
    return nullptr ;
  }else{
    return *itaux ;
  }
}
/*====================================================================*/
std::string SAE::horarioestud(std::string idestud){
  int dia1 ;
  bool tieneclase = false ;
  int v =0 ;
  std::string horitafin = "";

  std::list<Semestre*>::iterator it = this->listaSemestres.begin();
  std::string **matrizconf ;
  matrizconf = new std::string * [17] ;
  for(int zz= 0 ; zz<17 ; zz++){
    matrizconf[zz] = new std::string[8] ;
  }
  bool unavez = false ;
  tieneclase = false ;
  for(;it != this->listaSemestres.end() ; it++){

    std::list<std::string> infoimp ;
    std::list<std::string> infonom ;
    std::list<std::string> salon ;
    std::list<std::string> sesion1 ;
    for(int i=0 ; i<17 ; i++){
      for(int j=1 ; j<8 ; j++){
        matrizconf[i][j] = "    " ;
      }
    }

    std::string aux ="" ;
    int op = 7;
    for(int i=0 ; i<17 ;i++){
      aux="";
      aux = std::to_string(op) ;
      aux+= ":";
      aux+= "00";
      matrizconf[i][0] = aux;

      op++ ;
    }

    if((*it)->VerificarEstudiante2(idestud) != nullptr){
      std::cout<<bold1<<red1<<"\n *) Semestre : "<<yellow1<<(*it)->GetCicloElctivo();
      std::cout<<bold1<<red1<<"\n *) ID Estud : "<<yellow1<<idestud;
      std::cout<<bold1<<red1<<"\n *) Nombre   :"<<yellow1<<(*it)->VerificarEstudiante2(idestud)->GetNombreComp();

      /*==================================*/
      if((*it)->VerificarEstudiante2(idestud)->GetClases().size() > 0){
        std::list< ClaseXestudiante* > listclasest = (*it)->VerificarEstudiante2(idestud)->GetClases();
        std::list< ClaseXestudiante* >::iterator itc = listclasest.begin();
        for( ; itc != listclasest.end() ; itc++){
          if((*itc)->Getclase()->GetEstadoClase() != "Sección Cancelada"){
            /*=========================================*/
            if((*itc)->Getclase()->GetSesiones().size() > 0){
              tieneclase = true ;
              /*================================================*/
              std::list< Sesion* >listses = (*itc)->Getclase()->GetSesiones();

              std::list<Sesion* >::iterator its = listses.begin() ;
              v = 0;
              for( ; its != listses.end() ;its++){
                infoimp.push_back((*itc)->Getclase()->GetnClase());
                infonom.push_back((*itc)->Getclase()->Getnombreclas());
                salon.push_back((*its)->GetIdaula());
                sesion1.push_back((*its)->GetDia());
                if((*its)->GetDia() == "Lun"){
                  dia1 = 1 ;
                }else{
                  if((*its)->GetDia() == "Mart"){
                    dia1 = 2 ;
                  }else{
                    if((*its)->GetDia() == "Mierc"){
                      dia1 = 3 ;
                    }else{
                      if((*its)->GetDia() == "Jue"){
                        dia1 = 4 ;
                      }else{
                        if((*its)->GetDia() == "Vier"){
                          dia1 = 5 ;
                        }else{
                          if((*its)->GetDia() == "Sab"){
                            dia1 = 6 ;
                          }else{
                            dia1 = 7 ;
                          }
                        }
                      }
                    }
                  }
                }
                std::string hora1 = "" ;
                std::string hora2 = "";
                hora1 = convertirhora((*its)->GetHoraInicioClase());
                horitafin = convertirhora((*its)->GetHoraFinClase());
                hora2 = hora1 ;
                bool viu = false ;
                for(v=0 ; v < 17 ; v++){
                  if(compararhora(hora2,matrizconf[v][0])){
                    matrizconf[v][dia1] = (*itc)->Getclase()->GetnClase();
                    viu = true ;
                  }
                  if(!compararhora(hora2 ,horitafin) && viu ){
                    hora2 = siguientehora(hora2) ;
                  }
                }
              }
            }
          }
        }
      }
      unavez = true ;
    }else{
      continue;
    }
    if(tieneclase){
      std::cout<<std::endl;
      std::cout<<std::endl;
      std::cout<<bold1<<green1<<"\n \t  Lunes    Martes    Miercoles    Jueves    Viernes    Sabado    Domingo \n"<<reset1;
      std::cout<<std::endl<<bold1<<green1<<" \t                                                                           "<<reset1<<std::endl;
      for(int i=0 ; i<17 ; i++){
        for(int j=0 ; j<8 ; j++){
          if(matrizconf[i][j] == "7:00" || matrizconf[i][j] == "8:00" || matrizconf[i][j] == "9:00"){
            if(j == 0 )
            std::cout<<bold1<<blue1<<"  "<<matrizconf[i][j]<<"    "<<reset1;
            else
            std::cout<<bold1<<yellow1<<"  "<<matrizconf[i][j]<<"    "<<reset1;
          }else{
            if(j == 0)
            std::cout<<bold1<<blue1<<" "<<matrizconf[i][j]<<"    "<<reset1;
            else
            std::cout<<bold1<<yellow1<<"  "<<matrizconf[i][j]<<"    "<<reset1;
          }
        }
        std::cout<<std::endl;
      }

      std::cout<<std::endl<<bold1<<white1;
      std::list<std::string>::iterator ap = infonom.begin();
      std::list<std::string>::iterator al = salon.begin();
      std::list<std::string>::iterator ax = sesion1.begin() ;
      std::string nec = "" ;
      std::cout<<bold1<<magenta1<<"\n No. Clase         Asignatura            Sesion      Salon\n";
      for(std::list<std::string>::iterator ot = infoimp.begin() ; ot != infoimp.end()  && ap!= infonom.end() && al != salon.end() && ax != sesion1.end();ot++){
        nec = "" ;
        if(strlen((*ap).c_str()) >= 28){
          std::cout<<std::endl<<bold1<<cyan1<<" "<<(*ot)<<" ---> "<<(*ap)<<"  - "<<(*ax)<<" - "<<(*al);
        }else{
          for(int l=strlen((*ap).c_str()) ; l<=29 ;l++){
            nec += " ";
          }
          std::cout<<std::endl<<bold1<<cyan1<<" "<<(*ot)<<" ---> "<<(*ap)<<nec<<" - "<<(*ax)<<" - "<<(*al);
        }
        ap++;
        al++;
        ax++;
      }
    }
    std::cout<<std::endl<<white1  ;
    std::cout<<std::endl;
  }

  for(int nn = 0 ; nn < 17 ; nn++){
    delete[] matrizconf[nn] ;
  }

  if(!unavez){
    return "\n \t=== El estudiante no tiene ninguna informacion registrada/No existe ===";
  }
  if(!tieneclase){
    return "\n \t=== El estudiante no tiene clase o la informacion no fue cargada correctamente ===";
  }
  return "\n \t === El horario ha sido mostrado satisfactoriamente ===" ;
}
/*=============================================================================================================================*/
std::string SAE::convertirhora(std::string hora){
  if(std::isspace(hora[0])){
    hora.erase(0,1) ;
  }
  int horai;
  std::string aux = "";
  int w = 0;
  bool ya = false ;
  bool cam = false ;
  std::string minutos ;
  for(int i=0 ; i< strlen(hora.c_str()) ;i++){
    if(hora[i] != ':'){
      aux+= hora[i] ;
      if(hora[i] == 'P'){
        cam = true ;
        w = i ;
      }
      if(hora[i] == 'A'){
        w = i ;
      }
    }else{
      if(ya){
        minutos = aux ;
        aux = "";
      }
      if(!ya){
        horai = atoi(aux.c_str()) ;
        ya = true ;
        aux = "";
      }
    }
  }
  if(cam){
    if(horai != 12 )
    horai += 12 ;
  }
  hora.erase(w , w+2) ;
  std::string enviar = std::to_string(horai);
  enviar+= ":";
  enviar+= "00" ;
  return enviar;
}
/*=============================================================================================================================*/
bool SAE::compararhora(std::string hora1 , std::string hora2){
  std::string a = "" ;
  std::string b = "" ;
  bool c = false ;
  for(int i=0 ; i<strlen(hora1.c_str()) && !c; i++){
    if(hora1[i] != ':' ){
      a+= hora1[i] ;
    }else{
      c = true ;
    }
  }
  c = false ;
  for(int i=0 ; i<strlen(hora2.c_str()) && !c ; i++){
    if(hora2[i] != ':' ){
      b+= hora2[i] ;
    }else{
      c = true ;
    }
  }

  if(atoi(a.c_str()) == atoi(b.c_str())){
    return true ;
  }else{
    return false ;
  }
}
/*=============================================================================================================================*/
std::string SAE::siguientehora(std::string hora){
  int horai;
  bool ya = false ;
  std::string aux = "";
  for(int i=0 ; i< strlen(hora.c_str()) && !ya ;i++){
    if(hora[i] != ':'){
      aux+= hora[i] ;
    }else{
      ya = true ;
    }
  }
  horai = atoi(aux.c_str()) ;
  horai++ ;
  std::string enviar = std::to_string(horai);
  enviar+= ":";
  enviar+= "00" ;
  return enviar;
}
/*=============================================================================================================================*/
bool SAE::AgregarTupla(std::string id1 , std::string id2){
  if(this->VerificarAsignaturas(id1) != nullptr && this->VerificarAsignaturas(id2) != nullptr){
    this->prerequisitos.insert(std::pair<  Asignatura* , Asignatura* >(this->VerificarAsignaturas(id1) ,this->VerificarAsignaturas(id2) )) ;
    return true ;
  }
  else{
    return false ;
  }
}
/*=============================================================================================================================*/
Asignatura* SAE::VerificarAsignaturas(std::string idasign){
  Asignatura* aux = nullptr ;
  for(std::list<Departamento*>::iterator it = this->departamentos.begin() ; it != this->departamentos.end() ; it++){
    if((*it)->VerificarAsignatura(idasign) != nullptr){
      aux = (*it)->VerificarAsignatura(idasign);
    }
  }
  return aux ;
}
/*=============================================================================================================================*/
int SAE::DemandaAsign(std::string semestre  , std::string idasign){
  if(this->VerificarSemestre(semestre) != nullptr){
    if(this->VerificarAsignaturas(idasign) != nullptr){
      if(this->prerequisitos.find( this->VerificarAsignaturas(idasign)) != this->prerequisitos.end()){
        std::pair <std::multimap<Asignatura* , Asignatura* >::iterator, std::multimap<Asignatura* ,Asignatura* >::iterator> ret;
        ret = this->prerequisitos.equal_range(this->VerificarAsignaturas(idasign));
        int cont = 0 ;
        std::vector<int> vectordecanti ;
        std::set<Asignatura* , comparatorAsign> aux2 ;
        std::set<Asignatura* , comparatorAsign> aux3 ;

        for (std::multimap<Asignatura* , Asignatura* >::iterator it=ret.first; it!=ret.second; ++it){
          std::list<Clase*> lista1 = it->second->GetListaClases() ;
          for(std::list<Clase*>::iterator ite  = lista1.begin() ; ite != lista1.end() ; ite++ ){
            if((*ite)->GetCicloElctivo() == semestre){
              cont+=atoi((*ite)->GetTotalInscritos().c_str() )  ;
            }
          }
          aux2.insert(it->second);
        }
        vectordecanti.push_back(cont);
        while(!aux2.empty()){
          cont = 0 ;
          aux3.clear() ;
          for(std::set<Asignatura*>::iterator it2= aux2.begin(); it2!=aux2.end(); ++it2){
            ret = this->prerequisitos.equal_range(*it2);
            for (std::multimap<Asignatura* , Asignatura* >::iterator it=ret.first; it!=ret.second; ++it){
              std::list<Clase*> lista2 = it->second->GetListaClases() ;
              for(std::list<Clase*>::iterator ite  = lista2.begin() ; ite != lista2.end() ; ite++ ){
                if((*ite)->GetCicloElctivo() == semestre){
                  cont+=atoi((*ite)->GetTotalInscritos().c_str() )  ;
                }
              }
              aux3.insert(it->second);
            }
          }
          if (cont > 0 ){
            vectordecanti.push_back(cont);
          }
          aux2.swap(aux3);
        }
        for(int i = 0 ; i < vectordecanti.size() ; i++){
          semestre = this->siguienteSemestre(semestre) ;
          std::cout<<"\n *) Demanda para semestre "<<semestre<<" es de "<<vectordecanti[i]<<" estudiantes." ;
        }
        return 1 ;
      }else{
        return 0 ;
      }
    }else{
      return (-1) ;
    }
  }else{
    return (-2) ;
  }
}
/*=============================================================================================================================*/
std::string SAE::ultimoSemestre(){
  int maximo = 0 ;
  std::string maximo2  ;
  for(std::list<Semestre*>::iterator it = this->listaSemestres.begin() ; it != this->listaSemestres.end() ; it++){
    if(atoi((*it)->GetCicloElctivo().c_str()) > maximo){
      maximo = atoi((*it)->GetCicloElctivo().c_str()) ;
      maximo2 = (*it)->GetCicloElctivo();
    }
  }
  return maximo2 ;
}
/*=============================================================================================================================*/
void SAE::Demandaestud(std::string idestud ){
  std::string semestreactual = this->ultimoSemestre() ;
  std::set<Asignatura *  , comparatorAsign > primerasasign;
  for(std::list<Semestre*>::iterator it = this->listaSemestres.begin() ; it != this->listaSemestres.end() ; it++){
    if((*it)->VerificarEstudiante2(idestud) != nullptr){
      std::list<ClaseXestudiante*> aux  =  (*it)->VerificarEstudiante2(idestud)->GetClases() ;
      for(std::list<ClaseXestudiante*>::iterator ite = aux.begin() ; ite != aux.end() ;  ite++){
        primerasasign.insert(this->VerificarAsignaturas((*ite)->Getclase()->Getidasig() )) ;
      }
    }
  }
  std::multimap<Asignatura* , Asignatura*  , comparatorAsign> mapreverse ;
  for (std::multimap<Asignatura*,Asignatura*>::iterator it = this->prerequisitos.begin(); it != this->prerequisitos.end(); ++it){
    mapreverse.insert(std::pair<  Asignatura* , Asignatura* >(it->second ,it->first) ) ;
  }

  std::pair <std::multimap<Asignatura* , Asignatura* >::iterator, std::multimap<Asignatura* ,Asignatura* >::iterator> ret;
  std::vector<std::set<Asignatura* , comparatorAsign> > temp  ;
  std::set<Asignatura* , comparatorAsign> miniset ;
  temp.push_back(primerasasign) ;

  for(  int zz = 0 ; zz < temp.size() ; zz++){

    for(std::set<Asignatura*>::iterator itq = temp[zz].begin() ; itq != temp[zz].end() ; itq++){
      std::pair <std::multimap<Asignatura* , Asignatura*  , comparatorAsign>::iterator, std::multimap<Asignatura* ,Asignatura*  , comparatorAsign>::iterator> ret =  mapreverse.equal_range(*itq) ;
      for (std::multimap<Asignatura* , Asignatura* , comparatorAsign >::iterator rit =ret.first; rit!=ret.second ; ++rit){
        if(!estaposmateria(temp ,rit->second )){
          miniset.insert(rit->second);

        }
      }
    }

    if(!miniset.empty())
    temp.push_back(miniset);
    miniset.clear();
  }


  for(  int zz = 0 ; zz < temp.size() ; zz++){

    for(std::set<Asignatura*>::iterator itq = temp[zz].begin() ; itq != temp[zz].end() ; itq++){
      std::pair <std::multimap<Asignatura* , Asignatura*  , comparatorAsign>::iterator, std::multimap<Asignatura* ,Asignatura*  , comparatorAsign>::iterator> ret2 =  this->prerequisitos.equal_range(*itq) ;
      for (std::multimap<Asignatura* , Asignatura* , comparatorAsign >::iterator rit =ret2.first; rit!=ret2.second ; ++rit){
        if(!estaposmateria(temp ,rit->second )){
          temp[zz].insert(rit->second);
        }
      }
    }


  }

  std::cout<<std::endl ;
  semestreactual = this->ultimoSemestre() ;
  for(int i = 0 ; i < temp.size() ; i++){
    std::cout<<"\n Semestre : "<<semestreactual<<std::endl ;
    semestreactual = this->siguienteSemestre(semestreactual) ;
    for(std::set<Asignatura*>::iterator itz = temp[i].begin() ; itz != temp[i].end() ; itz++){
      std::cout<<(*itz)->GetIdCurso()<<" - "<<(*itz)->GetNombreAsignatura()<< "\n";
    }
    std::cout<<std::endl ;
  }
  semestreactual = this->ultimoSemestre() ;
  std::queue<Asignatura*> colaaux ;
  ArbolBinarioAVL<SemestrexAsignaturas> arbolestud ;
  std::set<Asignatura* , comparatorAsign> tempset ;
  std::set<Asignatura* , comparatorAsign> tempset1 ;
  std::set<Asignatura* , comparatorAsign> tempset2 ;
  SemestrexAsignaturas* auxsem = new SemestrexAsignaturas(semestreactual) ;
  auxsem->setAsignaturas(temp[0]);
  arbolestud.insertar(*auxsem) ;

  semestreactual = this->siguienteSemestre(semestreactual);
  auxsem = new SemestrexAsignaturas(semestreactual) ;
  for(int zz = 1  ; zz < temp.size() ; zz++){
    for(std::set<Asignatura*>::iterator itq = temp[zz].begin() ; itq != temp[zz].end() ; itq++){
      tempset = this->estanPrerreq(*itq , arbolestud);
      if(tempset.empty()){
        tempset2.insert(*itq);
      }else{
        tempset1.insert(*itq);
      }
    }
    auxsem->setAsignaturas(tempset2);
    arbolestud.insertar(*auxsem) ;
    tempset2.clear();
    semestreactual = this->siguienteSemestre(semestreactual);
    auxsem = new SemestrexAsignaturas(semestreactual) ;
    for(std::set<Asignatura*>::iterator ity = tempset1.begin() ; ity != tempset1.end() ; ity++){
      tempset = this->estanPrerreq(*ity , arbolestud);
      if(tempset.empty()){
        tempset2.insert(*ity);
        colaaux.push(*ity);
      }
    }
    while(!colaaux.empty()){
      tempset1.erase(colaaux.front());
      colaaux.pop();
    }
  }
  auxsem->setAsignaturas(tempset2);
  arbolestud.insertar(*auxsem) ;
  tempset2.clear();
  while(!tempset1.empty()){
    semestreactual = this->siguienteSemestre(semestreactual);
    auxsem = new SemestrexAsignaturas(semestreactual) ;
    for(std::set<Asignatura*>::iterator ity = tempset1.begin() ; ity != tempset1.end() ; ity++){
      tempset = this->estanPrerreq(*ity , arbolestud);
      if(tempset.empty()){
        tempset2.insert(*ity);
        colaaux.push(*ity);
      }
    }
    while(!colaaux.empty()){
      tempset1.erase(colaaux.front());
      colaaux.pop();
    }
    auxsem->setAsignaturas(tempset2);
    arbolestud.insertar(*auxsem) ;
    tempset2.clear();
  }

std::cout<<std::endl;
arbolestud.inOrden();

}
/*=============================================================================================================================*/
std::string SAE::siguienteSemestre(std::string& semestre){
  std::string temp = "" ;
  std::string temp2 = "" ;
  std::string temp3 = "" ;
  int i ;
  for(i=0 ; i  < (semestre.size() - 2) ; i++){
    temp += semestre[i] ;
  }
  for(int j = (i) ; j < semestre.size() ; j++){
    temp2 += semestre[j] ;
  }
  int a = atoi(temp2.c_str()) ;
  if( a <= 20){
    a += 10 ;
    temp3 += temp;
    temp3 += std::to_string(a);
  }else{
    int b = atoi(temp.c_str()) ;
    b+= 1 ;
    a = 10 ;
    temp3 += std::to_string(b) ;
    temp3 += std::to_string(a) ;
  }
  return temp3 ;
}
/*=============================================================================================================================*/
bool SAE::verificarsiesPrerrequisito(Asignatura* asign1 , Asignatura* asign2) {
  bool es = false ;
  std::pair <std::multimap<Asignatura* , Asignatura* >::iterator, std::multimap<Asignatura* ,Asignatura* >::iterator> ret;
  ret = this->prerequisitos.equal_range(asign1);
  for (std::multimap<Asignatura* , Asignatura* >::iterator it=ret.first; it!=ret.second && !es; ++it){
    if(it->second == asign2){
      es = true ;
    }
  }
  return es ;
}
/*=============================================================================================================================*/
bool SAE::esprerrequisito(Asignatura* asign , std::set<Asignatura* , comparatorAsign > &set1) {
  bool ya = false ;
  for(std::set<Asignatura*>::iterator it = set1.begin() ; it != set1.end() && !ya ; ++it){
    if(this->verificarsiesPrerrequisito(*it , asign)){
      ya = true ;
    }
  }
  return ya ;
}
/*=============================================================================================================================*/
SemestrexAsignaturas::SemestrexAsignaturas(std::string semestre){
  this->semestre = semestre ;
}
/*=============================================================================================================================*/
SemestrexAsignaturas::SemestrexAsignaturas(){

}
/*=============================================================================================================================*/
void SemestrexAsignaturas::Insertar(Asignatura* asignatura){
  this->asignaturas.insert(asignatura);
}
/*=============================================================================================================================*/
Asignatura* SemestrexAsignaturas::buscar(Asignatura* asignatura){
  if(this->asignaturas.find(asignatura) != this->asignaturas.end()){
    return *(this->asignaturas.find(asignatura) );
  }else{
    return nullptr;
  }
}
/*=============================================================================================================================*/
void SemestrexAsignaturas::setAsignaturas(std::set<Asignatura* , comparatorAsign> asignaturas) {
  this->asignaturas = asignaturas ;
}
/*=============================================================================================================================*/
void SAE::eliminarInnecesarios(std::set<Asignatura* , comparatorAsign>& siguientes, ArbolBinarioAVL<SemestrexAsignaturas> &arbol  ){
  std::queue<Asignatura*> cola  ;
  for(ArbolBinarioAVL<SemestrexAsignaturas>::iterator it = arbol.begin() ; it != arbol.end() ; it++){
    for(std::set<Asignatura*>::iterator ite = siguientes.begin() ; ite != siguientes.end() ; ite++){
      if((*it).buscar(*ite) != nullptr){
        cola.push(*ite);
      }
    }
  }
  while(!cola.empty()){
    siguientes.erase(cola.front());
    cola.pop();
  }
}
/*=============================================================================================================================*/
std::set<Asignatura* , comparatorAsign>  SAE::estanPrerreq(Asignatura* asign , ArbolBinarioAVL<SemestrexAsignaturas> &arbol) {
  std::pair <std::multimap<Asignatura* , Asignatura* >::iterator, std::multimap<Asignatura* ,Asignatura* >::iterator> ret;
  std::queue<Asignatura*> colaaux ;
  ret = this->prerequisitos.equal_range(asign);
  std::set<Asignatura* , comparatorAsign> setaux ;
  for (std::multimap<Asignatura* , Asignatura* >::iterator rit=ret.first; rit!=ret.second ; ++rit){
    setaux.insert(rit->second);
  }
  for(ArbolBinarioAVL<SemestrexAsignaturas>::iterator it = arbol.begin() ; it != arbol.end() && !setaux.empty() ; it++){
    for(std::set<Asignatura*>::iterator ite = (*it).asignaturas.begin() ; ite != (*it).asignaturas.end() && !setaux.empty() ; ite++){
      for(std::set<Asignatura*>::iterator sit = setaux.begin() ; sit != setaux.end() ; sit++){
        if(*ite == *sit){
          colaaux.push(*sit);
        }
      }
    }
  }
  while(!colaaux.empty()){
    setaux.erase(colaaux.front());
    colaaux.pop();
  }
  return setaux;
}
/*=============================================================================================================================*/
void SAE::agregardemas(std::set<Asignatura*> &asign  , ArbolBinarioAVL<SemestrexAsignaturas> &arbol) {

}
/*=============================================================================================================================*/
bool SAE::estaposmateria(std::vector<std::set<Asignatura* , comparatorAsign> > &temp , Asignatura* asign ) {
  bool ya = false  ;
  for(  int zz = 0 ; zz < temp.size() && !ya; zz++){
    for(std::set<Asignatura*>::iterator itq = temp[zz].begin() ; itq != temp[zz].end() && !ya; itq++){
      if(*itq == asign){
        ya = true ;
      }
    }
  }
  return ya ;
}
#endif
