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
    
    int test;
    cin>>test;
    
    long long p[101] = {0};
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    
    for (int i = 4; i < 101; i++) {
        p[i] = p[i-2] + p[i-3];
    }
    
    while (test--) {
        int n;
        cin >> n;
        cout << p[n] << "\n";
    }
    
    
    return 0;
}







