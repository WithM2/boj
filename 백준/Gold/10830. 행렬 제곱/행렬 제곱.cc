#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, b;
long long proc[5][5];
long long ans[5][5];

void calc(long long A[5][5], long long B[5][5]) {
    long long tmp[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                tmp[i][j] += A[i][k] * B[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = tmp[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> proc[i][j];
            ans[i][j] = (i == j ? 1 : 0);
        }
    }
    
    while (b > 0) {
        if (b % 2 == 1) {
            calc(ans, proc);
        }
        calc(proc, proc);
        b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}