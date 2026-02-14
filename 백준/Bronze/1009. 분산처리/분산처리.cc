#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main(){

    int tc;
    cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a >> b;
        int tmp = a%10;
        for (int i = 0; i < b-1; i++) {
            a = (a * tmp) % 10;
        }
        if (b == 1) cout << (tmp == 0 ? 10 : tmp) << "\n";
        else {
            cout << ((a >= 10 || a == 0) ? 10 : a) << "\n";
        }
    }
    

    return 0;
}