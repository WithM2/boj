#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 101

using namespace std;

int map[MAX][MAX];
bool visit[MAX][MAX];
int n, m;
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            map[i][j] = str[j-1] - '0';
        }
    }
    q.push({1, 1});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x == n && y == m) {
            cout << map[x][y];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (map[nx][ny] == 0) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] == 1) {
                q.push({nx, ny});
                map[nx][ny] = map[x][y] + 1;
            }
        }
    }
    return 0;
}
    