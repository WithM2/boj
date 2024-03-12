#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 676

using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;
int num = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans[MAX];

void check(int x, int y) {
    ans[num]++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (map[nx][ny] == 0) continue;
        if (visited[nx][ny]) continue;
        if (map[nx][ny] == 1) {
            visited[nx][ny] = true;
            check(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++) {
            map[i][j] = str[j-1] - '0';
            if (map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y]) continue;
        num++;
        check(x, y);

    }

    sort(ans+1, ans + num+1);
    cout << num << '\n';
    for (int i = 1; i <= num; i++) {
        cout << ans[i] << '\n';
    }





    

    return 0;
}
    