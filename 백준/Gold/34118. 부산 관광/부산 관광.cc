#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string A, B;
    cin >> A >> B;

    int p1, p3, p5, pp;
    cin >> p1 >> p3 >> p5 >> pp;

    vector<vector<int>> dp(n+6, vector<int>(n+6, INF));
    dp[0][0] = 0;

    vector<bool> va(n+2), vb(n+2);
    for (int i = 1; i <= n; i++) {
        va[i] = (A[i-1] == '1');
        vb[i] = (B[i-1] == '1');
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {

            if (dp[i][j] == INF) continue;
            int cur = dp[i][j];

            if (i < n) {
                if (!va[i+1]) {
                    dp[i+1][j] = min(dp[i+1][j], cur);
                } else {
                    dp[i+1][j] = min(dp[i+1][j], cur + p1);
                    dp[min(n, i+3)][j] = min(dp[min(n, i+3)][j], cur + p3);
                    dp[min(n, i+5)][j] = min(dp[min(n, i+5)][j], cur + p5);
                }
            }

            if (j < n) {
                if (!vb[j+1]) {
                    dp[i][j+1] = min(dp[i][j+1], cur);
                } else {
                    dp[i][j+1] = min(dp[i][j+1], cur + p1);
                    dp[i][min(n, j+3)] = min(dp[i][min(n, j+3)], cur + p3);
                    dp[i][min(n, j+5)] = min(dp[i][min(n, j+5)], cur + p5);
                }
            }

            // 묶음권
            for (int a = 0; a <= 4; a++) {
                for (int b = 0; b <= 4; b++) {
                    dp[min(n, i+a)][min(n, j+b)] =
                        min(dp[min(n, i+a)][min(n, j+b)], cur + pp);
                }
            }
        }
    }

    cout << dp[n][n] << "\n";
}