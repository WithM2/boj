#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 601

using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
            if (map[i][j] == 'I') {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int cnt = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'X' || visited[nx][ny]) continue;
            if (map[nx][ny] == 'P') {
                cnt++;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    if (cnt == 0) cout << "TT";
    else cout << cnt;



    return 0;
}
    