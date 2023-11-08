#include <stdio.h>
#include <queue>

using namespace std;

#define X first
#define Y second

int day = 0;
int map[1002][1002] = {0};
int visit[1002][1002] = {0};

int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    queue<pair<int, int>> q;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = q.front().X+dx[i];
            int ny = q.front().Y+dy[i];
            
            if(nx<1 || ny<1 || nx>m || ny>n) continue;
            if(map[nx][ny] == -1 || visit[nx][ny]>0 || map[nx][ny]==1) continue;

            visit[nx][ny] = visit[q.front().X][q.front().Y] + 1;
            day = visit[nx][ny];
            q.push(make_pair(nx, ny));
        }
        q.pop();
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!map[i][j] && !visit[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", day);

    return 0;
}