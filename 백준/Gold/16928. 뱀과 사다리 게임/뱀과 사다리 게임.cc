#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

int n, m;
int dx[6] = {1, 2, 3, 4, 5, 6};
int board[102] = {0};
bool vst[102];
queue<pii> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }

    q.push({1, 0});
    vst[1] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == 100) {
            cout << cnt;
            return 0;
        }

        if (board[now] != 0) {
            now = board[now];
        }

        for (int i = 0; i < 6; i++) {
            int next = now + dx[i];
            if (next <= 100 && !vst[next]) {
                vst[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }

    return 0;
}
