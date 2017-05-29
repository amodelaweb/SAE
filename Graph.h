#ifndef _GRAPH_H
#define _GRAPH_H

#include "Vertex.h"
#include <set>
#include <iostream>
#include <queue>
#include <stack>

//=========================================================================
template < class T , class E >
struct VertComparator
{
    bool operator()(const Vertex<T , E>* a, const Vertex<T , E>* b ) const
    {
        return a->GetData() < b->GetData();
    }
};
//=========================================================================
template < class T  , class E>
class Graph
{
protected:
    std::set<Vertex<T , E >* , VertComparator<T , E >> vertexs ;
    bool type ;
public:
    Graph();
    Graph(bool type);
    ~Graph() = default ;
    void addVertex(T data) ;
    void eraseEdge(Vertex<T , E > *V1, Vertex<T , E > *v2);
    Vertex<T , E>* findVertex(T data);
    void addEdge(T data, T data2, unsigned long cost , E datai);
    void eraseVertex(T data );
    void flatTravel();
    void printAll();
    void resetVisited();
    void DepthfirstSearch(T begin);
    void depthFirstSearch(T begin);
    void Breadthfirstsearch(T begin);
    void breadthfirstsearch(T begin);
    bool isPath(T begin);
    void EulerPath(Vertex<T , E>* V);
    unsigned int getinGrade(Vertex<T , E>* v );
    void rmEdge(Vertex<T , E>* v1 , Vertex<T , E>* v2);
    void reAddEdge(Vertex<T , E>* v1 , Vertex<T , E>* v2);
    bool validNext(Vertex<T , E>* v1 , Vertex<T , E>* v2);
    unsigned int numberOfConectedComponents(Vertex<T , E>* v1);
    std::set<Vertex<T , E>* , VertComparator<T,E> > GetConectedComponents(Vertex<T , E>* v1);
    unsigned int DFCount(Vertex<T , E>* v );
    void resetValue();
    void dijkstra(T begin, T end);
    void resetEdgeVisited();
};
#include "Graph.hxx"
//=========================================================================
#endif
