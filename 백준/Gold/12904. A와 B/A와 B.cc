#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string a, b;

int main(){
    fastio;
    cin >> a >> b;

    while (a.size() < b.size()) {
        
        char last = b[b.size()-1];

        b.erase(b.begin() + b.size()-1);
        if (last == 'B') {
            reverse(b.begin(), b.end());
        }
        
        if (a == b) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}