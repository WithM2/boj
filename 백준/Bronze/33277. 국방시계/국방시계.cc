#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    cin >> n >> m;

    int minutes = 1440 * m / n;
    if (minutes / 60 < 10) {
        cout << "0";
    }
    cout << minutes / 60 << ":";
    if (minutes % 60 < 10) {
        cout << "0";
    }
    cout << minutes % 60;


    return 0;
}