#include <bits/stdc++.h>
using namespace std;

int n, x;
int mx = 0;
bool flag = false;
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int delay, tm;
        cin >> delay >> tm;
        if (delay+tm <= x) {
            flag = true;
            if (mx < delay) mx = delay;
        }
    }
    
    if (flag) cout << mx;
    else cout << -1;
    
    return 0;
}