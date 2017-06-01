#ifndef VERTEX_GRAPH_HXX
#define VERTEX_GRAPH_HXX

#include "Vertex.h"

//=========================================================================
template < class T  , class E >
Vertex<T , E >::Vertex(){

}
//=========================================================================
template < class T  , class E >
Vertex<T , E >::Vertex(T& data) : data(data) , visited(false) , value(9999){

}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::addAdjacents(unsigned long cost ,  Vertex<T , E >* vert , E data){
  if(!this->ExistEdge(vert , data)){
    Edge<E>* aux  = new Edge<E>(cost,false , data);
    this->adjacents.insert(std::pair<Vertex<T , E >*, Edge<E>* >(vert,aux) );
  }
}
//=========================================================================
template < class T  , class E >
bool operator == (const Vertex<T , E > &v1  , const Vertex<T , E > &v2){
  return v1.data == v2.data ;
}
//=========================================================================
template < class T  , class E >
bool operator != (const Vertex<T , E > &v1  , const Vertex<T , E > &v2){
  return v1.data != v2.data ;
}
//=========================================================================
template < class T  , class E >
bool operator < (const Vertex<T , E > &v1  , const Vertex<T , E > &v2){
  return v1.data < v2.data ;
}
//=========================================================================
template < class T  , class E >
bool operator > (const Vertex<T , E > &v1  , const Vertex<T , E > &v2){
  return v1.data > v2.data ;
}
//=========================================================================
template < class T  , class E >
bool operator >= (const Vertex<T , E > &v1  , const Vertex<T , E >&v2){
  return v1.data >= v2.data ;
}
//=========================================================================
template < class T  , class E >
bool operator <= (const Vertex<T , E > &v1  , const Vertex<T , E > &v2){
  return v1.data <= v2.data ;
}
//=========================================================================
template < class T  , class E >
std::ostream& operator << (std::ostream &o, const Vertex<T , E > &v1){
  return o << v1.data ;
}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::eraseEdge(Vertex<T , E >*vert , E data ){

    bool band = false ;
    std::pair <typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator, typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator> ret;
    ret = this->adjacents.equal_range(vert);
    for (typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator it=ret.first; it!=ret.second && !band; ++it){
      if((it->second)->data == data ){
        this->adjacents.erase(it);
      }
    }

}
//=========================================================================
template < class T  , class E >
T Vertex<T , E >::GetData() const{
  return this->data ;
}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::PrintEdges(){
  std::cout<<std::endl ;
  typename std::multimap<Vertex<T , E >* , Edge<E>* >::iterator it  ;
  for(it = this->adjacents.begin() ; it != this->adjacents.end() ; it++){
    std::cout<<std::endl<<"( "<<this->data<<" , "<<(it->first)->data<<" , "<<(it->second)->weigth<<" , "<<(it->second)->data<< " ) " ;
  }
  std::cout<<std::endl ;
}
//=========================================================================
template < class T  , class E >
bool Vertex<T , E >::getVisited(){
  return this->visited ;
}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::setVisited(bool v){
  this->visited = v ;
}
//=========================================================================
template < class T  , class E >
std::multimap<Vertex<T , E >*, Edge<E>* > Vertex<T , E >::GetAdjacents(){
  return this->adjacents;
}
//=========================================================================
template < class T  , class E >
unsigned int Vertex<T , E >::getGrade(){
  return this->adjacents.size();
}
//=========================================================================
template < class T  , class E >
bool Vertex<T , E >::exist(Vertex<T , E >* v ){
  typename std::multimap<Vertex<T , E >* ,Edge<E>*>::iterator it  = this->adjacents.find(v);
  if(it != this->adjacents.end()){
    return true ;
  }
  return false ;
}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::resetVisited(){
  typename std::multimap<Vertex<T , E >* ,Edge<E>*>::iterator it ;
  for(it = this->adjacents.begin() ; it != this->adjacents.end() ; it++){
    (it->second)->visited = false ;
  }
}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::rmEdge(Vertex<T , E >* v, E data){
  bool band = false ;
  std::pair <typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator, typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator> ret;
  ret = this->adjacents.equal_range(v);
  for (typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator it=ret.first; it!=ret.second ; it++){
    if( !(it->second)->visited ){
      (it->second)->visited = true ;
      band = true ;
    }
  }


}
//=========================================================================
template < class T  , class E >
void Vertex<T , E >::reAddEdge(Vertex<T , E >* v , E data){
  bool band = false ;
  std::pair <typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator, typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator> ret;
  ret = this->adjacents.equal_range(v);
  for (typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator it=ret.first; it!=ret.second ; it++){
    if( (it->second)->visited  ){
      (it->second)->visited = false ;
      band = true ;
    }
  }
}
//=========================================================================
template < class T  , class E >
bool Vertex<T , E >::ExistEdge(Vertex<T , E >* v){
  bool band = false ;
  std::pair <typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator, typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator> ret;
  ret = this->adjacents.equal_range(v);
  for (typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator it=ret.first; it!=ret.second; ++it){
    if( (it->second)->visited == false && !band ){
      band = true ;
    }
  }
  return !band ;
}
//=========================================================================
template < class T  , class E >
unsigned int Vertex<T , E >::NumberOfNonVisitedVertexs(){
  unsigned int cont = 0 ;
  typename std::multimap<Vertex<T , E >* ,Edge<E>*>::iterator it ;
  for(it = this->adjacents.begin() ; it != this->adjacents.end() ; it++){
    if(!(it->second)->visited ){
      cont++;
    }
  }
  return cont ;
}
//=========================================================================
template < class T  , class E >
bool Vertex<T , E >::HasAdjacent(Vertex<T , E >* v){
  typename std::multimap<Vertex<T , E >* , Edge<E>* >::iterator it   = this->adjacents.find(v);
  if(it != this->adjacents.end()){
    return true;
  }else{
    return false ;
  }
}
//=========================================================================
template<class T , class E>
int Vertex<T , E >::getValue(){
  return this->value;
}
//=========================================================================
template<class T , class E>
void Vertex<T , E >::setValue(int value){
  this->value= value;
}
//=========================================================================
template<class T , class E>
int Vertex<T , E >::getDist(Vertex<T , E > *t){
  return this->ady.find(t)->second;
}
//=========================================================================
template<class T , class E>
bool Vertex<T , E >::allAdy(){
  bool x=true;
  typename std::multimap<Vertex<T , E > *, int>::iterator it=this->ady.begin();
  for(;it!=this->ady.end();it++){
    if(it->first->getVisited()==false){
      x=false;
    }
  }
  return x;
}
//=========================================================================
template<class T , class E>
bool Vertex<T , E >::ExistEdge(Vertex<T , E>* v , E val){
  bool band = false ;
  std::pair <typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator, typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator> ret;
  ret = this->adjacents.equal_range(v);
  for (typename std::multimap<Vertex<T , E >* , Edge<E>*>::iterator it=ret.first; it!=ret.second && !band; ++it){
    if( (it->second)->data == val && !band && !(it->second)->visited){
      band = true ;
    }
  }
  return band ;
}
//=========================================================================
template<class T , class E>
void Vertex<T , E >::getWaytoTarget(Vertex<T,E>* v , std::stack<E> &media){
  bool band = false ;
  std::pair <typename std::multimap<Vertex<T,E>* , Edge<E>*>::iterator , typename std::multimap<Vertex<T,E>* , Edge<E>*>::iterator> ret;
  ret = this->adjacents.equal_range(v);
  for (typename std::multimap<Vertex<T,E>* , Edge<E>*>::iterator it=ret.first; it!=ret.second && !band; ++it){
    if( !band ){
      media.push((it->second)->data);
    }
  }
}
//=========================================================================
#endif
