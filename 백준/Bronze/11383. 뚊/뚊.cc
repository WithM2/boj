#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[11];
string tmp;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != tmp[j*2] || a[i][j] != tmp[j*2 + 1]) {
                cout << "Not Eyfa";
                return 0;
            }
        }
    }
    cout << "Eyfa";

    return 0;
}
