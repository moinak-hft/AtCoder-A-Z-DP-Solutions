#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, dp[mxN], ui, vi, ans;
vector<int> adj[mxN];

int cdp(int u) {
	if(!dp[u]) {
		for(int v : adj[u])
			dp[u]=max(cdp(v), dp[u]);
		++dp[u];
	}
	return dp[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> ui >> vi, --ui, --vi;
		adj[ui].push_back(vi);
	}
	for(int i=0; i<n; ++i)
		ans=max(cdp(i), ans);
	cout << ans-1;
}