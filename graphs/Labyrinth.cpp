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

    vector<string> M(n);
    rep(i, 0, n) cin >> M[i];

    pair<int,int> start, end;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (M[i][j] == 'A') start = {i,j};
            if (M[i][j] == 'B') end   = {i,j};
        }
    }

    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> parent(n, vector<char>(m, 'N'));
    pair<int,int> adds[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    char dir[4] = {'R', 'L', 'D', 'U'};

    queue<pair<int,int>> S;
    S.push(start);
    visited[start.first][start.second] = true;

    while (!S.empty()) {
        auto p = S.front();
        S.pop();
        for (int i=0; i<4; i++) {
            auto a = adds[i];
            auto d = dir[i];
            int y = p.first + a.first;
            int x = p.second + a.second;
            if (y < 0 or y >= n or x < 0 or x >= m) continue;
            if (M[y][x] != '#' and !visited[y][x]) {
                S.push({y,x});
                parent[y][x] = d;
                visited[y][x] = true;
            }
            if (pair<int,int>(y,x) == end) {
                goto done;
            }
        }
    }

done:

    if (parent[end.first][end.second] == 'N') {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    vector<char> path;

    auto pos = end;
    while (pos != start) {
        char p = parent[pos.first][pos.second];
        path.push_back(p);
        if (p == 'U') pos = {pos.first+1, pos.second};
        if (p == 'D') pos = {pos.first-1, pos.second};
        if (p == 'L') pos = {pos.first, pos.second+1};
        if (p == 'R') pos = {pos.first, pos.second-1};
    }

    cout << path.size() << endl;
    for (int i=path.size()-1; i>=0; i--) {
        cout << path[i];
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
