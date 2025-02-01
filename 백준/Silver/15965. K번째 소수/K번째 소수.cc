#include <bits/stdc++.h>
using namespace std;

#define MAX 10000001

int K;
bool prime[MAX]; // prime이면 false, 아니면 true
int k = 1;
int ans = 2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    while (k<K) {
        if (prime[ans]) continue;
        int n = 1;
        while (ans * n <= MAX) {
            prime[ans * n] = true;
            n++;
        }
        ans++;
        while (prime[ans]) ans++;
        k++;
    }

    cout << ans;
	return 0;
}