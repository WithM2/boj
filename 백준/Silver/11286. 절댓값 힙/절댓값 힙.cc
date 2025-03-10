#include <bits/stdc++.h>

using namespace std;

int n;

struct cmp {
    bool operator()(int x, int y) {
        if (abs(x) == abs(y)) return x > y;
        else return abs(x) > abs(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, cmp> pq;
    
    cin >> n;
    while(n--) {
        int tmp;
        cin >> tmp;
        if (tmp != 0) {
            pq.push(tmp);
        }
        else {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}