#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll x, y, w, s;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y >> w >> s;

    ll ans1 = 0, ans2 = 0;
    ans1 = (x + y) * w;
    ans2 = min(x, y) * s;
    ans2 += min(abs(x - y) * w, (abs(x - y) % 2 == 1 ? (abs(x - y) - 1) * s + w : abs(x - y) * s));

    cout << min(ans1, ans2);

    
    return 0;
}