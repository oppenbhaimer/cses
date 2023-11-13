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

    vector<vector<int>> G(n+1, vi());

    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<int> parent(n+1, -1);

    queue<int> Q;
    Q.push(1);
    visited[1] = true;

    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();

        for (int v : G[t]) {
            if (!visited[v]) {
                Q.push(v);
                visited[v] = true;
                parent[v] = t;
            }
        }
    }

    if (parent[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    int v = n;
    path.push_back(v);
    while (parent[v] != -1) {
        path.push_back(parent[v]);
        v = parent[v];
    }

    cout << path.size() << endl;;
    for (int i=path.size()-1; i>=0; i--) {
        cout << path[i] << " ";
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

