#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int n, m;
string s;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'I') {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (s[i+2*k+1] == 'O' && s[i+2*k+2] == 'I') {
                    cnt++;
                    if (cnt == n) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans;


    

    return 0;
}
    