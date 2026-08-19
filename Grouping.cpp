#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> a[i][j];

    int N = 1 << n;
    vector<ll> score(N, 0);

    for (int mask = 1; mask < N; ++mask) 
        for (int i = 0; i < n; ++i) 
            if ((mask >> i) & 1) 
                for (int j = i + 1; j < n; ++j) 
                    if ((mask >> j) & 1) 
                        score[mask] += a[i][j];

    vector<ll> dp(N, 0);

    for (int mask = 1; mask < N; ++mask) {
        dp[mask] = score[mask];
        for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask) 
            dp[mask] = max(dp[mask], dp[mask ^ submask] + score[submask]);
    }

    cout << dp[N - 1] << "\n";

    return 0;
}