#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
const ll MOD = 1e9 + 7;
vector<vector<int>> g;
vector<vector<ll>> dp;

void dfs(int u, int p) {
    dp[u][0] = 1;
    dp[u][1] = 1;
    
    for (int v : g[u]) {
        if (v == p) continue;
        
        dfs(v, u);
        
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    g.resize(n);
    dp.resize(n, vector<ll>(2, 0));
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]) % MOD << "\n";
    return 0;
}