#include <iostream>
#include <string.h>
#include "TadArchivo.h"

//===================================================
const std::string red("\x1B[31m");
const std::string blue("\x1B[34m") ;
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");
const std::string bold("\x1B[1m") ;
const std::string white("\x1B[37m");
const std::string underline("\x1B[4m");
const std::string backgroundblue("\x1B[44m");
const std::string backgroundblack("\x1B[49m");
const std::string backgroundwhite("\x1B[47m");
//===================================================

/* PROTOTIPO DE FUNCIONES */

/* CONVIERTE CADENA DE STRING EN ENTERO */
int str2int(const std::string& str);
/* SEPARA UN STRING PARA OBTENER LA PRIMERA PARTE */
std::string sacarcomando(char*argv1) ;
/* SEPARA UN STRING PARA OBTENER LA SEGUNDA PARTE */
std::string sacarnombrearch(char*argv1) ;
/* SEPARA UN STRING PARA OBTENER EL NUMERO DE PALABRAS/ARGUMENTOS PASADOS */
int ArgNumber(std::string arguments);
/* SEPARA UN STRING PARA OBTENER UN ARGUMENTO EN ESPECIFICO */
void sacarnombrearch2(std::string& str);
/*=============================================================================================================================*/
int main(int argc, char const *argv[]) {

  char* user_name = getenv("USER");
  char*argv1;
  char*argv2;
  int zz1 ;
  std::string comando ;
  std::string semestre1 ;
  SAE sae ;
  std::string archivo ;
  bool a = true ;
  bool prerreq = false ;

  std::cout<<cyan<<bold<<std::endl<<"\t\t  ███████╗ █████╗ ███████╗";
  std::cout<<std::endl<<"\t\t  ██╔════╝██╔══██╗██╔════╝";
  std::cout<<std::endl<<"\t\t  ███████╗███████║█████╗  ";
  std::cout<<std::endl<<"\t\t  ╚════██║██╔══██║██╔══╝  ";
  std::cout<<std::endl<<"\t\t  ███████║██║  ██║███████╗";
  std::cout<<std::endl<<"\t\t  ╚══════╝╚═╝  ╚═╝╚══════╝"<<std::endl;
  bool dd   ;
  do{
    argv1= new char[300];
    std::cout<<std::endl<<blue<<bold<<underline<<user_name<<yellow<<" $ "<<reset<<green<<"" ;
    std::cin.getline (argv1,300);
    std::cout<<bold<<white ;
    archivo = "  " ;
    std:: string archivo2(argv1);
    comando = sacarcomando(argv1) ;
    if(ArgNumber(argv1) <= 2){
      archivo = sacarnombrearch(argv1) ;
    }else{
      sacarnombrearch2(archivo2);
      archivo = sacarnombrearch(argv1) ;
    }

    Archivo z(archivo , &sae) ;
    if(!z.archopen() && (comando == "cargar_info_estud" || comando == "cargar_info_asign" || comando == "cargar_info_prerreq")){
      std::cout<<bold<<red<<"\n\t --- ERROR AL ABRIR EL ARCHIVO --- \n";
      continue ;
    }
    switch (str2int(comando)) {
      /* CASO DE LLENAR INFORMAICION SALONES Y CLASES */
      case 1772:
      if(archivo != " " || z.archopen()){
        std::cout<<"\n"<<z.llenarArch()<<std::endl;
      }else{
        std::cout<<"\n \t --- Nombre de archivo incorrecto ó error abriendo el archivo!! --- \n" ;
      }
      break ;
      /* CASO DE LLENAR LA INFORMACION DE ESTUDIANTES E INSCRIPCIONES */
      case 1791:
      if(archivo != " " || z.archopen()){
        std::cout<<std::endl<<z.llenarArch2()<<std::endl;
      }else{
        std::cout<<"\n \t --- Nombre de archivo incorrecto ó error abriendo el archivo!! --- \n" ;
      }
      break ;
      /* CASO DE MOSTRAR EL HORARIO DE UN ESTUDIANTE */
      case 1400:
      if(archivo != "  "){
        std::cout<<std::endl<<sae.horarioestud(archivo)<<std::endl<<backgroundblack;
      }else{
        std::cout<<std::endl<<"\t Ingrese un id valido \n" ;
      }
      break ;
      /* LLENAR PRE REQUISITOS */
      case 2011:
      /* LLENAR PRE REQUISITO */
      if(archivo != " " && z.archopen()){
        std::cout<<std::endl<<z.llenarprereq();
        prerreq = true ;
      }else{
        std::cout<<"\n \t --- Nombre de archivo incorrecto ó error abriendo el archivo!! --- \n" ;
      }
      break ;
      case 1267:
      /* PROY_DEMANDA */
      std::cout<<std::endl;
      if(prerreq){
        int demandaasign = sae.DemandaAsign(sae.ultimoSemestre(), archivo);
        if(demandaasign != -1 && demandaasign!= -2 && demandaasign!= 0 ){
          std::cout<<std::endl<<bold<<red<<"\n Demanda basados en el semestre "<<green<<sae.ultimoSemestre()<<white<<" \n " ;
        }else{
          if(demandaasign == -1){
            std::cout<<"\n \n La asignatura no esta registrada en el sistema ! "<<std::endl;
          }
          if(demandaasign== -2){
            std::cout<<std::endl<<" El semestre no existe !  \n" ;
          }
          if(demandaasign == 0){
            std::cout<<"\n La asignatura no tiene prerrequsitos registrados ! \n"<<std::endl ;
          }
        }
      }
      else{
        std::cout<<"\n \t ===== PRIMERO LLENE LA INFORMACION DE PRE REQUISITOS ===== \n" ;
      }
      break ;
      /* PROYECTAR SEMESTRES */
      case 1540:
      /* PROY_SEMESTRES */
      std::cout<<std::endl;
      if(prerreq){
        if(archivo != ""){
          sae.Demandaestud(archivo);
        }
      }
      else{
        std::cout<<"\n \t ===== PRIMERO LLENE LA INFORMACION DE PRE REQUISITOS ===== \n" ;
      }
      break ;
      /* CASO DE RED SOCIAL */
      case 1045:
      dd = false ;
      if(archivo == " "){
        semestre1 = sae.ultimoSemestre() ;
        dd = sae.makeRedSocial(semestre1);
        //sae.printSocial();
      }else{
        semestre1 = archivo ;
        dd = sae.makeRedSocial(archivo);
        //sae.printSocial();
      }
      if(!dd){
        std::cout<<bold<<red<<"\n\t - NO EXISTE SEMESTRE / NO SE CARGO INFORMACION NECESARIA. - \n \n";
      }else{
        std::cout<<bold<<green<<"\n\t - SE CARGO CORRECTAMENTE EL GRAFO - \n \n";
      }
      break ;
      /* CASO GRADOS SEP */
      case 1796:
      if(dd){
        zz1 = sae.GradosSeparacion(archivo2 , archivo , semestre1) ;
        if (zz1 == -1){
          //SEMESTRE NO EXISTE
          std::cout<<bold<<red<<"\n\t --- INFORMACION DE SEMESTRE NO FUE CARGADA CORRECTAMENTE --- \n" ;
        }else if(zz1 == -2){
          // ALGUNO DE LOS ESTUDIANTES NO EXISTE
          std::cout<<bold<<red<<"\n\t --- ALGUNO/AMBOS ESTUDIANTE(S) NO SE ENCUENTRA(N) REGISTRADO(S) EN EL SISTEMA --- \n" ;
        }else if (zz1 == 1 || zz1 == 0 ){
          // NO EXISTE CONECCION
          std::cout<<bold<<red<<"\n\t --- NO EXISTE CONECCION ALGUNA ENTRE LOS DOS ALUMNOS --- \n" ;
        }else if ( zz1 == 2){
          // CONECCION DIRECCTA
          std::cout<<bold<<green<<"\n\t --- EXISTE UNA CONECCION DIRECTA ENTRE LOS DOS ESTUDIANTES ---\n" ;
        }else if(zz1 > 2 && zz1 < 7  ){
          // CONECCION NORMAL CON MAS DE UNO INTERMEDIO
          std::cout<<bold<<green<<"\n *) EXISTE UNA CONECCION DE " << zz1 - 2 <<" GRADO(S) DE SEPARACION ENTRE LOS DOS ESTUDIANTES \n" ;
        }else{
          std::cout<<bold<<red<<"\n *) EXISTE UNA CONECCION DE " << zz1 - 2 <<" GRADO(S) DE SEPARACION ENTRE LOS DOS ESTUDIANTES , PERO INCOMPLE LA LEY DE LOS 6 GRADOS.\n" ;
        }
      }else{
        std::cout<<bold<<red<<"\n\t - NO SE HA GENERADO EL GRAFO - \n \n";
      }
      break;
      /* CASO DE FINALIZAR PROGRAMA */
      case 539:
      a = false ;
      std::cout<<std::endl<<underline<<green<<"\t                                                         " ;
      std::cout<<std::endl<<underline<<green<<"\t ========= Muchas Gracias por usar el programa ========= \n" ;
      std::cout<<reset<<std::endl<<bold<<magenta<<std::endl  ;

      std::cout<<std::endl<<"\t__________________________________________________________";
      std::cout<<std::endl<<"\t|                                                        |";
      std::cout<<std::endl<<"\t|                      ..:::::::::..                     |";
      std::cout<<std::endl<<"\t|                  ..:::aad8888888baa:::..               |";
      std::cout<<std::endl<<"\t|              .::::d:?88888888888?::8b::::.             |";
      std::cout<<std::endl<<"\t|            .:::d8888:?88888888??a888888b:::.           |";
      std::cout<<std::endl<<"\t|          .:::d8888888a8888888aa8888888888b:::.         |";
      std::cout<<std::endl<<"\t|         ::::dP::::::::88888888888::::::::Yb::::        |";
      std::cout<<std::endl<<"\t|        ::::dP:::::::::Y888888888P:::::::::Yb::::       |";
      std::cout<<std::endl<<"\t|      :::::Y8baaaaaaaaaa88P:T:Y88aaaaaaaaaad8P:::::     |";
      std::cout<<std::endl<<"\t|      :::::::Y88888888888P::|::Y88888888888P:::::::     |";
      std::cout<<std::endl<<"\t|      ::::::::::::::::888:::|:::888::::::::::::::::     |";
      std::cout<<std::endl<<"\t|      `:::::::::::::::8888888888888b::::::::::::::'     |";
      std::cout<<std::endl<<"\t|       :::::::::::::::88888888888888::::::::::::::      |";
      std::cout<<std::endl<<"\t|        :::::::::::::d88888888888888:::::::::::::       |";
      std::cout<<std::endl<<"\t|         ::::::::::::88::88::88:::88::::::::::::        |";
      std::cout<<std::endl<<"\t|          `::::::::::88::88::88:::88::::::::::'         |";
      std::cout<<std::endl<<"\t|            `::::::::88::88::P::::88::::::::'           |";
      std::cout<<std::endl<<"\t|              `::::::88::88:::::::88::::::'             |";
      std::cout<<std::endl<<"\t|                 ``:::::::::::::::::::''                |";
      std::cout<<std::endl<<"\t|                      ``:::::::::''                     |";
      std::cout<<std::endl<<"\t|                                                        |";
      std::cout<<std::endl<<"\t|________________________________________________________|";
      std::cout<<std::endl<<""<<bold<<cyan<<std::endl<<std::endl;
      std::cout <<std::endl<< R"(
                                /|         ,
                              ,///        /|
                             // //     ,///
                            // //     // //
                           // //     || ||
                           || ||    // //
                           || ||   // //
                           || ||  // //
                           || || || ||
                           \\,\|,|\_//
                            \\)\)\\|/
                            )-."" .-(
                           //^\` `/^\\
                          //  |   |  \\
                        ,/_| 0| _ | 0|_\,
                      /`    `"=.v.="`    `\
                     /`    _."{_,_}"._    `\
                     `/`  ` \  |||  / `  `\`
                      `",_  \\=^~^=//  _,"`
                          "=,\'-=-'/,="
                              '---'

      ESTO FUE TODO POR HOY EN FANTASIAS ANIMADAS DE AYER Y HOY
)" << '\n';
std::cout<<std::endl<<""<<reset<<std::endl<<std::endl;
      break ;
      /* CASO DE INSTRUCTIVO */
      case 532:
      std::cout<<std::endl<<underline<<bold<<red<<"\t ========= INSTRUCCIONES ========= \n" <<reset<<bold<<white;
      if (archivo == "salir"){
        std::cout<<bold<<blue<<"\n\t*comando:"<<bold<<white<<" salir\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n"<<bold<<white;
        std::cout<<"\n\t-(No tiene salida por pantalla)\n";
        std::cout<<bold<<red<<"\n\tDescripcion:"<<bold<<white<<" Termina la ejecucion de la aplicacion.\n";
      }	else if (archivo == "cargar_info_asign"){
        std::cout<<bold<<blue<<"\n\t*comando: "<<bold<<white<<"cargar_info_asign\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n"<<bold<<white;
        std::cout<<bold<<magenta<<"\n\t-(Semestre ya inicializado):"<<bold<<white<<"Informaci�n de asignaturas y clases para el semestre IDsem ya ha sido cargada\n";
        std::cout<<bold<<magenta<<"\n\t(Archivo no existe)"<<bold<<white<<" El archivo listaClasesAsignacionAula-IDsem.csv no existe o es ilegible.\n";
        std::cout<<bold<<magenta<<"\n\t(resultado exitoso) "<<bold<<white<<"Informaci�n de asignaturas y clases para el semestre IDsem ha sido cargada exitosamente.\n";
        std::cout<<bold<<red<<"\n\t Descripci�n: "<<bold<<white<<"Carga en el sistema la informaci�n de asignaturas y clases programadas para un semestre\n"
        "\tespec�fico. El comando debe estructurar la informaci�n a partir del archivo de forma que sea f�cil recuperar\n"
        "\tlos datos m�nimos posteriormente. La informaci�n debe ser verificada para no incluir registros repetidos o incompletos";
      }
      else if (archivo == "cargar_info_estud"){
        std::cout<<bold<<blue<<"\n\t*comando: "<<bold<<white<<"cargar_info_estud\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n"<<bold<<white;
        std::cout<<bold<<magenta<<"\n\t-(Semestre ya inicializado): "<<bold<<white<<"Informaci�n de inscripciones de estudiantes para el semestre IDsem ya ha sido cargada.\n";
        std::cout<<bold<<magenta<<"\n\t-(Semestre no coincide): "<<bold<<white<<"Semestre IDsem no coincide con los datos de asignaturas y clases ya cargados.\n";
        std::cout<<bold<<magenta<<"\n\t(Archivo no existe):"<<bold<<white<<" El archivo listaClasesInscritasEstud-IDsem.csv no existe o es ilegible. \n";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso): "<<bold<<white<<"Informaci�n de inscripciones de estudiantes para el semestre IDsem ha sido cargada exitosamente. \n";
        std::cout<<bold<<magenta<<"\n\tdescripci�n: "<<bold<<white<<" Carga en el sistema la informaci�n de inscripciones de estudiantes para un semestre espec�fico.\n"
        "\tEl semestre debe coincidir con aquel para el cual ya se carg� la informaci�n de asignaturas y clases progra-"
        "\tmadas, para evitar problemas de conexi�n de la informaci�n. El comando debe estructurar la informaci�n a"
        "\tpartir del archivo de forma que sea f�cil recuperar los datos m�nimos posteriormente. Adem�s, la informaci�n"
        "\tdebe ser verificada para no incluir registros repetidos o incompletos \n";
      }
      else if (archivo == "horario_estud"){
        std::cout<<bold<<blue<<"\n\t*comando:"<<bold<<white<<" horario_estudID_estud\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<bold<<magenta<<"\n\t-(Informaci�n incompleta):"<<bold<<white<<" La informaci�n necesaria (programaci�n de asignaturas, inscripciones \n de estudiantes) no ha sido cargada completamente.\n";
        std::cout<<bold<<magenta<<"\n\t(Estudiante no existe):"<<bold<<white<<" El estudiante con identificaci�n ID_estud no est� registrado en el sistema..\n";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso)"<<bold<<white<<" El horario semanal para el estudiante nombre_completo_estud es: \n";
        std::cout<<bold<<red<<"\tdescripci�n:"<<bold<<white<<"El comando permite conocer el horario de clases inscrito por un estudiante, discriminado por\n"
        "\tlos d�as de la semana. Para cada d�a, deben aparecer en orden cronol�gico las clases de las asignaturas,\n"
        "\tindicando el sal�n donde se llevar�n a cabo. El comando debe verificar que el estudiante tenga informaci�n\n"
        "\tcargada en el sistema para poder generar el horario de clases.\n";
      }
      else if(archivo == "cargar_info_prerreq"){
        std::cout<<bold<<blue<<"\n\t*comando:"<<bold<<white<<" cargar_info_prerreq listaprerreq.csv \n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<bold<<magenta<<"\n\t(Prerrequisitos ya inicializados)"<<bold<<white<<" Información de prerrequisitos para las asignaturas ya ha sido cargada\n";
        std::cout<<bold<<magenta<<"\n\t(Información incompleta)"<<white<<" La información necesaria (programación de asignaturas) no ha sido cargada correctamente\n";
        std::cout<<bold<<magenta<<"\n\t(Archivo no existe)"<<bold<<white<<" El archivo listaPrerrequisitos.csv no existe o es ilegible. \n";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso)"<<bold<<white<<" Información de asignaturas y sus prerrequisitos ha sido cargada exitosamente.\n";
        std::cout<<bold<<red<<"\tdescripción:"<<bold<<white<<" Registra en el sistema la información de los prerrequisitos para cada asignatura a partir \n"
        "\tdel archivo dado, en el cual se registran pares de identificadores de asignaturas (asignatura - prerrequi \n"
        "\tsito). La información de asignaturas y requisitos se encuentra en el documento oficial de la Dirección de\n"
        "\tCarrera de Ingeniería de Sistemas (http://ingenieria.javeriana.edu.co/documents/2838900/2841579/PreRequisitos_CarreraIngSistemas(Act-sep-2016_v0).pdf) \n";
      }
      else if(archivo == "proy_demanda"){
        std::cout<<bold<<blue<<"\n\t*comando:"<<bold<<white<<" proy_demanda ID_asign\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<bold<<magenta<<"\n\t(Información incompleta)"<<bold<<white<<" La información necesaria (programación de asignaturas, prerrequisitos, inscripciones de estudiantes) no ha sido cargada completamente. \n";
        std::cout<<bold<<magenta<<"\n\t(Asignatura no existe)"<<bold<<white<<" La asignatura con identificador ID_asig no está registrada en el sistema.\n";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso)"<<bold<<white<<" La demanda proyectada para la asignatura nombre_asignatura es: \n";
        std::cout<<bold<<magenta<<"\n\t(Resultado adverso)"<<bold<<white<<" No existe suficiente información para calcular la demanda proyectada para la asignatura nombre_asignatura .\n";
        std::cout<<bold<<red<<"\tdescripción:"<<bold<<white<<" El comando permite calcular la demanda proyectada para la asignatura indicada, a partir de la información actual de estudiantes inscritos en las asignaturas prerrequisito. Para esto, se requiere calcular \n"
        "\tel árbol de prerrequisitos de la asignatura dada, que almacene asignaturas e inscritos en cada nodo, y que   conecte los nodos de acuerdo a los prerrequisitos ya registrados con el comando cargar_info_prerreq.  \n"
        "\tLa demanda proyectada para cada semestre futuro dependerá de la cantidad de inscritos actuales en cada una de las asignaturas prerrequisito, teniendo en cuenta la distancia sobre el árbol (en semestres) entre la   asignatura actual y cada prerrequisito.\n";
      }
      else if(archivo == "proy_semestres"){
        std::cout<<bold<<blue<<"\n\t*comando:"<<bold<<white<<" proy_semestres ID_estud \n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<bold<<magenta<<"\n\t(Información incompleta)"<<bold<<white<<" La información necesaria (programación de asignaturas, prerrequisitos, inscripciones de estudiantes) no ha sido cargada completamente.\n";
        std::cout<<bold<<magenta<<"\n\t(Estudiante no existe)"<<bold<<white<<" El estudiante con identificación ID_estud no está registrado en el   sistema.\n";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso)"<<bold<<white<<" Las asignaturas proyectadas para el estudiante nombre_estudiante son:\n";
        std::cout<<bold<<magenta<<"\n\t(Resultado adverso)"<<bold<<white<<" No existe suficiente información para generar la proyección de asignaturas  para el estudiante nombre_estudiante.\n";
        std::cout<<bold<<red<<"\tdescripción: "<<bold<<white<<"El comando permite generar una proyección de las asignaturas a cursas en semestres futuros\n"
        "\tpor el estudiante dado. Para esto, se utilizan las asignaturas actualmente inscritas por el estudiante, y\n"
        "\tpara cada una de ellas se genera un árbol de posibles asignaturas futuras, de acuerdo a la información de \n"
        "\tprerrequisitos ya registrada con el comando cargar_info_prerreq. Luego, se combina la información de"
        "\testos árboles para informar las posibles asignaturas a cursar por el estudiante en cada semestre futuro.";
      }else if(archivo == "red_social"){
        std::cout<<bold<<blue<<"\n\t*Comando :"<<bold<<white<<" red_social [IDSem]\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<bold<<magenta<<"\n\t(Información incompleta)"<<bold<<white<<" La información necesaria (programación de asignaturas, inscripciones";
        std::cout<<"\n\tde estudiantes) no ha sido cargada completamente.";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso)"<<bold<<white<<" La red social de los estudiantes ha sido generada exitosamente.";
        std::cout<<bold<<red<<"\n\tDescripcion : "<<bold<<white<<"descripción: Utilizando la información de asignaturas programadas e inscripciones de estudiantes, el sistema";
        std::cout<<"\n\tgenera un grafo que representa la red social del semestre actual, donde cada estudiante se conecta a otros";
        std::cout<<"\n\tsi y sólo sí se encuentran cursando la misma clase (son compañeros de asignatura y de clase).";
        std::cout<<bold<<yellow<<"\n\tUso :"<<bold<<white<<" Si no propociona el id del semestre se usara el ultimo cargado.";
      }else if(archivo == "grados_separacion"){
        std::cout<<bold<<blue<<"\n\t*comando: "<<bold<<white<<"grados_separacion ID_estud_1 ID_estud_2";
        std::cout<<bold<<blue<<"\n\tsalida en pantalla:";
        std::cout<<bold<<magenta<<"\n\t(Red social no generada)"<<bold<<white<<" La red social de los estudiantes aún no ha sido generada.";
        std::cout<<bold<<magenta<<"\n\t(Estudiante no existe)"<<bold<<white<<" El estudiante con identificación ID_estud_1 (y/o ID_estud_2 ) no está";
        std::cout<<"\n\tregistrado en el sistema.";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso 1)"<<bold<<white<<" El estudiante nombre_estud_1 conoce al estudiante nombre_estud_2 de";
        std::cout<<"\n\tforma directa.";
        std::cout<<bold<<magenta<<"\n\t(Resultado exitoso 2)"<<bold<<white<<" El estudiante nombre_estud_1 conoce al estudiante nombre_estud_2 a";
        std::cout<<"\n\ttravés de n conocidos intermedios, los cuales son:";
        std::cout<<bold<<magenta<<"\n\t(Resultado adverso)"<<bold<<white<<" El estudiante nombre_estud_1 no conoce al estudiante nombre_estud_2 .";
        std::cout<<bold<<red<<"\n\tdescripción:"<<white<<" Dados los identificadores de dos estudiantes, el comando inspecciona la red social generada";
        std::cout<<"\n\tpara el semestre en busca de los conocidos conectados que permitan llegar de un estudiante a otro, confirmando";
        std::cout<<"\n\tla hipótesis de los “seis grados de separación”. El comando debe verificar que los estudiantes estén";
        std::cout<<"\n\tcargados en el sistema y que el grafo con la red social ya haya sido generado. Si los estudiantes están";
        std::cout<<"\n\tconectados de forma directa, o no existe conexión alguna entre ellos, el sistema debe informar la situación";
        std::cout<<"\n\tcon el mensaje apropiado";

      }else{
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"horario_estud ID_estud\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"cargar_info_estud\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"cargar_info_asign\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"cargar_info_prerreq\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"proy_demanda\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"proy_semestres\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"red_social\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"grados_separacion\n";
        std::cout<<bold<<green<<"\n\t*comando: "<<white<<"salir\n";
      }
      break ;
      case 0:
      break ;
      default :
      std::cout<<std::endl<<"Informacion : "<<comando<<" No existe , por favor tipee ayuda para obtener informacion \n" ;
      //std::cout<<std::endl<<"VALOR NUMERICO : "<<str2int(comando);
      break ;
    }
    delete argv1 ;
  }while(a) ;
  return 0;
}
/*=============================================================================================================================*/
int str2int(const std::string& str) {
  int i = 0;
  std::string::const_iterator it = str.begin();
  while (it != str.end()) {
    i += *it++ ;
  }
  return i;
}
/*=============================================================================================================================*/
std::string sacarcomando(char*argv1) {
  std::string a = "" ;
  bool b = true ;
  for (int i=0 ; (i < strlen(argv1) )&& b;i++){

    if (argv1[i] == ' '){
      b = false ;
    }
    if(b){
      a += argv1[i] ;
    }
  }
  return a ;
}
/*=============================================================================================================================*/
std::string sacarnombrearch(char*argv1) {
  std::string a = "" ;
  bool b = true ;
  bool c = false ;
  int w = 0 ;
  for (int i=0 ; (i < strlen(argv1) )&& b;i++){
    if (argv1[i] == ' '){
      c = true ;
      w = i ;
    }
  }
  if(c){
    for (int j=w+1 ; j < strlen(argv1)&& b;j++){

      a += argv1[j] ;
      if (argv1[j] == '\0'){
        b = false ;
      }
      if (argv1[j] == '\n'){
        b = false ;
      }
    }
    return a ;
  }else{
    return " " ;
  }
}
/*=============================================================================================================================*/
int ArgNumber(std::string arguments){
  std::string a = arguments ;
  int cont = 0 ;
  while (a.find(" ", 0) != std::string::npos){
    size_t  pos = a.find(" ", 0);
    a.erase(0, pos + 1);
    cont++ ;
  }
  return ++cont ;
}
/*=============================================================================================================================*/
void sacarnombrearch2(std::string& str){
  size_t  pos = str.find(" ", 0);
  str.erase(0, pos + 1) ;
  size_t  pos1 = str.find(" ", 0);
  str.erase(pos1  , str.size()) ;
}
/*=============================================================================================================================*/
// POR SANTIAGO CHAUSTRE.
