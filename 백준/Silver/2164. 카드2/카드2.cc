#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    queue<int> card;
    
    for (int i = 0; i < n; i++) {
        card.push(i+1);
    }
    
    while (card.size() != 1) {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    
    cout << card.front();
    
    return 0;
}
