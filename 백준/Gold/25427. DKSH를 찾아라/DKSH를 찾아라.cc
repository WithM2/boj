#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    string input;
    cin >> input;

    ll h = 0, sh = 0, ksh = 0, dksh = 0;
    for (int i = input.length()-1; i >= 0; i--) {
        if (input[i] == 'H') h++;
        else if (input[i] == 'S') sh += h;
        else if (input[i] == 'K') ksh += sh;
        else if (input[i] == 'D') dksh += ksh;
    }

    cout << dksh;
	
	return 0;
}