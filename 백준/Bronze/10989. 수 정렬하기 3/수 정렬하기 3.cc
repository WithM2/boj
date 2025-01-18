#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    int cnt[10001] = {0};
    
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
    }
    
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}