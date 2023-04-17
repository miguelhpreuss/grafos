#include <iostream>
#include <vector>
#define INFINITY 10001

using namespace std;

vector<vector<int>> adjs;
vector<bool> mk;
int B;

// A DFS(u) devolve a distância de u até B
int dfs(int u){
    if (u == B)
        return 0;
    //Marca u e visita adjacências
    mk[u] = true;
    for (int j = 0; j < adjs[u].size(); j++){
        int v = adjs[u][j];
        
        if (!mk[v]){
            int dist_v_b = dfs(v);
            if (dist_v_b < INFINITY){
                return 1 + dist_v_b;
            }
        }
    }
}

int main(){
    int A, N;
    cin >> N >> A >> B;
    A--;
    B--;

    //Construindo o grafo
    adjs = vector<vector<int>>(N);
    mk = vector<bool> (N, false);
    for (int i = 0; i < N; i++){
        int P, Q;
        cin >> P >> Q;
        P--;
        Q--;
        adjs[P].push_back(Q);
        adjs[Q].push_back(P);
    }

    //Disparando o DFS sobre o A
    cout << dfs(A) << "\n";

    return 0;    
}
