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

class DFS_Paths {
  private:
    const int s;
    vector<bool> marked;
    vector<int> edge_to;
    void dfs(Graph *G, int u) {
        marked[u] = true;
        vector<int> *adju = G->adj(u);
        for (int j = 0; j < adju->size(); j++) {
            int v = (*adju)[j];
            if (!marked[v]) {
                edge_to[v] = u;
                dfs(G, v);
            }
        }
    }
  public:
    DFS_Paths(Graph *G, int ss) : s(ss) {
        marked = vector<bool> (G->get_V());
        edge_to = vector<int> (G->get_V());
        dfs(G, s);
    }
    bool has_path_to(int u) {
        return marked[u];
    }
    vector<int> path_to(int u) {
        vector<int> path;
        if (!has_path_to(u)) return path;
        for (int x = u; x != s; x = edge_to[x])
            path.push_back(x);
        path.push_back(s);
        reverse(path.begin(), path.end());
        return path;
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

    // Elege uma origem
    int s = 0;

    // Cria um objeto cliente de Graph que coleta
    // info sobre caminhos em G, originados em s
    DFS_Paths *obj = new DFS_Paths(G, s);

    // Testa e imprime caminhos (consulta obj)
    for (int u = 0; u < V; u++) {
        if (obj->has_path_to(u)) {
            cout << s << "->" << u << ": " << s << " - ";
            vector<int> p = obj->path_to(u);
            for (int x : p)
                cout << x << " - ";
            cout << '\n';
        }
    }

    delete G, obj;
    return 0;
}
