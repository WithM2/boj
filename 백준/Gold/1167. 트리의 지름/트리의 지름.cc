#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[100001];

bool visited[100001];
int mx = 0;
int best = 1;

void dfs(int node, int val) {
    
    visited[node] = true;
    if (mx < val) {
        mx = val;
        best = node;
    }

    for (int i=0; i< graph[node].size(); i++) {
        int next = graph[node][i].first;
        int nextval = graph[node][i].second;
        if (!visited[next]) dfs(next, nextval+val);
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        while(1) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            graph[a].push_back(make_pair(b, c));
        }
    }

    dfs(1, 0);
    mx = 0;
    for (int i = 0; i < n; i++) {
        visited[i+1] = false;
    }
    dfs(best, 0);

    cout << mx;
    
    return 0;
}