#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vi> G(n+1, vi());

    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color(n+1, -1);
    vector<bool> visited(n+1, false);
    queue<int> Q;
    bool is_bipartite = true;
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;

        Q.push(i);
        visited[i] = true;
        color[i] = 1;

        while (!Q.empty()) {
            
            int u = Q.front();
            Q.pop();

            for (auto v : G[u]) {
                if (visited[v] && color[v] != (1^color[u])) {
                    is_bipartite = false; 
                    goto done;
                }
                if (!visited[v]) {
                    color[v] = (1^color[u]);
                    Q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

done:
    if (!is_bipartite) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    rep(i, 1, n+1) {
        cout << color[i] + 1 << " ";
    }
    cout << endl;

}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

