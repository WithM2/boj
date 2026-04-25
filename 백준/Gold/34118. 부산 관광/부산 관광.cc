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

    // dp[i][j] : A는 i일까지, B는 j일까지 처리한 최소 비용
    vector<vector<int>> dp(n+6, vector<int>(n+6, INF));
    dp[0][0] = 0;

    // 1-index 편하게 쓰기
    vector<bool> va(n+2), vb(n+2);
    for (int i = 1; i <= n; i++) {
        va[i] = (A[i-1] == '1');
        vb[i] = (B[i-1] == '1');
    }

    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= n+1; j++) {

            int cur = dp[i-1][j-1];
            if (cur == INF) continue;

            bool aa = va[i];
            bool bb = vb[j];

            // 관광 안 하는 날 처리
            if (!aa) dp[i][j-1] = min(dp[i][j-1], cur);
            if (!bb) dp[i-1][j] = min(dp[i-1][j], cur);

            // 한국이 티켓
            if (aa) {
                dp[i][j-1] = min(dp[i][j-1], cur + p1);
                for (int k = 1; k <= 3; k++)
                    dp[min(n, i-1+k)][j-1] = min(dp[min(n, i-1+k)][j-1], cur + p3);
                for (int k = 1; k <= 5; k++)
                    dp[min(n, i-1+k)][j-1] = min(dp[min(n, i-1+k)][j-1], cur + p5);
            }

            // 정올이 티켓
            if (bb) {
                dp[i-1][j] = min(dp[i-1][j], cur + p1);
                for (int k = 1; k <= 3; k++)
                    dp[i-1][min(n, j-1+k)] = min(dp[i-1][min(n, j-1+k)], cur + p3);
                for (int k = 1; k <= 5; k++)
                    dp[i-1][min(n, j-1+k)] = min(dp[i-1][min(n, j-1+k)], cur + p5);
            }

            // 묶음권 (핵심)
            if (i == j) {
                for (int a = 0; a <= 4; a++) {
                    for (int b = 0; b <= 4; b++) {
                        dp[min(n, i-1+a)][min(n, j-1+b)] =
                            min(dp[min(n, i-1+a)][min(n, j-1+b)], cur + pp);
                    }
                }
            }
        }
    }

    cout << dp[n][n] << "\n";
}