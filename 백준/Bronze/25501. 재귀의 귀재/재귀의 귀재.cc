#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    while(n--) {
        string a;
        cin >> a;
        
        int start = 0, finish = a.length()-1;
        
        int cnt = 1;
        int chk = 1;
        
        for (int i = 0; i < a.length(); i++) {
            if (start>=finish) break;
            
            if(a[start] == a[finish]) {
                cnt++;
                start++;
                finish--;
            }
            else {
                chk = 0;
                break;
            }
        }
        
        cout << chk << " " << cnt << "\n";
        
        
        
    }
    
    
    
    
    
    return 0;
}





