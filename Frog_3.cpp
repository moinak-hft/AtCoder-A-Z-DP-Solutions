#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

struct Line {
    ll m, b; // y = m*x + b
    ll get(ll x) { return m * x + b; }
};

struct CHT {
    vector<Line> lines;
    vector<ll> xs;
    int ptr = 0;
    
    bool bad(Line l1, Line l2, Line l3) {
        return (__int128)(l2.b - l1.b) * (l1.m - l3.m) >= (__int128)(l3.b - l1.b) * (l1.m - l2.m);
    }
    
    void add(ll m, ll b) {
        Line newLine = {m, b};
        while (lines.size() >= 2 && bad(lines[lines.size()-2], lines[lines.size()-1], newLine)) {
            lines.pop_back();
        }
        lines.push_back(newLine);
    }
    
    ll query(ll x) {
        while (ptr + 1 < lines.size() && lines[ptr].get(x) >= lines[ptr+1].get(x)) {
            ptr++;
        }
        return lines[ptr].get(x);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    ll C;
    cin >> N >> C;
    
    vector<ll> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    
    vector<ll> dp(N, INF);
    dp[0] = 0;
    
    CHT cht;
    cht.add(-2 * h[0], dp[0] + h[0] * h[0]);
    
    for (int i = 1; i < N; i++) {
        dp[i] = cht.query(h[i]) + h[i] * h[i] + C;
        cht.add(-2 * h[i], dp[i] + h[i] * h[i]);
    }
    
    cout << dp[N-1] << "\n";
    return 0;
}