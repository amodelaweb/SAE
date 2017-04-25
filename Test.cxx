#include <iostream>
#include <string.h>
#include "TadArchivo.h"

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

/* PROTOTIPO DE FUNCIONES */

/* CONVIERTE CADENA DE STRING EN ENTERO */
int str2int(const std::string& str);
/* SEPARA UN STRING PARA OBTENER LA PRIMERA PARTE */
std::string sacarcomando(char*argv1) ;
/* SEPARA UN STRING PARA OBTENER LA SEGUNDA PARTE */
std::string sacarnombrearch(char*argv1) ;

/*=============================================================================================================================*/
int main(int argc, char const *argv[]) {

  char * user_name = getenv("USER");
  char*argv1= new char[300];
  std::string comando ;
  SAE sae ;
  std::string archivo ;
  bool a = true ;
  bool prerreq = false ;

  do{
    std::cout<<std::endl<<blue<<bold<<underline<<user_name<<yellow<<" $ "<<reset<<green<<"" ;
    std::cin.getline (argv1,300);
    std::cout<<bold<<white ;
    archivo = "  " ;
    comando = sacarcomando(argv1) ;
    archivo = sacarnombrearch(argv1) ;
    Archivo z(archivo , &sae) ;

    switch (str2int(comando)) {
      /* CASO DE LLENAR INFORMAICION SALONES Y CLASES */
      case 1772:
      if(archivo != " " || z.archopen()){
        std::cout<<"\n"<<z.llenarArch()<<std::endl;
      }else{
        std::cout<<"\n \t --- Nombre de archivo incorrecto ó error abriendo el archivo!! --- " ;
      }
      break ;
      /* CASO DE LLENAR LA INFORMACION DE ESTUDIANTES E INSCRIPCIONES */
      case 1791:
      if(archivo != " " || z.archopen()){
        std::cout<<std::endl<<z.llenarArch2()<<std::endl;
      }else{
        std::cout<<"\n \t --- Nombre de archivo incorrecto ó error abriendo el archivo!! --- " ;
      }
      break ;
      /* CASO DE MOSTRAR EL HORARIO DE UN ESTUDIANTE */
      case 1400:
      if(archivo != "  "){
        std::cout<<std::endl<<sae.horarioestud(archivo)<<std::endl;
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
        std::cout<<"\n \t --- Nombre de archivo incorrecto ó error abriendo el archivo!! --- " ;
      }
      break ;
      case 1267:
      /* PROY_DEMANDA */
      if(prerreq)
      sae.DemandaAsign("1130", archivo);
      else
      std::cout<<"\n \t ===== PRIMERO LLENE LA INFORMACION DE PRE REQUISITOS =====" ;
      break ;
      /* PROYECTAR SEMESTRES */
      case 1540:
      /* PROY_SEMESTRES */
      break ;
      /* CASO DE FINALIZAR PROGRAMA */
      case 539:
      a = false ;
      std::cout<<std::endl<<underline<<green<<"\t                                                           " ;
      std::cout<<std::endl<<underline<<green<<"\t ========= Muchas Gracias por usar el programa ========= \n" ;
      std::cout<<reset<<std::endl<<bold<<magenta  ;


      std::cout<<std::endl<<"\t                      ..:::::::::..";
      std::cout<<std::endl<<"\t                  ..:::aad8888888baa:::..";
      std::cout<<std::endl<<"\t              .::::d:?88888888888?::8b::::.";
      std::cout<<std::endl<<"\t            .:::d8888:?88888888??a888888b:::.";
      std::cout<<std::endl<<"\t          .:::d8888888a8888888aa8888888888b:::.";
      std::cout<<std::endl<<"\t         ::::dP::::::::88888888888::::::::Yb::::";
      std::cout<<std::endl<<"\t        ::::dP:::::::::Y888888888P:::::::::Yb::::";
      std::cout<<std::endl<<"\t      :::::Y8baaaaaaaaaa88P:T:Y88aaaaaaaaaad8P:::::";
      std::cout<<std::endl<<"\t      :::::::Y88888888888P::|::Y88888888888P:::::::";
      std::cout<<std::endl<<"\t      ::::::::::::::::888:::|:::888::::::::::::::::";
      std::cout<<std::endl<<"\t      `:::::::::::::::8888888888888b::::::::::::::'";
      std::cout<<std::endl<<"\t       :::::::::::::::88888888888888::::::::::::::";
      std::cout<<std::endl<<"\t        :::::::::::::d88888888888888:::::::::::::";
      std::cout<<std::endl<<"\t         ::::::::::::88::88::88:::88::::::::::::";
      std::cout<<std::endl<<"\t          `::::::::::88::88::88:::88::::::::::'";
      std::cout<<std::endl<<"\t            `::::::::88::88::P::::88::::::::'";
      std::cout<<std::endl<<"\t              `::::::88::88:::::::88::::::'";
      std::cout<<std::endl<<"\t                 ``:::::::::::::::::::''";
      std::cout<<std::endl<<"\t                      ``:::::::::''";
      std::cout<<std::endl<<""<<reset<<std::endl;

      break ;
      /* CASO DE INSTRUCTIVO */
      case 532:
      std::cout<<std::endl<<underline<<bold<<red<<"\t ========= INSTRUCCIONES ========= \n" <<reset<<bold<<white;
      if (archivo == "salir"){
        std::cout<<"\n\t*comando: salir\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n"<<white;
        std::cout<<"\n\t-(No tiene salida por pantalla)\n";
        std::cout<<"\n\tDescripcion: Termina la ejecucion de la aplicacion.\n";
      }	else if (archivo == "cargar_info_asign"){
        std::cout<<"\n\t*comando: cargar_info_asign\n";
        std::cout<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<"\n\t-(Semestre ya inicializado):Informaci�n de asignaturas y clases para el semestre IDsem ya ha sido cargada\n";
        std::cout<<"\n\t(Archivo no existe) El archivo listaClasesAsignacionAula-IDsem.csv no existe o es ilegible.\n";
        std::cout<<"\n\t(resultado exitoso) Informaci�n de asignaturas y clases para el semestre IDsem ha sido cargada exitosamente.\n";
        std::cout<<"\n\t Descripci�n:Carga en el sistema la informaci�n de asignaturas y clases programadas para un semestre\n"
        "\tespec�fico. El comando debe estructurar la informaci�n a partir del archivo de forma que sea f�cil recuperar\n"
        "\tlos datos m�nimos posteriormente. La informaci�n debe ser verificada para no incluir registros repetidos o incompletos";
      }
      else if (archivo == "cargar_info_estud"){
        std::cout<<"\n\t*comando: ccargar_info_estud\n";
        std::cout<<bold<<blue<<"\n\tPosibles salidas en pantalla: \n"<<white;
        std::cout<<"\n\t-(Semestre ya inicializado): Informaci�n de inscripciones de estudiantes para el semestre IDsem ya ha sido cargada.\n";
        std::cout<<"\n\t-(Semestre no coincide): Semestre IDsem no coincide con los datos de asignaturas y clases ya cargados.\n";
        std::cout<<"\n\t(Archivo no existe): El archivo listaClasesInscritasEstud-IDsem.csv no existe o es ilegible. \n";
        std::cout<<"\n\t(Resultado exitoso): Informaci�n de inscripciones de estudiantes para el semestre IDsem ha sido cargada exitosamente. \n";
        std::cout<<"\n\tdescripci�n: Carga en el sistema la informaci�n de inscripciones de estudiantes para un semestre espec�fico.\n"
        "\tEl semestre debe coincidir con aquel para el cual ya se carg� la informaci�n de asignaturas y clases progra-"
        "\tmadas, para evitar problemas de conexi�n de la informaci�n. El comando debe estructurar la informaci�n a"
        "\tpartir del archivo de forma que sea f�cil recuperar los datos m�nimos posteriormente. Adem�s, la informaci�n"
        "\tdebe ser verificada para no incluir registros repetidos o incompletos \n";
      }
      else if (archivo == "horario_estudID_estudt"){
        std::cout<<"\n\t*comando: horario_estudID_estud\n";
        std::cout<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<"\n\t-(Informaci�n incompleta): La informaci�n necesaria (programaci�n de asignaturas, inscripciones \n de estudiantes) no ha sido cargada completamente.\n";
        std::cout<<"\n\t(Estudiante no existe): El estudiante con identificaci�n ID_estud no est� registrado en el sistema..\n";
        std::cout<<"\n\t(Resultado exitoso) El horario semanal para el estudiante nombre_completo_estud es: \n";
        std::cout<<"\tdescripci�n:El comando permite conocer el horario de clases inscrito por un estudiante, discriminado por\n"
        "\tlos d�as de la semana. Para cada d�a, deben aparecer en orden cronol�gico las clases de las asignaturas,\n"
        "\tindicando el sal�n donde se llevar�n a cabo. El comando debe verificar que el estudiante tenga informaci�n\n"
        "\tcargada en el sistema para poder generar el horario de clases.\n";
      }
      else if(archivo == "cargar_info_prerreq"){
        std::cout<<"\n\t*comando: cargar_info_prerreq listaprerreq.csv \n";
        std::cout<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<"\n\t(Prerrequisitos ya inicializados) Información de prerrequisitos para las asignaturas ya ha sido cargada\n";
        std::cout<<"\n\t(Información incompleta) La información necesaria (programación de asignaturas) no ha sido cargada correctamente\n";
        std::cout<<"\n\t(Archivo no existe) El archivo listaPrerrequisitos.csv no existe o es ilegible. \n";
        std::cout<<"\n\t(Resultado exitoso) Información de asignaturas y sus prerrequisitos ha sido cargada exitosamente.\n";
        std::cout<<"\tdescripción: Registra en el sistema la información de los prerrequisitos para cada asignatura a partir \n"
        "\tdel archivo dado, en el cual se registran pares de identificadores de asignaturas (asignatura - prerrequi \n"
        "\tsito). La información de asignaturas y requisitos se encuentra en el documento oficial de la Dirección de\n"
        "\tCarrera de Ingeniería de Sistemas (http://ingenieria.javeriana.edu.co/documents/2838900/2841579/PreRequisitos_CarreraIngSistemas(Act-sep-2016_v0).pdf) \n";
      }
      else if(archivo == "proy_demanda"){
        std::cout<<"\n\t*comando: proy_demanda ID_asign\n";
        std::cout<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<"\n\t(Información incompleta) La información necesaria (programación de asignaturas, prerrequisitos, inscripciones de estudiantes) no ha sido cargada completamente. \n";
        std::cout<<"\n\t(Asignatura no existe) La asignatura con identificador ID_asig no está registrada en el sistema.\n";
        std::cout<<"\n\t(Resultado exitoso) La demanda proyectada para la asignatura nombre_asignatura es: \n";
        std::cout<<"\n\t(Resultado adverso) No existe suficiente información para calcular la demanda proyectada para la asignatura nombre_asignatura .\n";
        std::cout<<"\tdescripción: El comando permite calcular la demanda proyectada para la asignatura indicada, a partir de la información actual de estudiantes inscritos en las asignaturas prerrequisito. Para esto, se requiere calcular \n"
        "\tel árbol de prerrequisitos de la asignatura dada, que almacene asignaturas e inscritos en cada nodo, y que   conecte los nodos de acuerdo a los prerrequisitos ya registrados con el comando cargar_info_prerreq.  \n"
        "\tLa demanda proyectada para cada semestre futuro dependerá de la cantidad de inscritos actuales en cada una de las asignaturas prerrequisito, teniendo en cuenta la distancia sobre el árbol (en semestres) entre la   asignatura actual y cada prerrequisito.\n";
      }
      else if(archivo == "proy_semestres"){
        std::cout<<"\n\t*comando: proy_semestres ID_estud \n";
        std::cout<<"\n\tPosibles salidas en pantalla: \n";
        std::cout<<"\n\t(Información incompleta) La información necesaria (programación de asignaturas, prerrequisitos, inscripciones de estudiantes) no ha sido cargada completamente.\n";
        std::cout<<"\n\t(Estudiante no existe) El estudiante con identificación ID_estud no está registrado en el   sistema.\n";
        std::cout<<"\n\t(Resultado exitoso) Las asignaturas proyectadas para el estudiante nombre_estudiante son:\n";
        std::cout<<"\n\t(Resultado adverso) No existe suficiente información para generar la proyección de asignaturas  para el estudiante nombre_estudiante.\n";
        std::cout<<"\tdescripción: El comando permite generar una proyección de las asignaturas a cursas en semestres futuros\n"
        "\tpor el estudiante dado. Para esto, se utilizan las asignaturas actualmente inscritas por el estudiante, y\n"
        "\tpara cada una de ellas se genera un árbol de posibles asignaturas futuras, de acuerdo a la información de \n"
        "\tprerrequisitos ya registrada con el comando cargar_info_prerreq. Luego, se combina la información de"
        "\testos árboles para informar las posibles asignaturas a cursar por el estudiante en cada semestre futuro.";
      }
      else{
        std::cout<<"\n\t*comando: horario_estud ID_estud\n";
        std::cout<<"\n\t*comando: cargar_info_estud\n";
        std::cout<<"\n\t*comando: cargar_info_asign\n";
        std::cout<<"\n\t*comando: cargar_info_prerreq\n";
        std::cout<<"\n\t*comando: proy_demanda\n";
        std::cout<<"\n\t*comando: proy_semestres\n";
        std::cout<<"\n\t*comando: salir\n";
      }
      break ;
      default :
      std::cout<<std::endl<<"Informacion : "<<comando<<" No existe , por favor tipee ayuda para obtener informacion \n" ;
      std::cout<<std::endl<<"VALOR NUMERICO : "<<str2int(comando);
      break ;
    }
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
