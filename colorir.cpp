#include <iostream>
#include <vector>

using namespace std;

char fig[200][200] = {};

int n, m, q = 0;

bool in(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void ff(int i, int j) {
    if (!in(i,j) || fig[i][j] == 1)
        return;

    // Visita (i, j)
    fig[i][j] = 1;
    q++;
    ff(i-1, j-1); ff(i-1, j); ff(i-1, j+1);
    ff(i,   j-1);             ff(i,   j+1);
    ff(i+1, j-1); ff(i+1, j); ff(i+1, j+1);
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
