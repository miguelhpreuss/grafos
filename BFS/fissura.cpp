#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 500;
int n, f, g[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    vis[sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (g[x][y] <= f) {
            g[x][y] = -1;  // invadido pela lava
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (inside(nx, ny) && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    cout << "(" << nx << ", " << ny << "): " << "true" << endl;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> n >> f;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }

    bfs(0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == -1) {
                cout << "*";
            } else {
                cout << g[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
