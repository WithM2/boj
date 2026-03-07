#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>

string small(int n) {
    string ans = "";

    if (n == 7) return "8";

    while(n>8) {
        if (n == 11) return "20" + ans;
        else if (n == 17) return "200" + ans;
        else if (n == 10) return "22" + ans;
        ans += "8";
        n -= 7;
    }
    if (n == 2) ans = "1" + ans;
    else if (n == 3) ans = "7" + ans;
    else if (n == 4) ans = "4" + ans;
    else if (n == 5) ans = "2" + ans;
    else if (n == 6) ans = "6" + ans;
    else if (n == 7) ans = "8" + ans;
    else if (n == 8) ans = "10" + ans;
    return ans;
}

string big(int n) {
    string ans = "";
    if (n%2) {
        ans = "7";
        for (int i = 0; i < (n/2)-1; i++)
            ans += "1";
    }
    else {
        for (int i = 0; i < (n/2); i++)
            ans += "1";
    }
    return ans;
}

int main(){
    fastio;
    int testcase;
    cin >> testcase;
    while(testcase--) {
        int input;
        cin >> input;
        cout << small(input) << " " 
            << big(input) << "\n";

    }

    return 0;
}