#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[10005];
vector<int> ans;
bool visited[10005];

int dfs(int now) {
    int cnt = 1;
    visited[now] = true;

    for (int child : graph[now]) {
        if (!visited[child]) {
            cnt += dfs(child);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> end >> start;
        graph[start].push_back(end);
    }

    int maxCnt = 0;

    for (int i = 1; i <= n; i++) {
        if (graph[i].empty()) continue;
        for (int j = 0; j <= n; j++) {
            visited[j] = false;
        }
        int cnt = dfs(i);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans.clear();
            ans.push_back(i);
        } else if (cnt == maxCnt) {
            ans.push_back(i);
        }
    }

    for (int answer : ans) {
        cout << answer << " ";
    }
    

    return 0;
}