#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjs;
vector<bool> mk;

int main(){
    int E, L;
    int k = 0;
    cin >> E >> L;

    while (E != 0) {
        adjs = vector<vector<int>> (E);
        for (int i = 0; i < L; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }
        
        mk = vector<bool> (E, false);
        bfs(0);

        //resultado

        bool falha = false;
        for (int i = 0; i < E; i++) {
            if (mk[i]) {
                falha = true;
            }
        }

        cout << "Teste: " << k++ << "\n";

        if (falha == false){
            cout << "Normal" << "\n";
        }
        else 
            cout << "Falha" << "\n";
        

    }

    return 0;
}