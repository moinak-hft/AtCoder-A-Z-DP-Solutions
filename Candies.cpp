#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
typedef long long ll;
const int MOD=1e9+7;

int n, k;
int main() {
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<ll> dp(k + 1, 0), pref(k + 1, 0);
    
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        pref[0] = dp[0];
        for(int j = 1; j <= k; j++) 
            pref[j] = (pref[j-1] + dp[j]) % MOD;
        
        vector<ll> ndp(k + 1, 0);
        for(int j = 0; j <= k; j++) {
            if(j - a[i] > 0)
                ndp[j] = (pref[j] - pref[j - a[i] - 1] + MOD) % MOD;
            else 
                ndp[j] = pref[j];
        }
        dp = ndp;
    }
    
    cout << dp[k] % MOD << endl;
    return 0;
}