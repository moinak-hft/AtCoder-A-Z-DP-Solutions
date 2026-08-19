#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)

typedef long long ll;
int n, u, v;
ll m;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    rep(i, 0, n - 1)
    {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<ll> dp(n + 1, 1), ans(n + 1, 0);

    auto dfs1 = [&](auto &self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            dp[u] = (dp[u] * (dp[v] + 1)) % m;
        }
    };


    auto dfs2 = [&](auto &self, int u, int p, ll out_u) -> void
    {
        ans[u] = (dp[u] * out_u) % m;

        vector<int> ch;
        for (int v : adj[u])
            if (v != p)
                ch.push_back(v);

        int k = ch.size();
        vector<ll> pref(k + 1, 1), suff(k + 1, 1);

        rep(i, 0, k) pref[i + 1] = (pref[i] * (dp[ch[i]] + 1)) % m;
        for (int i = k - 1; i >= 0; --i)  suff[i] = (suff[i + 1] * (dp[ch[i]] + 1)) % m;

        rep(i, 0, k)
        {
            int v = ch[i];
            ll p = (pref[i] * suff[i + 1]) % m;
            ll outdp = ((p * out_u) % m + 1) % m;
            self(self, v, u, outdp);
        }
    };

    dfs1(dfs1, 1, 0);
    dfs2(dfs2, 1, 0, 1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";

    return 0;
}