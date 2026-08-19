#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

string s;
int m;
ll dp[10005][105][2];

ll solve(int pos, int sum, int tight) {
    if (pos == s.size()) 
        return (sum % m == 0) ? 1 : 0;
    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    
    int limit = tight ? (s[pos] - '0') : 9;
    ll ans = 0;
    
    for (int d = 0; d <= limit; d++) {
        int ntight = tight && (d == limit);
        ans = (ans + solve(pos + 1, (sum + d) % m, ntight)) % MOD;
    }
    
    return dp[pos][sum][tight] = ans;
}

int main() {
    cin >> s >> m;
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, 0, 1);
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;
    return 0;
}