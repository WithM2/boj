#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

bool visited_dfs[1001];

void dfs(vector<vector<int>> graph, int current) {
    visited_dfs[current] = true;
    for (int next : graph[current]) {
        if (!visited_dfs[next]) {
            cout << next << " ";
            dfs(graph, next);
        }
    }
}

queue<int> q;
bool visited_bfs[1001];
void bfs(vector<vector<int>> graph, int source) {
    q.push(source);
    visited_bfs[source] = true;
    while(!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int next : graph[current]) {
            if(!visited_bfs[next]) {
                q.push(next);
                visited_bfs[next] = true;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, v;
    cin>>n>>m>>v;
    
    vector<vector<int>> g;
    for (int i = 0; i <= n; i++) {
        vector<int> tmp;
        int a = 0;
        g.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 0; i < g.size(); i++) {
        sort(g[i].begin(), g[i].end());
    }
    
    cout << v << " ";
    dfs(g, v);
    
    cout << "\n";
    
    bfs(g, v);
    
    
    return 0;
}











