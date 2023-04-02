#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10005;

vector<int> g[MAXN];
bool vis[MAXN];

int bfs(int s, int t) {
    queue<pair<int, int>> q;
    q.push({s, 0});
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        if (u == t) return d;

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({v, d+1});
            }
        }
    }

    return -1; // não alcançou t
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i < n; i++) {
        int p, q;
        cin >> p >> q;

        g[p].push_back(q);
        g[q].push_back(p);
    }

    int ans = bfs(a, b);
    cout << ans << endl;

    return 0;
}
