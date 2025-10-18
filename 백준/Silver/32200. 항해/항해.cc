#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n, x, y;
vector<int> toast;
int ans, trash;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x >> y;
    int diff = y - x;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        toast.push_back(tmp);
    }

    for (int piece : toast) {
        if (piece < x) {
            trash += piece;
        }
        else {
            int food = piece / x;
            ans += food;
            int left = piece % x;
            for (int i = 0; i < food; i++) {
                if (left <= diff) {
                    left = 0;
                    break;
                }
                left -= diff;
            }
            trash += left;
            // cout << "ans add " << food << ", trash add " << left << endl;
        }
    }

    cout << ans << "\n" << trash;


    
    return 0;
}