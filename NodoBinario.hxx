#ifndef NODO_BINARIO_HXX
#define NODO_BINARIO_HXX

#include "NodoBinario.h"
/* ================================================================================================================*/
template< class T >
NodoBinario<T>::NodoBinario(){
  this->hijoIzq = nullptr ;
  this->hijoDer = nullptr;
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>::NodoBinario(T& val){
  this->dato = val ;
  this->hijoIzq = nullptr ;
  this->hijoDer = nullptr;
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>::NodoBinario(T& val , NodoBinario<T> *izqq , NodoBinario<T> *der){
  this->dato = val ;
  this->hijoIzq = izqq;
  this->hijoDer = der ;
}
/* ================================================================================================================*/
template< class T >
T& NodoBinario<T>::obtenerDato(){
  return this->dato ;
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::fijarDato(T& val){
  this->dato = val;
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::fiJarHijoDer(NodoBinario<T> *der){
  this->hijoDer = der ;
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq){
  this->hijoIzq = izq ;
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq(){
  return this->hijoIzq ;
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer(){
  return this->hijoDer ;
}
/* ================================================================================================================*/
template< class T >
bool NodoBinario<T>::esNull(){
  if(this->dato == nullptr){
    return true ;
  }else{
    return false ;
  }
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::preOrden() {
  std::cout<<this->obtenerDato()<<std::endl ;

  if(this->obtenerHijoIzq() != nullptr ){
    std::cout<<"a izquierda ";
    this->obtenerHijoIzq()->preOrden() ;

  }

  if(this->obtenerHijoDer() != nullptr){
    std::cout<<"a derecha ";
    this->obtenerHijoDer()->preOrden() ;

  }
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::posOrden(){
  if(this->obtenerHijoIzq() != nullptr){
    this->obtenerHijoIzq()->posOrden() ;
  }
  if(this->obtenerHijoDer() != nullptr){
    this->obtenerHijoDer()->posOrden() ;
  }
  std::cout<<this->obtenerDato()<<std::endl ;
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::inOrden(){
  if(this->obtenerHijoIzq() != nullptr){
    this->obtenerHijoIzq()->inOrden() ;
  }
  std::cout<<this->obtenerDato()<<std::endl ;
  if(this->obtenerHijoDer() != nullptr){
    this->obtenerHijoDer()->inOrden() ;
  }
}
/* ================================================================================================================*/
template< class T >
int NodoBinario<T>::altura(){

  if(this->obtenerHijoDer() == nullptr && this->obtenerHijoIzq() == nullptr){
    return 0 ;
  }
  int temp1 = 0 ;
  int temp2 = 0 ;
  if(this->obtenerHijoIzq() != nullptr){
    temp1 = this->obtenerHijoIzq()->altura() ;
  }
  if(this->obtenerHijoDer() != nullptr){
    temp2 = this->obtenerHijoDer()->altura() ;
  }
  if(temp1 > temp2){
    return ++temp1 ;
  }else{
    return ++temp2 ;
  }
}
/* ================================================================================================================*/
template< class T >
int NodoBinario<T>::tamano(int aux){
  if(this->obtenerHijoIzq() != nullptr ){
    aux = this->obtenerHijoIzq()->tamano(aux) ;
  }
  if(this->obtenerHijoDer() != nullptr){
    aux = this->obtenerHijoDer()->tamano(aux) ;
  }
  return aux+1 ;
}
/* ================================================================================================================*/
template< class T >
bool NodoBinario<T>::insertar(T& val){
  if(val < this->obtenerDato()){
    if(this->obtenerHijoIzq() != nullptr){
      return this->obtenerHijoIzq()->insertar(val);
    }else{
      this->fijarHijoIzq(new NodoBinario<T>(val)) ;
      return true ;
    }
  }else{
    if(val > this->obtenerDato()){
      if(this->obtenerHijoDer() != nullptr){
        return this->obtenerHijoDer()->insertar(val);
      }else{
        this->fiJarHijoDer(new NodoBinario<T>(val));
        return true ;
      }
    }
  }
  return false ;
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>* NodoBinario<T>::eliminar(T& val){
  bool ya = false ;
  NodoBinario<T>* pp = nullptr ;
  if(this->obtenerHijoIzq() != nullptr){
    if(this->obtenerHijoIzq()->obtenerDato() == val){
      if(this->obtenerHijoIzq()->obtenerHijoIzq() == nullptr && this->obtenerHijoIzq()->obtenerHijoDer() == nullptr){
        NodoBinario<T>* aux = this->obtenerHijoIzq();
        this->fijarHijoIzq(nullptr);
        delete aux ;
        /* AQUI BEBE */
        return this ;
      }else{
        if((this->obtenerHijoIzq()->obtenerHijoIzq() != nullptr && this->obtenerHijoIzq()->obtenerHijoDer() == nullptr) || (this->obtenerHijoIzq()->obtenerHijoIzq() == nullptr && this->obtenerHijoIzq()->obtenerHijoDer() != nullptr)){
          if(this->obtenerHijoIzq()->obtenerHijoIzq() == nullptr){
            NodoBinario<T>* aux = this->obtenerHijoIzq();
            NodoBinario<T>* aux2 = this->obtenerHijoIzq()->obtenerHijoDer();
            this->fijarHijoIzq(aux2);
            aux->fiJarHijoDer(nullptr);
            delete aux ;
            return aux2;
          }else{
            NodoBinario<T>* aux = this->obtenerHijoIzq();
            NodoBinario<T>* aux2 = this->obtenerHijoIzq()->obtenerHijoIzq();
            this->fijarHijoIzq(aux2);
            aux->fijarHijoIzq(nullptr);
            delete aux ;
            return aux2 ;
          }
        }else{
          /*SUB HIJO MAIOR*/
          NodoBinario<T>* aux = this->obtenerHijoIzq();
          NodoBinario<T>* aux2 ;
          NodoBinario<T>* aux3 = this->obtenerHijoIzq()->obtenerHijoDer() ;
          NodoBinario<T>* aux4 = this->obtenerHijoIzq()->obtenerHijoIzq() ;

          if(this->obtenerHijoIzq()->obtenerHijoIzq()->obtenerHijoDer() == nullptr){
            this->fijarHijoIzq(aux->obtenerHijoIzq());
          }else{
            aux2 = this->obtenerHijoIzq()->obtenerHijoIzq()->obtenerNodomayor();
            this->fijarHijoIzq(aux2->obtenerHijoDer()) ;

            aux2->fiJarHijoDer(nullptr);
            this->obtenerHijoIzq()->fijarHijoIzq(aux4);
          }
          this->obtenerHijoIzq()->fiJarHijoDer(aux3);
          delete aux ;
          return this->obtenerHijoIzq();
        }
      }
    }else{
      pp = this->obtenerHijoIzq()->eliminar(val);
      if( pp != nullptr)
      ya = true ;
      else
      ya = false ;
    }
  }
  if (!ya){
    if(this->obtenerHijoDer() != nullptr){
      if(this->obtenerHijoDer()->obtenerDato() == val){
        if(this->obtenerHijoDer()->obtenerHijoIzq() == nullptr && this->obtenerHijoDer()->obtenerHijoDer() == nullptr){
          NodoBinario<T>* aux = this->obtenerHijoDer();
          this->fiJarHijoDer(nullptr);
          delete aux ;
          return this ;
        }else{
          if((this->obtenerHijoDer()->obtenerHijoIzq() != nullptr && this->obtenerHijoDer()->obtenerHijoDer() == nullptr) || (this->obtenerHijoDer()->obtenerHijoIzq() == nullptr && this->obtenerHijoDer()->obtenerHijoDer() != nullptr)){
            if(this->obtenerHijoDer()->obtenerHijoIzq() == nullptr){
              NodoBinario<T>* aux = this->obtenerHijoDer();
              NodoBinario<T>* aux2 = this->obtenerHijoDer()->obtenerHijoDer();
              this->fiJarHijoDer(aux2);
              aux->fiJarHijoDer(nullptr);
              delete aux ;
              return aux2 ;
            }else{
              NodoBinario<T>* aux = this->obtenerHijoDer();
              NodoBinario<T>* aux2 = this->obtenerHijoDer()->obtenerHijoIzq();
              this->fiJarHijoDer(aux2);
              aux->fijarHijoIzq(nullptr);
              delete aux ;
              return aux2 ;
            }
          }else{
            /*SUB HIJO MAIOR*/
            NodoBinario<T>* aux = this->obtenerHijoDer();
            NodoBinario<T>* aux2 ;
            NodoBinario<T>* aux3 = this->obtenerHijoDer()->obtenerHijoDer() ;
            NodoBinario<T>* aux4 = this->obtenerHijoDer()->obtenerHijoIzq() ;

            if(this->obtenerHijoDer()->obtenerHijoIzq()->obtenerHijoDer() == nullptr){
              this->fiJarHijoDer(aux->obtenerHijoIzq());
            }else{
              aux2 = this->obtenerHijoDer()->obtenerHijoIzq()->obtenerNodomayor();
              this->fiJarHijoDer(aux2->obtenerHijoDer()) ;
              aux2->fiJarHijoDer(nullptr);
              this->obtenerHijoDer()->fijarHijoIzq(aux4);
            }
            this->obtenerHijoDer()->fiJarHijoDer(aux3);
            delete aux ;
            return this->obtenerHijoDer() ;
          }
        }
      }else{
        this->obtenerHijoDer()->eliminar(val);
      }
    }
  }


}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerNodomayor(){
  if(this->obtenerHijoDer()->obtenerHijoDer() == nullptr){
    return this ;
  }else{
    return this->obtenerHijoDer()->obtenerNodomayor();
  }
}
/* ================================================================================================================*/
template< class T >
T& NodoBinario<T>::minimo(){
  if(this->obtenerHijoIzq() == nullptr){
    return this->obtenerDato();
  }else{
    return this->obtenerHijoIzq()->minimo();
  }
}
/* ================================================================================================================*/
template< class T >
T& NodoBinario<T>::maximo(){
  if(this->obtenerHijoDer() == nullptr){
    return this->obtenerDato();
  }else{
    return this->obtenerHijoDer()->maximo();
  }
}
/* ================================================================================================================*/
template< class T >
bool NodoBinario<T>::verificarAVL(){
  int altiz = 0 ;
  int altder = 0 ;
  int res =0 ;
  altiz = this->obtenerHijoIzq()->altura(0) -1 ;
  altder = this->obtenerHijoDer()->altura(0) -1 ;
  res = altiz - altder ;
  if( res < 0 ){
    res *= -1 ;
  }
  if(res == 0 ){
    return true ;
  }
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>* NodoBinario<T>::rotIzq(){

  NodoBinario<T>* n_padre ;
  n_padre= this->obtenerHijoDer();
  this->fiJarHijoDer(n_padre->obtenerHijoIzq());
  n_padre->fijarHijoIzq(nullptr);
  n_padre->fijarHijoIzq(this);

  return n_padre;
}
/* ================================================================================================================*/
template< class T >
NodoBinario<T>* NodoBinario<T>::rotDer(){

  NodoBinario<T>* n_padre;
  n_padre= this->obtenerHijoIzq();
  this->fijarHijoIzq(n_padre->obtenerHijoDer());
  n_padre->fiJarHijoDer(nullptr);
  n_padre->fiJarHijoDer(this);


  return n_padre;
}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::rotizqder(NodoBinario<T>*& root){

  if(this->obtenerHijoIzq()->obtenerHijoDer() != nullptr){
    NodoBinario<T>* n_padre = this->obtenerHijoIzq()->rotIzq();

    root->cambiarPadre(root ,n_padre , this->obtenerHijoIzq());


    NodoBinario<T>* aux = n_padre ;

    this->fijarHijoIzq(aux);
  }

  NodoBinario<T>* n_padre2 =this->rotDer();

  root->cambiarPadre(root ,n_padre2 , this);

}
/* ================================================================================================================*/
template< class T >
void NodoBinario<T>::rotderizq(NodoBinario<T>*& root){

  if(this->obtenerHijoDer()->obtenerHijoIzq() != nullptr){
    NodoBinario<T>* n_padre = this->obtenerHijoDer()->rotDer() ;

    root->cambiarPadre(root ,n_padre , this->obtenerHijoDer());



    NodoBinario<T>* aux = n_padre;

    this->fiJarHijoDer( aux );
  }

  NodoBinario<T>* n_padre2 =  this->rotIzq() ;

  root->cambiarPadre(root ,n_padre2 , this);
}
/* ================================================================================================================*/
template< class T >
bool NodoBinario<T>::balancear(T& val , NodoBinario<T>*& root) {
  int altder = 0 ;
  int altizq = 0 ;
  int res = 0 ;
  bool bandera = false ;
  if(this->obtenerHijoDer() != nullptr ){
    if(this->obtenerHijoDer()->obtenerDato() == val){
      bandera = true ;
    }
  }
  if (this->obtenerHijoIzq() != nullptr){
    if(this->obtenerHijoIzq()->obtenerDato() == val){
      bandera = true ;
    }
  }
  if(bandera){

    if(this->obtenerHijoDer() != nullptr){
      altder = this->obtenerHijoDer()->altura() ;

    }else{
      altder = -1 ;
    }
    if(this->obtenerHijoIzq() != nullptr){
      altizq = this->obtenerHijoIzq()->altura();
    }else{
      altizq = -1 ;
    }
    res = altizq - altder ;
    if(res == 0 ){
      return true ;
    }
    if(res == 1 ){
      NodoBinario<T>* n_padre = this->rotDer();
      root->cambiarPadre(root ,n_padre , this);

      return true ;
    }
    if(res == -1){
      NodoBinario<T>* n_padre = this->rotIzq();
      root->cambiarPadre(root ,n_padre , this);
      return true ;
    }
    if(res == -2){
      this->rotderizq(root);
      return true ;
    }
    if(res == 2){
      this->rotizqder(root);
      return true ;
    }
    return false ;
  }else{
    bool b = false ;
    if(this->obtenerDato() < val && !b){
      if(this->obtenerHijoDer() != nullptr)
      this->obtenerHijoDer()->balancear(val , root) ;
      b = true ;
    }
    if(this->obtenerDato() > val && !b){
      if(this->obtenerHijoIzq() != nullptr)
      this->obtenerHijoIzq()->balancear(val , root) ;
      b = true ;
    }
    if(this->obtenerDato() == val)
    return false ;

    if(this->obtenerHijoDer() != nullptr){
      altder = this->obtenerHijoDer()->altura();

    }else{
      altder = -1 ;
    }
    if(this->obtenerHijoIzq() != nullptr){
      altizq = this->obtenerHijoIzq()->altura()   ;

    }else{
      altizq = -1 ;
    }
    res = altizq - altder ;

    if(res == 0 ){
      return true ;
    }

    if(res == -2){
      this->rotderizq(root);
      return true ;
    }
    if(res == 2){
      this->rotizqder(root);
      return true ;
    }
    return false ;
  }
}
/* ================================================================================================================*/
template< class T >
bool NodoBinario<T>::cambiarPadre(NodoBinario<T>*& root , NodoBinario<T>* n_padre , NodoBinario<T>* padre){
  if(root->obtenerDato() == padre->obtenerDato()){
    root = n_padre ;
    return true ;
  }else{
    if(this->obtenerHijoIzq() != nullptr){
      if(this->obtenerHijoIzq()->obtenerDato() == padre->obtenerDato()){
        this->fijarHijoIzq( n_padre);
        return true ;
      }
    }
    if(this->obtenerHijoDer() != nullptr){
      if(this->obtenerHijoDer()->obtenerDato() == padre->obtenerDato()){
        this->fiJarHijoDer( n_padre);
        return true ;
      }
    }
    if(this->obtenerHijoIzq() != nullptr){
      if(padre->obtenerDato() < this->obtenerDato()){
        return this->obtenerHijoIzq()->cambiarPadre(root , n_padre , padre );
      }
    }
    if(this->obtenerHijoDer() != nullptr){
      if(padre->obtenerDato() > this->obtenerDato() ){
        return this->obtenerHijoDer()->cambiarPadre(root , n_padre , padre   );
      }
    }
  }
  return false ;
}
/* ================================================================================================================*/
template< class T >
bool NodoBinario<T>::balancear2(T& val , NodoBinario<T>*& root) {
  int altder = 0 ;
  int altizq = 0 ;
  int res = 0 ;
  bool bandera = false ;
  if(this->obtenerDato() == val ){

    bandera = true ;

  }
  if(bandera){

    if(this->obtenerHijoDer() != nullptr){
      altder = this->obtenerHijoDer()->altura() ;
    }else{
      altder = -1 ;
    }
    if(this->obtenerHijoIzq() != nullptr){
      altizq = this->obtenerHijoIzq()->altura();
    }else{
      altizq = -1 ;
    }
    res = altizq - altder ;
    if(res == 0 ){
      return true ;
    }
    if(res == 1 ){
      NodoBinario<T>* n_padre = this->rotDer();
      root->cambiarPadre(root ,n_padre , this);

      return true ;
    }
    if(res == -1){
      NodoBinario<T>* n_padre = this->rotIzq();
      root->cambiarPadre(root ,n_padre , this);
      return true ;
    }
    if(res == -2){
      this->rotderizq(root);
      return true ;
    }
    if(res == 2){
      this->rotizqder(root);
      return true ;
    }
    return false ;
  }else{
    bool b = false ;
    if(this->obtenerDato() < val && !b){
      if(this->obtenerHijoDer() != nullptr)
      this->obtenerHijoDer()->balancear2(val , root) ;
      b = true ;
    }
    if(this->obtenerDato() > val && !b){
      if(this->obtenerHijoIzq() != nullptr)
      this->obtenerHijoIzq()->balancear2(val , root) ;
      b = true ;
    }
    if(this->obtenerDato() == val)
    return false ;

    if(this->obtenerHijoDer() != nullptr){
      altder = this->obtenerHijoDer()->altura();

    }else{
      altder = -1 ;
    }
    if(this->obtenerHijoIzq() != nullptr){
      altizq = this->obtenerHijoIzq()->altura()   ;

    }else{
      altizq = -1 ;
    }
    res = altizq - altder ;

    if(res == 0 ){
      return true ;
    }

    if(res == -2){
      this->rotderizq(root);
      return true ;
    }
    if(res == 2){
      this->rotizqder(root);
      return true ;
    }
    return false ;
  }
}
template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerPadre(NodoBinario* nodo) {
  if(this->hijoIzq == nodo || this->hijoDer == nodo){
    return this ;
  }else{
    if(nodo->obtenerDato() > this->obtenerDato() && this->hijoDer != nullptr){
      return this->hijoDer->obtenerPadre(nodo);
    }else if(nodo->obtenerDato() < this->obtenerDato() && this->hijoIzq != nullptr){
      return this->hijoIzq->obtenerPadre(nodo);
    }else{
      return nullptr ;
    }
  }
}
#endif
