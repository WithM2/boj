#include <iostream>

#define MAX 1001

using namespace std;

int n;

int main() {
    cin >> n;
    int arr[MAX];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[MAX];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout << max << endl;

    return 0;
}
    