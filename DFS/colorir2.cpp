#include <iostream>

using namespace std;

char fig[200][200];
int m, n;

bool in(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int ff(int x, int y) {
    stack <pair<int, int>> st;
    int q = 0;
    st.push({x ,y});
    while (!st.empty()){
        
    }
    return q;
}

int main() {
    int x, y, k;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        fig[a][b] = 1;
    }
    
    q = ff(x, y);

    cout << q << "\n";

    return 0;
}
