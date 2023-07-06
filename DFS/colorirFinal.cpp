#include <iostream>
#include <vector>
#include <stack>

using namespace std;

char fig[200][200] = {};

int n, m, q = 0;

bool in(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void printStack(stack<pair<int,int>> stk) {
    while (!stk.empty()) {
        cout << "(" << stk.top().first << "," << stk.top().second << ") ";
        stk.pop();
    }
    cout << endl;
}


void ff(int x, int y) {
    stack<pair<int,int>> stk;
    stk.push({x, y});

    while (!stk.empty()) {
        printStack(stk);
        
        int i = stk.top().first;
        int j = stk.top().second;
        
        stk.pop();
        
        if (!in(i,j) || fig[i][j] == 1)
            continue;

        // Visita (i, j)
        fig[i][j] = 1;
        q++;

        stk.push({i-1, j-1}); stk.push({i-1, j}); stk.push({i-1, j+1});
        stk.push({i,   j-1});                    stk.push({i,   j+1});
        stk.push({i+1, j-1}); stk.push({i+1, j}); stk.push({i+1, j+1});

        
    }
}

int main () {
    cin >> n >> m;

    int x, y, k;
    cin >> x >> y >> k;

    // Quadrado Inicial
    x--;
    y--;

    // Marcando os cheios
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        fig[a][b] = 1;
    }

    // Dispara o flood-fill
    ff(x, y);

    // Resposta
    cout << q << "\n";
    return 0;
}
