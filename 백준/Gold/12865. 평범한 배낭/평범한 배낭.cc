#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define pii pair<int, int>

vector<pii> bag;
int dp[105][100005];

int main() {
    fastio;

    int n, k; cin >> n >> k;
    bag.push_back({0, 0});

    for (int i = 0; i < n; i++) {
        pii tmp;
        cin >> tmp.first >> tmp.second;
        bag.push_back(tmp);
    }

    //  i : 물건 index, j : 가방에 담을 수 있는 무게
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (bag[i].first <= j) {
                dp[i][j] = max(dp[i-1][j-bag[i].first] + bag[i].second, dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}