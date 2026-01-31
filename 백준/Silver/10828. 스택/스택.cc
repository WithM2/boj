#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int arr[10005]; // 스택
int num = 0;    // 스택에 현재 몇개 저장?

int main(){
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int x;
            cin >> x;
            arr[num] = x;
            num++;
        }
        else if (input == "pop") {
            if (num == 0) {
                cout << -1 << "\n";
            }
            else {
                cout << arr[num-1] << "\n";
                num--;
            }
        }
        else if (input == "size") {
            cout << num << "\n";
        }
        else if (input == "empty") {
            if (num == 0) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if (input == "top") {
            if (num == 0) {
                cout << -1 << "\n";
            }
            else {
                cout << arr[num-1] << "\n";
            }
        }
    }
    return 0;
}


// dp[i][j];   // i 자릿수 숫자 각 자릿수 합을 3으로 나누면 나머지가 j야

// dp[1][0] = 0    dp[1][1] = 1    dp[1][2] = 1
// dp[2][0] = 2    dp[2][1] = 1    dp[2][2] = 1
// dp[3][0] = 2    dp[3][1] = 3    dp[3][2] = 3
// dp[4][0] = 6    dp[4][1] = 5    dp[4][2] = 5
// 1111 : dp[4][1]
// 1115 : dp[4][]


// int index = 3;
// a[1] = 3
// a[2] = 4
// a[3] = 6





