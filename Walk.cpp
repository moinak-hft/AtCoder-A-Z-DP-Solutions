#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

vector<vector<ll>> mat_mul(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++) 
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
        }
    }
    return result;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> A, ll k) {
    int n = A.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    
    while (k > 0) {
        if (k & 1) 
            result = mat_mul(result, A);
        A = mat_mul(A, A);
        k >>= 1;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    ll K;
    cin >> N >> K;
    
    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> A[i][j];
    
    vector<vector<ll>> result = mat_pow(A, K);
    
    ll ans = 0;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            ans = (ans + result[i][j]) % MOD;
    
    cout << ans << "\n";
    
    return 0;
}