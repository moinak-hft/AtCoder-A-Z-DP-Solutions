#include<bits/stdc++.h>
using namespace std;

int N;
double dp[301][301][301];
bool vis[301][301][301];

double solve(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) return 0;
    if (vis[i][j][k]) return dp[i][j][k];

    int total = i + j + k;
    double ans = (double)N / total;

    if (i > 0) ans += (double)i / total * solve(i - 1, j, k);
    if (j > 0) ans += (double)j / total * solve(i + 1, j - 1, k);
    if (k > 0) ans += (double)k / total * solve(i, j + 1, k - 1);

    vis[i][j][k] = true;
    return dp[i][j][k] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a == 1) cnt1++;
        else if(a == 2) cnt2++;
        else cnt3++;
    }
    
    cout << fixed << setprecision(10) << solve(cnt1, cnt2, cnt3) << "\n";
    
    return 0;
}