#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> graph[105];
queue<int> q;
bool visited[105];
int ans = 0;

int main(){
    fastio;
    int n; cin >> n;
    int nodes; cin >> nodes;

    for (int i = 0; i < nodes; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    q.push(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        ans++;
        visited[now] = true;
        for (auto i : graph[now]) {
            if(visited[i]) continue;
            q.push(i);
        }
    }

    cout << ans-1;

    return 0;
}