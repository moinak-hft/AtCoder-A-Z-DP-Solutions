#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
const ll MOD = 1e9 + 7;

int n;
string s;
main()
{
    cin >> n >> s;

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;

    for (int len = 1; len < n; len++)
    {
        vector<ll> pref(n + 1, 0), ndp(n + 1, 0);

        for (int j = 1; j <= len; j++)
            pref[j] = (pref[j - 1] + dp[j]) % MOD;

        if (s[len - 1] == '>')
        {
            for (int j = 1; j <= len + 1; j++)
                ndp[j] = (pref[len] - pref[j - 1] + MOD) % MOD;
        }
        else
        {
            for (int j = 1; j <= len + 1; j++)
                ndp[j] = pref[j - 1] % MOD;
        }

        swap(dp, ndp);
    }

    ll ans = 0;
    for (int j = 1; j <= n; j++)
        ans = (ans + dp[j]) % MOD;
    cout << ans << "\n";

    return 0;
}