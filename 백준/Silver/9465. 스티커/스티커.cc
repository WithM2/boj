#include <iostream>

#define N 100001
#define MAX(a,b) (((a) > (b)) ? (a) : (b)) 

using namespace std;

int testcase;
int dp[N][2];

int main() {
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> dp[i][0];
        }
        for (int i = 0; i < n; i++) {
            cin >> dp[i][1];
        }

        if (n == 1) {
            cout << MAX(dp[0][0], dp[0][1]) << "\n";
            continue;
        }
        dp[1][0] += dp[0][1];
        dp[1][1] += dp[0][0];
        if (n == 2) {
            cout << MAX(dp[1][0], dp[1][1]) << "\n";
            continue;
        }


        for (int i = 2; i < n; i++) {
            dp[i][0] += MAX(dp[i-1][1], dp[i-2][1]);
            dp[i][1] += MAX(dp[i-1][0], dp[i-2][0]);
        }
        
        cout << MAX(dp[n-1][0], dp[n-1][1]) << "\n";
    }

    return 0;
}