#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, 0, n)
        cin >> h[i];

    vector<int> dp(n, 2e9);
    dp[0] = 0;

    rep(i, 0, n){
        if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }

    cout << dp[n - 1] << "\n";

    return 0;
}