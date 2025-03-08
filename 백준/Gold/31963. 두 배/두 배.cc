#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
int cnt = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 1; i < n; i++) {
        while(v[i] < v[i-1]) {
            cnt++;
            v[i] *= 2;
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    
    cout << cnt;
    
    return 0;
}