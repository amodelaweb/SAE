#ifndef VERTEX_GRAPH_H
#define VERTEX_GRAPH_H

#include "Graph.h"
#include <map>
#include <stack>
#include <iostream>


template < class T , class E >
class Graph ;
//=========================================================================
template <class E >
struct Edge{
  unsigned long weigth ;
  bool visited ;
  E data ;
  Edge(unsigned long weigth , bool visited , E data) : weigth(weigth) , visited(visited) , data(data){}
  Edge(){}
};
//=========================================================================
template < class T , class E >
class Vertex
{
  friend class Graph<T , E>;
protected:
  T data ;
  std::multimap<Vertex<T , E>*, Edge<E>* > adjacents ;
  bool visited ;
  int value;
public:

  Vertex();
  Vertex(T& data );
  ~Vertex() = default ;
  void addAdjacents(unsigned long cost,  Vertex<T , E>* vert , E data);
  void eraseEdge(Vertex<T , E>*vert , E data);
  T GetData() const;
  void PrintEdges();
  bool getVisited();
  void setVisited(bool v);
  unsigned int getGrade();
  bool exist(Vertex<T , E>* v );
  void resetVisited();
  void rmEdge(Vertex<T , E>* v , E data);
  void reAddEdge(Vertex<T , E>* v , E data);
  bool ExistEdge(Vertex<T , E>* v);
  bool HasAdjacent(Vertex<T , E>* v);
  unsigned int NumberOfNonVisitedVertexs();
  int getValue();
  void setValue(int value);
  int getDist(Vertex<T , E> *t);
  bool allAdy();
  std::multimap<Vertex<T , E>*, Edge<E>* > GetAdjacents();
  bool ExistEdge(Vertex<T , E>* v , E val);
  void getWaytoTarget(Vertex<T,E>* v , std::stack<E> &media);
//=========================================================================
  template<T , E> friend bool operator == (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend bool operator != (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend bool operator < (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend bool operator > (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend bool operator >= (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend bool operator <= (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend bool operator != (const Vertex<T , E> &v1, const Vertex<T , E> &v2);
  template<T , E> friend std::ostream& operator << (std::ostream &o, const Vertex<T , E> &v1);
};
//=========================================================================
#include "Vertex.hxx"

#endif
