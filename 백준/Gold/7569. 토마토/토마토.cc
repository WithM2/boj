#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 101
using namespace std;

int m, n, h;
int graph[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
queue <pair<pii, pii>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> h;

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cin >> graph[x][y][z];
                if (graph[x][y][z] == 1) {
                    q.push({{x, y}, {z, 0}});
                    visited[x][y][z] = true;
                }
            }
        }
    }

    int day = 0;
    int dx[6] = {1, 0, 0, -1, 0, 0};
    int dy[6] = {0, 1, 0, 0, -1, 0};
    int dz[6] = {0, 0, 1, 0, 0, -1};

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int x = front.first.first;
        int y = front.first.second;
        int z = front.second.first;
        int d = front.second.second;
        day = d;

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (!visited[nx][ny][nz] && graph[nx][ny][nz] == 0) {
                visited[nx][ny][nz] = true;
                graph[nx][ny][nz] = 1;
                q.push({{nx, ny}, {nz, d+1}});
            }
        }
    }

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (graph[x][y][z] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << day;
    return 0;
}
