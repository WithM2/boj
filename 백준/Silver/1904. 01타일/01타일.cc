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
    cin>>n;
    
    int a=0, b=1, c;
    
    while (n--) {
        c = (a+b)%15746;
        a = b;
        b = c;
    }
    
    cout << c;
    
    
    return 0;
}







