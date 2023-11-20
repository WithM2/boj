#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q;
queue<pair<int, int>> cheese;
int cnt = 0;
int time = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void spread(int x, int y) {
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visit[x][y]) continue;
        visit[x][y] = true;
        map[x][y] = 2;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if (map[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                cheese.push(make_pair(i, j));
                cnt++;
            }
        }
    }

    spread(0, 0);

    while(cnt) {
        int tmp = cnt;
        for (int i = 0; i < tmp; i++) {
            int x = cheese.front().first;
            int y = cheese.front().second;
            cheese.pop();

            int chk = 0;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
                if (map[nx][ny] == 2) {
                    chk++;
                }
            }
            if (chk >= 2) {
                q.push(make_pair(x, y));
                cnt--;
            }
            else cheese.push(make_pair(x, y));
        }
        time++;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            map[x][y] = 2;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
                if (map[nx][ny] == 0) {
                    spread(nx, ny);
                }
            }
        }
    }

    cout << time;

    return 0;
}   