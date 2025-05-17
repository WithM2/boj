#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int testcase;
	int n;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		int cnt = 0;
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				int square = 2*(a*a + b*b);
				int div = a*b;
				if (square % div == 0) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}




	return 0;
}