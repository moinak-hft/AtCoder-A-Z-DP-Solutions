#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; ++i)
typedef long long ll;

int n;
int main() {
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    rep(i, 0, n) 
        dp[i][i] = a[i];
    
    for (int len = 2; len <= n; len++) 
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    
    cout << dp[0][n-1] << endl;
    
    return 0;
}