#include <iostream>
#include <vector>
using namespace std;

class Graph {
  private:
    int V, E;
    vector<vector<int>> adjs;
  public:
    Graph(int VV, int EE) : V(VV), E(EE) {
        adjs = vector<vector<int>> (V);
    }
    void add_edge(int u, int v) {
        adjs[u].push_back(v);
        adjs[v].push_back(u);
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

class DFS {
  private:
    vector<bool> marked;
    int count;
    void dfs(Graph *G, int u) {
        marked[u] = true;
        count++;
        for (int v : *(G->adj(u)))
            if (!marked[v])
                dfs(G, v);
    }
  public:
    DFS(Graph *G, int s) {
        marked = vector<bool> (G->get_V());
        count = 0;
        dfs(G, s);
    }
    bool marked_to(int u) {
        return marked[u];
    }
    int get_count() {
        return count;
    }
};

class CC {
  private:
    vector<int> id;
    vector<bool> marked;
    int count;
    void dfs(Graph *G, int u) {
        marked[u] = true;
        id[u] = count;
        for (int v : *(G->adj(u)))
            if (!marked[v])
                dfs(G, v);
    }
  public:
    CC(Graph *G) {
        marked = vector<bool> (G->get_V());
        id = vector<int> (G->get_V());
        count = 0;
        for (int u = 0; u < G->get_V(); u++)
            if (!marked[u]) {
                dfs(G, u);
                count++;
            }
    }
    bool conectados(int u, int v) {
        return id[u] == id[v];
    }
    int contagem() {
        return count;
    }
    int get_id(int u) {
        return id[u];
    }
};

int main() {
    // Cria o grafo
    int V, E;
    cin >> V >> E;
    Graph *G = new Graph(V, E);
    for (int j = 0; j < E; j++) {
        int u, v;
        cin >> u >> v;
        G->add_edge(u, v);
    }
    
    // Cria um objeto CC
    CC *obj = new CC(G);
    
    // Coleta componentes conexas
    int m = obj->contagem();
    cout << m << " componentes" << '\n';
    vector<vector<int> > componentes(m);
    for (int u = 0; u < V; u++)
        componentes[obj->get_id(u)].push_back(u);
    
    // Imprime componentes conexas
    for (int i = 0; i < m; i++) {
        for (int u : componentes[i])
            cout << u << ' ';
        cout << '\n';
    }
    
    delete G, obj;
    return 0;
}
