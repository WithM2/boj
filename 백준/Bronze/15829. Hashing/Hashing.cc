#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    string alphabets;
    
    cin >> n >> alphabets;
    
    long long M = 1234567891;
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++){
        long long r = 1;
        char a = alphabets[i];
        a -= ('a' - 1);
        
        for (int j = 0; j < i; j++) {
            r *= 31;
            if (r > M) r%=M;
        }
        
        ans += (long long) a * r;
        
        if (ans > M) ans %= M;
    }
    
    
    cout << ans;
    
    
    return 0;
}
