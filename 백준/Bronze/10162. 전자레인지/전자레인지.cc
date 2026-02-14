#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    if (t%10) cout << -1;
    else {
        cout << t / 300 << " ";
        t %= 300;
        cout << t / 60 << " " << (t%60)/10;
    }

    
    return 0;
}