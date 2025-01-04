#include <bits/stdc++.h>
using namespace std;

int a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int start = 0, end = n - 1;
    int sum = INT_MAX;
    int best_start = start, best_end = end;

    while (start < end) {
        int tmp = a[start] + a[end];

        if (abs(tmp) < sum) {
            sum = abs(tmp);
            best_start = start;
            best_end = end;
        }

        if (tmp < 0) {
            start++;
        } else if (tmp > 0) {
            end--;
        } else {  // tmp == 0
            cout << a[start] << " " << a[end];
            return 0;
        }
    }

    cout << a[best_start] << " " << a[best_end];
    return 0;
}
