#include<iostream>
#include <list>
using namespace std;


/* Conceitos Importantes */
/* 
Um grafo conexo G é Euleriano sse(se A então B e se B então A)
cada vértice de G possui grau par. Ou seja, se o grafo é euleriano 
todos os vértices tem grau par, e além disto,  se todos os vértices 
do grafo tem grau par então o grafo é Euleriano.
Um percurso é dito pré-euleriano quando utiliza cada aresta ou 
arco do grafo ao menos uma vez.
Um percurso é dito euleriano quando utiliza cada aresta ou arco do grafo 
uma única vez.
Denomina-se ciclo o percurso onde o último vértice atingido corresponde 
ao vértice de partida.
Denomina-se cadeia o percurso onde os vértices de inicial e e final são distintos.
*/


class Graph
{
    int Vertices;
    list<int> *adj;
public:
    Graph(int Vertices)   {this->Vertices = Vertices; adj = new list<int>[Vertices]; }
    ~Graph() { delete [] adj; }
  
    void addEdge(int v, int w);
  
    int isEulerian();
  
    bool isConnected();

};
