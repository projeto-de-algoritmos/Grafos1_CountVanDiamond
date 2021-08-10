#include <iostream>
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
	Graph(int Vertices)
	{
		this->Vertices = Vertices;
		adj = new list<int>[Vertices];
	}
	~Graph() { delete[] adj; }

	void addEdge(int v, int w);

	void DFS(int v, bool visited[]);

	int isEulerian();

	bool isConnected();

	void print(int v);
};

/* void Graph::print(int v)
{
    for (int i = 0; i < Vertices; i++)
    {
        for (auto it = adj[i].cbegin(); it != adj[i].cend(); ++it)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }
} */

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int v, bool visited[])
{
	visited[v] = true;

	//Pecorre todos os vertices adjacentes do nó
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited);
}

bool Graph::isConnected()
{

	bool visited[Vertices];
	int i;
	for (i = 0; i < Vertices; i++)
		visited[i] = false;

	//Encontrando um vertice com grau diferente de zero
	for (i = 0; i < Vertices; i++)
		if (adj[i].size() != 0)
			break;

	//Se não houver arestas no grafo, retorna true
	if (i == Vertices)
		return true;

	DFS(i, visited);

	//Verificando todos os graus diferentes de zeroque foram visitados
	for (i = 0; i < Vertices; i++)
		if (visited[i] == false && adj[i].size() > 0)
			return false;

	return true;
}

int Graph::isEulerian()
{
	if (isConnected() == false)
		return 0;

	int odd = 0;
	for (int i = 0; i < Vertices; i++)
		if (adj[i].size() & 1)
			odd++;

	// Não é euleriano
	if (odd > 2)
		return 0;

	// Se odd = 2, então é semi-euleriano
	// Se odd = 0, então é euleriano
	return (odd) ? 1 : 2;
}

int main()
{
	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 5);
	g.addEdge(4, 7);
	g.addEdge(5, 8);
	g.addEdge(5, 9);
	g.addEdge(9, 6);
	g.addEdge(3, 6);

	const char *statement = R"(
                                            O Caso Count Van Diamond


            O cenário abaixo é a residência do bilionário Count Van Diamond, que acaba de ser assassinado. 
            Sherlock Gomes, um detetive conhecido internacionalmente por solucionar casos usando seu amplo
            conhecimento em Teoria dos Grafos, foi chamado para investigar o caso. O mordomo alega ter visto
            o jardineiro usar a mesma porta para entrar e sair da Sala da Piscina, onde ocorreu o crime. O
            jardineiro, contudo, afirma que não poderia ser a pessoa vista pelo mordomo, pois havia entrado
            na casa, passado por todas as portas uma única vez e, em seguida, deixado a casa. Sherlock Gomes 
			avaliou a planta da propriedade e em poucos minutos declarou solucionado o caso.


                                            Quem matou o bilionário?
    )";
	cout << statement << endl;
	cout << "1 - Count Van Diamond\n2 - Mordomo\n3 - Jardineiro\n4 - Sherlock Gomes\n"
		 << endl;

	int assassin;

	cin >> assassin;

	int res = g.isEulerian();
	switch (assassin)
	{
	case 1:
		cout << "Felizmente Sherlock Gomes descartou a possibilidade do Count Van Diamond ser o assassino." << endl;
		break;
	case 2:
		cout << "Felizmente Sherlock Gomes descartou a possibilidade do Mordomo ser o assassino." << endl;
		break;
	case 3:
		if (res == 0)
		{

			cout << R"(
								Tadaaaã...Aqui está o culpado.


			Usando o Teorema de Euler, Sherlock Gomes chegou a conclusão de que o grafo formado pelos comodos da casa 
			não era possivel ter um ciclo euleriano.Portanto, não é possível passar por todas as portas da residência 
			uma única vez. Sendo assim, devido ao perjúrio, constata-se que...


								...o jardineiro é o assassino.)"
				 << endl;
		}
		break;
	case 4:
		cout << "Como assim?? Eu nem estava no local na hora do crime !! ಠ_ಠ" << endl;
		break;

	default:
		break;
	}

	return 0;
}
