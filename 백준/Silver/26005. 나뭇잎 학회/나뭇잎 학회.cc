#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 1) cout << 0;
    else {
        if (N % 2 == 0) cout << (N * N)/2;
        else cout << (N * N) / 2 + 1;
    }
    return 0;
}