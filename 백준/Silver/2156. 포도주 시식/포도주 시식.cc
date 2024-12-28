#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> glass;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    glass.push_back(0);
    dp.push_back(0);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        glass.push_back(tmp);
        dp.push_back(0);
    }

    dp[1] = glass[1];
    dp[2] = glass[1] + glass[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(max(dp[i-3]+glass[i-1]+glass[i], dp[i-2]+glass[i]), dp[i-1]);
    }

    cout << dp[n];

    return 0;
}