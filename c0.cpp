#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
  int V, E;
  vector<vector<int>> adjs;
public:
  Graph(int VV, int EE) : V(VV), E(EE) {
    adjs = vector<vector<int>>(V);
  }
  
  void add_edge(int u, int v) {
    adjs[u].push_back(v);
    adjs[v].push_back(u);
    E++;
  }
  
  vector<int> *adj(int u) {
    return &adjs[u];
  }
  
  int get_V() {
    return V;
  }
  
  int get_E() {
    return E;
  }
};

void imprime(Graph *G) {
  int V = G->get_V();

  for (int u = 0; u < V; u++) {
    for (int v : *(G->adj(u))) {
      if (u < v) {
        cout << u << " " << v << endl;
      }
    }
  }
}

int grau(Graph *G, int u) {
  return G->adj(u)->size();
}

double grau_medio(Graph *G) {
  int V = G->get_V();
  int E = G->get_E();

  int soma_graus = 0;

  for (int i = 0; i < V; i++) {
    soma_graus += grau(G, i);
  }

  return (double)soma_graus / V;
}

int main() {
  Graph *G = new Graph(13, 0);

  G->add_edge(0, 5);
  G->add_edge(4, 3);
  G->add_edge(0, 1);
  G->add_edge(9, 12);
  G->add_edge(6, 4);
  G->add_edge(5, 4);
  G->add_edge(0, 2);
  G->add_edge(11, 12);
  G->add_edge(9, 10);
  G->add_edge(0, 6);
  G->add_edge(7, 8);
  G->add_edge(9, 11);
  G->add_edge(5, 3);

  cout << "Arestas do grafo:" << endl;
  imprime(G);

  cout << endl;

  for (int u = 0; u < G->get_V(); u++) {
    cout << "Grau do vértice " << u << ": " << grau(G, u) << endl;
  }

  cout << endl;

  cout << "Grau médio do grafo: " << grau_medio(G) << endl;

  delete G;

  return 0;
}
