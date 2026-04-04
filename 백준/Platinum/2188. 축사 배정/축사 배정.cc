#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 205

int n, m;
int room[MAX];
vector<int> graph[MAX];
bool visited[MAX];
int ans;

bool dfs(int start) {
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++) {
        int to = graph[start][i];
        if (room[to] == -1 ||
                (!visited[room[to]] && dfs(room[to]))) {
            // cow[start] = to;
            room[to] = start;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        while(num--) {
            int to; cin >> to;
            graph[i].push_back(to);
        }
    }

    // fill(&cow[1], &cow[MAX], -1);
    fill(&room[1], &room[MAX], -1);

    for (int i = 1; i <= n; i++) {
        fill(&visited[1], &visited[n+1], false);
        if (dfs(i)) ans++;
        // if (cow[i] == -1) {
        // }
    }

    cout << ans;


    return 0;
}