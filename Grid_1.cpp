#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; i++)
        cin >> grid[i];

    vector<vector<int>> dp(h, vector<int>(w, 0));

    dp[0][0] = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0)
                continue;

            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];

            dp[i][j] %= MOD;
        }
    }

    cout << dp[h - 1][w - 1] << '\n';

    return 0;
}