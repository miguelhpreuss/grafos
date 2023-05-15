#include <iostream>
#include <vector>

using namespace std;

class Digraph
{
    int V, E;
    vector<vector<int>> adjs;

public:
    Digraph(int VV) : V(VV), E(0)
    {
        adjs = vector<vector<int>>(V);
    }
    int get_V() { return V; };
    void add_edge(int u, int v)
    {
        adjs[u].push_back(v);
        E++;
    }
    vector<int> *adj(int u)
    {
        return &adjs[u];
    }

    Diagraph* reverso(){
        Digraph* R = new Digraph(V);
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < *adj(u); v++) {
                R->add_edge(v, u);
            }
            
        }
        return R;
    }
};

// // // class DFS_dirigida {
// // // private:
// // //     vector<bool> mk;
// // //     void dfs(Digraph *G, int u)
// // //     {
// // //         mk[u] = true;
// // //         for (int v : *(G->adj(u)))
// // //             if (!mk[v])
// // //                 dfs(G, v);
// // //     }

// // // public:
// // //     DFS_Dirigida(Digraph *G, vector<int> &ss)
// // //     {
// // //         marked = vector<bool>(G->get_V());
// // //         for (int s : ss)
// // //             if (!mk[v])
// // //                 dfs(G, v);
// // //     }
// // //     bool marcado(int u)
// // //     {
// // //         return mk[u];
// // //     }
// // // }

void imprime(Digraph* G){
    for (int u = 0; u < V; u++) {
        for (int v : *adj(u)){
            cout << u << "->" << v;
        }
    }    
}

int main() {
    int V, E;
    cin >> V >> E;

    Digraph* G = new Digraph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        G->add_edge(u, v);
    }

    imprime(G);
    imprime(G->reverso())
    
}