#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n;
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.push(num);
    }

    int now = 0;
    int top = 0;
    int count = 0;

    while (!s.empty()) {
        top = s.top();
        s.pop();

        if (top > now) {
            now = top;
            count++;
        }
    }

    cout << count;

    return 0;
}
    