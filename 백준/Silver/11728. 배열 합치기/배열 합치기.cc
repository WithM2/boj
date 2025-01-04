#include <bits/stdc++.h>
using namespace std;

int a[1000001], b[1000001], ans[2000003];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int idx_a = 0, idx_b = 0;
    for (int i = 0; i < n+m; i++) {
        if (idx_a >= n) {
            ans[i] = b[idx_b];
            idx_b++;
        }
        else if (idx_b >= m) {
            ans[i] = a[idx_a];
            idx_a++;
        }
        else if (a[idx_a] > b[idx_b]) {
            ans[i] = b[idx_b];
            idx_b++;
        }
        else {
            ans[i] = a[idx_a];
            idx_a++;
        }
    }

    for (int i = 0; i < n+m; i++) {
        cout << ans[i] << " ";
    }


	return 0;
}