#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ld> p(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i];

    vector<vector<ld>> dp(n + 1, vector<ld>(n + 1, 0));

    dp[0][0] = 1.0L;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            dp[i][j] += dp[i - 1][j] * (1.0L - p[i - 1]);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
        }
    }

    ld res = 0.0L;

    for (int h = n / 2 + 1; h <= n; ++h) 
        res += dp[n][h];

    cout << fixed << setprecision(10)
         << (double)res << '\n';

    return 0;
}