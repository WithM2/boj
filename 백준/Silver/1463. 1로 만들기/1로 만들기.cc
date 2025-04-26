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
    
    int d[1000001] = {0};
    d[1] = 0;
    
    int n;
    cin>>n;
    
    for(int i = 2; i <= n; i++) {
        if (i%6==0) {
            d[i] = min(d[i/2], d[i/3]) + 1;
        }
        else if(i%2==0) {
            d[i] = min(d[i/2], d[i-1]) + 1;
        }
        else if (i%3==0) {
            d[i] = min(d[i/3], d[i-1]) + 1;
        }
        else d[i] = d[i-1]+1;
    }
    
    cout << d[n];
    

    return 0;
}








