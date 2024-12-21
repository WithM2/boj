#include <iostream>
#include <vector>
using namespace std;

vector<int> card;

int n;
int now = 1;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    card.push_back(0);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    
    for (int i = 1; i <= n; i++) {
        if (card[i] == now) {
            now++;    
        }
        else {
            ans++;
        }
    }

    cout << ans;


    return 0;
}