#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n, m;
vector<pair<int, pii>> graph;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void uni(vector<int>& parent, vector<int>& rank, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;   cin >> m;
    
    int start, end, cost;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        graph.push_back({cost, {start, end}});
    }    
    sort(graph.begin(), graph.end());
    
    vector<int> parent(n+1), rank(n+1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int mstCost = 0;

    for (auto edge : graph) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(parent, u) != find(parent, v)) {
            uni(parent, rank, u, v);
            mstCost += cost;
        }

    }
    cout << mstCost;
    
    return 0;
}