#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int h[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> h[i];
        sum += h[i];
    }

    sort(h, h+9);

    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if (sum - h[i] - h[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    cout << h[k] << "\n";
                }
                return 0;
            }
        }
    }
    

    return 0;
}

