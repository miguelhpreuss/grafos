#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10;

// Matriz que representa a caverna
int cave[MAXN][MAXN];

// Estrutura para representar uma posição na caverna
struct Pos {
    int x, y, dist;
};

// Vetores para movimentação nas quatro direções
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Função que realiza a busca em largura
int bfs(Pos start, int n, int m) {
    // Matriz de visitados
    bool visited[MAXN][MAXN] = {false};
    visited[start.x][start.y] = true;
    
    // Fila para a BFS
    queue<Pos> q;
    q.push(start);
    
    while (!q.empty()) {
        Pos current = q.front();
        q.pop();
        
        // Verifica se encontrou a saída
        if (cave[current.x][current.y] == 0) {
            return current.dist;
        }
        
        // Tenta se mover para as quatro direções
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            // Verifica se a nova posição é válida e ainda não foi visitada
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && cave[nx][ny] != 2 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.dist + 1});
                cout << "(" << nx << ", " << ny << "): " << current.dist + 1 << endl;
            }
        }
    }
    
    // Retorna -1 se não encontrou uma saída
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Lê a matriz que representa a caverna
    Pos start = {-1, -1, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cave[i][j];
            if (cave[i][j] == 3) {
                start = {i, j, 0};
            }
        }
    }
    
    // Executa a busca em largura
    int result = bfs(start, n, m);
    
    // Imprime o resultado
    cout << result << endl;
    
    return 0;
}
