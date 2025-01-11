#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<string> name, ans;
    
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        name.push_back(tmp);
    }
    
    sort(name.begin(), name.end());
    
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        
        if (binary_search(name.begin(), name.end(), tmp)) {
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    
    
    

    return 0;
}



