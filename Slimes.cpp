#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> prefix(n, 0);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++)
            {
                ll c;
                if (i >= 1)
                    c = dp[i][k] + dp[k + 1][j] + (prefix[j] - prefix[i - 1]);
                else
                    c = dp[i][k] + dp[k + 1][j] + (prefix[j]);
                dp[i][j] = min(dp[i][j], c);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}