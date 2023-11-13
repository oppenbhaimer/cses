#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

class dsu {

    public:

    unordered_map<int,int> parent;
    unordered_map<int,int> size;

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {

    int n, m;
    cin >> n >> m;

    dsu d;
    rep(i, 1, n+1) d.make_set(i);

    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        d.union_sets(a, b);
    }

    unordered_set<int> parents; 
    rep(i, 1, n+1) {
        int set = d.find_set(i);
        if (parents.find(set) == parents.end()) {
            parents.insert(set);
        }
    }

    cout << parents.size()-1 << endl;
    vector<int> P(parents.begin(), parents.end());
    for (int i=0; i<P.size()-1; i++) {
        cout << P[i] << " " << P[i+1] << endl;
    }

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

