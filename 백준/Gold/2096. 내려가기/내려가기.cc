#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 3

int dpmax[MAX], dpmin[MAX], tmpdpmax[MAX], tmpdpmin[MAX];
int n;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < 3; i++) {
        dpmax[i] = 0;
        dpmin[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = 0; j < 3; j++) {
            tmpdpmax[j] = dpmax[j];
            tmpdpmin[j] = dpmin[j];
        }

        dpmax[0] = max(tmpdpmax[0], tmpdpmax[1]) + a;
        dpmax[1] = max(tmpdpmax[0], max(tmpdpmax[1], tmpdpmax[2])) + b;
        dpmax[2] = max(tmpdpmax[1], tmpdpmax[2]) + c;

        dpmin[0] = min(tmpdpmin[0], tmpdpmin[1]) + a;
        dpmin[1] = min(tmpdpmin[0], min(tmpdpmin[1], tmpdpmin[2])) + b;
        dpmin[2] = min(tmpdpmin[1], tmpdpmin[2]) + c;
    }

    cout << max(dpmax[0], max(dpmax[1], dpmax[2])) << " " << min(dpmin[0], min(dpmin[1], dpmin[2]));
    

    return 0;
}