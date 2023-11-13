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

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair<int,int> adds[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int n_rooms = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (visited[i][j] or M[i][j] == '#') continue;
            queue<pair<int,int>> S;
            S.push({i,j});
            visited[i][j] = true;
            while (!S.empty()) {
                auto p = S.front();
                S.pop();
                for (auto a : adds) {
                    int y = p.first + a.first;
                    int x = p.second + a.second;
                    if (y < 0 or y >= n or x < 0 or x >= m) continue;
                    if (M[y][x] == '.' and !visited[y][x]) {
                        S.push({y,x});
                        visited[y][x] = true;
                    }
                }
            }
            n_rooms++;
        }
    }

    cout << n_rooms << endl;

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

