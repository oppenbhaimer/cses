#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

vector<ll> f(1e6+5);
vector<ll> g(1e6+5);
vector<ll> N(1e6+5);

void solve() {

    int n;
    cin >> n;
    cout << N[n] << endl;

}

/*
 * N_0 = 1 
 * N_1 = 2 
 * N_2 = 8
 * N_3 = 34 (Looking at it by hand)
 *
 * N_n = sum_{i=1}^n [ (no. ways to tile 2xi with no 2-wide tile) * 
 *                     (no. ways to tile 2x(n-i)) ]
 *
 *     = sum_{i=1}^n [ (1 + 3^(i-1)) * N_{i-1} ]
 *       (proof: 1 way to tile with a single 2xi tile 
 *               if we divide into 2 1xi tiles, then each horizontal line has 
 *               3 ways to be a break: left, right or no break, giving 3^(i-1))
 *
 *     = sum_{i=1}^{n-1} N_i + sum_{i=1}^{n} [ 3^{i-1} * N_{n-i} ]
 *
 *  Let g(n) = sum_{i=1}^{n-1} N_i
 *      f(n) = sum_{i=1}^{n} [ 3^{i-1} * N_{n-i} ]
 *
 *  We have g(n) = g(n-1)  + N_{n-1}
 *          f(n) = 3f(n-1) + N_{n-1}
 *          N_n  = g(n) + f(n)
 *
 * Memoize and compute. Base cases: N_0 = 1, f(0) = g(0) = 0
 *
 */
int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    N[0] = 1;
    f[0] = 0;
    g[0] = 0;

    rep(i, 1, 1e6+1) {
        g[i] = (g[i-1]   + N[i-1]) % MOD;
        f[i] = (3*f[i-1] + N[i-1]) % MOD;

        N[i] = (g[i] + f[i]) % MOD;
    }

    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

