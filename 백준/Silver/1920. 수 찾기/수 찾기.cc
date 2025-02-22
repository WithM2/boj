#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n;
    vector<string> a;
    
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    
    cin >> m;
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        auto lower = lower_bound(a.begin(), a.end(), tmp);
        
        if (a[lower-a.begin()] == tmp) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    
    
    return 0;
}
