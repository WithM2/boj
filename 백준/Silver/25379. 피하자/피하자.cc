#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll arr[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll odd_left = 0;
    ll even_left = 0;

    ll tmp_odd = 0;
    ll tmp_even = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            tmp_odd += 1;
            even_left += tmp_even;
        }
        else {
            tmp_even += 1;
            odd_left += tmp_odd;
        }
    }

    cout << min(odd_left, even_left);
    



    return 0;
}
