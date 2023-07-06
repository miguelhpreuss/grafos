#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjs;
vector<bool> mk;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    mk[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adjs[u].size(); i++) {
            int w = adjs[u][i];
            if (!mk[w]) {
                mk[w] = true;
                q.push(w);
            }
        }
    }
}

int main(){
    int E, L;
    int k = 1;
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
            if (!mk[i]) {
                falha = true;
            }
        }

        cout << "Teste " << k++ << "\n";

        if (!falha) {
            cout << "normal" << "\n";
        }
        else {
            cout << "falha" << "\n";
        }
        cout << "\n";

        cin >> E >> L;
    }

    return 0;
}
