#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 0;
vector<bool> map;
bool a[27], b[27], c[14];

void solve(int t) {
    if (t == n) {
        cnt++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (c[i] || a[i+t] || b[i-t+n-1]) continue;
        c[i] = true;
        a[i+t] = true;
        b[i-t+n-1] = true;
        solve(t+1);
        c[i] = false;
        a[i+t] = false;
        b[i-t+n-1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    solve(0);
    cout << cnt;
    return 0;
}


