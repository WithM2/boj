#include <bits/stdc++.h>
using namespace std;

int testcase;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> testcase;
    while(testcase--) {
        unsigned long long int n;
        cin >> n;
        unsigned long long int ans = 0;
        unsigned long long int start = 0, end = n;

        while (start <= end) {
            unsigned long long int middle = (start+end)/2;
            if ((middle*(middle+1)) <= n*2) {
                start = middle + 1;
                ans = max(ans, middle);
            }
            else {
                end = middle - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
