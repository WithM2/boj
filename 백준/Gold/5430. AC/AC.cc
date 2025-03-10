#include <bits/stdc++.h>

using namespace std;

int testcase;

void func() {
    string p, tmp;
    int n;
    deque<int> dq;
    cin >> p;
    cin >> n;
    cin >> tmp;
    int len = n*2 - 1;
    int tmp_sum = 0;
    if (tmp.length() == 2) tmp = "";
    for (int i = 1; i < tmp.length(); i++) {
        if (tmp[i] == ',' || tmp[i] == ']') {
            dq.push_back(tmp_sum);
            tmp_sum = 0;
        }
        else {
            tmp_sum *= 10;
            tmp_sum += tmp[i]-'0';
        }
    }

    bool direction = true;  // true : -> / false : <-

    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'R') {
            direction = !direction;
        }
        else {  // p[i] =='D'
            if (dq.empty()) {
                cout << "error\n";
                return;
            }
            if(!direction) dq.pop_back();
            else dq.pop_front();
        }
    }

    cout << "[";
    if (direction) {
        for (int i = 0 ; i < dq.size(); i++) {
            cout << dq[i];
            if (i == dq.size() - 1) cout << "]\n";
            else cout << ",";
        }
    }
    else {
        for (int i = dq.size() - 1; i >= 0; i--) {
            cout << dq[i];
            if (i == 0) cout << "]\n";
            else cout << ",";
        }
    }

    if (dq.size() == 0) cout << "]\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> testcase;
    while(testcase--) {
        func();
    }

    return 0;
}