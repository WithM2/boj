#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define pii pair<int,int>;

int main() {
    fastio;
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        string from, to;
        cin >> from >> to;
        int fromB = 0, fromW = 0;
        for (int i = 0; i < from.size(); i++) {
            if (from[i] != to[i]) {
                (from[i] == 'W') ? fromW++ : fromB++;
            }
        }
        cout << ((fromW > fromB) ? fromW : fromB)  << "\n";

    }

    
    return 0;
}