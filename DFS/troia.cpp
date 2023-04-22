#include <iostream>
#include <vector>
using namespace std;

class Graph {
   private:
    int V, E;
    vector<vector<int>> adj;

   public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        adj.resize(V);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> get_adj(int u) { return adj[u]; }
    int get_V() { return V; }
};

class CC {
   private:
    Graph *G;
    vector<bool> marked;
    vector<int> id;
    int count;

    void dfs(int u) {
        marked[u] = true;
        id[u] = count;

        for (int v : G->get_adj(u)) {
            if (!marked[v]) {
                dfs(v);
            }
        }
    }

   public:
    CC(Graph *G) {
        this->G = G;
        marked.resize(G->get_V(), false);
        id.resize(G->get_V(), 0);
        count = 0;

        for (int u = 0; u < G->get_V(); u++) {
            if (!marked[u]) {
                dfs(u);
                count++;
            }
        }
    }

    bool connected(int u, int v) { return id[u] == id[v]; }
    int get_count() { return count; }
    int get_id(int u) { return id[u]; }
};

int main() {
    int N, M;

    cin >> N >> M;

    Graph *G = new Graph(N, M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G->add_edge(u - 1, v - 1);
    }

    CC *obj = new CC(G);
    cout << obj->get_count() << endl;

    delete G;
    delete obj;


    return 0;
}
