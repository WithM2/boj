#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string text[5];
	for (int i = 0; i < 5; i++) cin >> text[i];

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (text[j].length()-1 < i) {
				continue;	// cout 스킵
			}
			cout << text[j][i];
		}
	}
	
	
	return 0;
}