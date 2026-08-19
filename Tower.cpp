#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
int w, s, n;
ll v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<tuple<int, int, ll>> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> w >> s >> v;
        b[i] = {w, s, v};
    }

    sort(b.begin(), b.end(), [](const auto &a, const auto &b)
         { return get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b); });

    int max_w = 20000;
    vector<ll> dp(max_w + 1, 0);

    for (const auto &[w_i, s_i, v_i] : b)
        for (int w = s_i; w >= 0; --w)
            dp[w + w_i] = max(dp[w + w_i], dp[w] + v_i);

    ll ans = 0;
    rep(w, 0, max_w + 1)
        ans = max(ans, dp[w]);

    cout << ans << "\n";

    return 0;
}