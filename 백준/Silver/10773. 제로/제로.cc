#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int sum = 0;
    int n;
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            s.pop();
        } else {
            s.push(num);
        }
    }
    n = s.size();
    for (int i = 0; i < n; i++) {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}
    