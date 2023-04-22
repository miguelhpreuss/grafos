#include <iostream>
#include <vector>
#include <climits> // troca INFINITY por INT_MAX

using namespace std;

vector<vector<int>> adjs;
vector<bool> mk;
int B;

// A DFS(u) devolve a distância de u até B
int dfs(int u) {
    if (u == B)
        return 0;
    // Marca u e visita adjacências
    mk[u] = true;
    for (int j = 0; j < adjs[u].size(); j++) {
        int v = adjs[u][j];
        if (!mk[v]) {
            int dist_v_b = dfs(v);
            if (dist_v_b < INT_MAX) { // usa INT_MAX no lugar de INFINITY
                return 1 + dist_v_b;
            }
        }
    }
    // se u não leva até B, então retorna infinito
    return INT_MAX;
}

int main() {
    int A, N;
    cin >> N >> A >> B;
    A--;
    B--;

    // Construindo o grafo
    adjs = vector<vector<int>>(N);
    mk = vector<bool>(N, false);
    for (int i = 0; i < N - 1; i++) { // corrige o loop para ler as arestas
        int P, Q;
        cin >> P >> Q;
        P--;
        Q--;
        adjs[P].push_back(Q);
        adjs[Q].push_back(P);
    }

    // Disparando o DFS sobre o A
    cout << dfs(A) << "\n";

    return 0;
}
