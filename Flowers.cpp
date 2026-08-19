#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll maxBeauty(vector<int>& h, vector<int>& a) {
        int n = h.size();
        vector<ll> bit(n + 1, 0);
        
        auto update = [&](int idx, ll val) {
            while (idx <= n) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };
        
        auto query = [&](int idx) {
            ll res = 0;
            while (idx > 0) {
                res = max(res, bit[idx]);
                idx -= idx & -idx;
            }
            return res;
        };
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll best = query(h[i] - 1) + a[i];
            update(h[i], best);
            ans = max(ans, best);
        }
        
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> h(n), a(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    Solution sol;
    cout << sol.maxBeauty(h, a) << endl;
    
    return 0;
}