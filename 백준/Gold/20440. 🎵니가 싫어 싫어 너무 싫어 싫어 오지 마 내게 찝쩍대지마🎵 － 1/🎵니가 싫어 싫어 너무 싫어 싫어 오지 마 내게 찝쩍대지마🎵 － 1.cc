#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

int ans = 0;
vector<pii> mos;

bool cmp(pii x, pii y) {
    if (x.first == y.first) return x.second < y.second;
    else return x.first < y.first;
}

int main(){
    fastio;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int in, out;
        cin >> in >> out;
        mos.push_back({in, 1});
        mos.push_back({out, -1});
    }
    sort(mos.begin(), mos.end(), cmp);

    int ans = 0;
    int now = 0;
    int start = 0, finish = 0;

    // cout << endl;
    // for (auto i : mos) cout << i.first << ' ' << i.second << endl;

    bool flag = false;
    for (auto i : mos) {
        if (i.second == 1) {
            now++;
            if (now == ans && finish == i.first) flag = true;
        }
        else {
            if (ans == now && flag) {
                finish = i.first;
                flag = false;
            }
            now--;
        }
        if (ans < now) {
            ans = now;
            start = i.first;
            flag = true;
        }
    }

    cout << ans << "\n";
    cout << start << " " << finish;

    return 0;
}








