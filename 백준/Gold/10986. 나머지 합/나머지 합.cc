#include <bits/stdc++.h>
#define MAX 1000002
#define ll long long

using namespace std;

ll n, m;
ll arr[MAX], cnt[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    ll ans = 0;
    ll prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        prefix_sum = (prefix_sum + tmp) % m;
        
        if (prefix_sum == 0) ans++;

        ans += cnt[prefix_sum];

        cnt[prefix_sum]++;
    }

    cout << ans;

    return 0;
}
