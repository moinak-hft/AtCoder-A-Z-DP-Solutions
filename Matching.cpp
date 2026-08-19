#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> a[i][j];
    
    vector<int> dp(1 << n, 0);
    dp[0] = 1;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int i = __builtin_popcount(mask);
        if (i == n) continue;
        
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0 && a[i][j] == 1) {
                int nmask = mask | (1 << j);
                dp[nmask] = (dp[nmask] + dp[mask]) % MOD;
            }
        }
    }
    
    cout << dp[(1 << n) - 1] << "\n";
    
    return 0;
}