#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    vector<bool> dp(k + 1, false);
    
    for (int i = 1; i <= k; i++) {
        for (int x : v) {
            if (x <= i && !dp[i - x]) {
                dp[i] = true;
                break;
            }
        }
    }
    
    cout << (dp[k] ? "First" : "Second") << "\n";
    return 0;
}