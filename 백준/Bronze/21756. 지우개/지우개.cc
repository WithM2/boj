#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while ( n!=1 ) {
        if (n >= 2) {
            n /= 2;
            ans *= 2;
        }
    }
    cout << ans;

    return 0;
}