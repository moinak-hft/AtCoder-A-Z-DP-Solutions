#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n, a, b, c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> dp(3, 0);

    rep(i, 0, n) 
    {
        cin >> a >> b >> c;
        
        vector<int> ndp(3, 0);
        ndp[0] = a + max(dp[1], dp[2]);
        ndp[1] = b + max(dp[0], dp[2]);
        ndp[2] = c + max(dp[0], dp[1]);
        
        swap(dp, ndp);
    }

    cout << max({dp[0], dp[1], dp[2]}) << "\n";

    return 0;
}