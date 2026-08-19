#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, W;
	cin >> n >> W;
	int w[n], v[n];
	for(int i=0; i<n; ++i)
		cin >> w[i] >> v[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=0; i<n; ++i) {
		for(int j=100000-v[i]; j>=0; --j)
			dp[j+v[i]]=min(dp[j]+w[i], dp[j+v[i]]);
	}
	for(int i=100000; i>=0; --i) {
		if(dp[i]<=W) {
			cout << i;
			break;
		}
	}
}