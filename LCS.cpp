#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	for(int i=1; i<=s.size(); ++i) {
		for(int j=1; j<=t.size(); ++j) {
			if(s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	//cout << dp[s.size()][t.size()];
	int i=s.size(), j=t.size();
	string ans;
	while(i&&j) {
		if(s[i-1]==t[j-1]) {
			ans=s[i-1]+ans;
			--i;
			--j;
			continue;
		}
		if(dp[i-1][j]>dp[i][j-1])
			--i;
		else
			--j;
	}
	cout << ans;
}