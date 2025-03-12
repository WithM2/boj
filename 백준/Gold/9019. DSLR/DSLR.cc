#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;
bool visited[10001];

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int start, goal;
        cin >> start >> goal;
        queue <pair<int, string>> q;

        q.push({start, ""});
        visited[start] = true;

        while (!q.empty()) {
            int now = q.front().first;
            string ans = q.front().second;
            q.pop();

            if (now == goal) {
                cout << ans << "\n";
                break;
            }

            int D, S, L, R;
            
            //  D
            D = (now * 2) % 10000;
            if (!visited[D]) {
                visited[D] = true;
                q.push({D, ans + "D"});
            }

            //  S
            S = now == 0 ? 9999 : now - 1;
            if (!visited[S]) {
                visited[S] = true;
                q.push({S, ans + "S"});
            }

            //  L
            L = (now % 1000) * 10 + (now / 1000);
            if (!visited[L]) {
                visited[L] = true;
                q.push({L, ans + "L"});
            }

            //  R
            R = (now / 10) + (now % 10) * 1000;
            if (!visited[R]) {
                visited[R] = true;
                q.push({R, ans + "R"});
            }
        }

        memset(visited, false, sizeof(visited));
    }

    return 0;
}
