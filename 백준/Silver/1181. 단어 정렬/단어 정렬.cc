#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, string>> a;
    
    for (int i = 0; i < n; i++) {
        pair<int, string> tmp;
        
        string arr;
        cin >> arr;
        tmp.first = arr.length();
        tmp.second = arr;
        
        a.push_back(tmp);
    }
    
    sort(a.begin(), a.end(), compare);
    
    for (int i = 0; i < n; i++) {
        if (a[i+1].second == a[i].second) continue;
        else cout << a[i].second << "\n";
    }
    cout << a[n].second << "\n";
    return 0;
}
