#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    vector<int> dp(n, 2e9);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= k; ++j)
            if (i + j < n)
                dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));

    cout << dp[n - 1] << "\n";

    return 0;
}