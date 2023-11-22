#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define MAX 1001

long long dist[MAX];
bool visited[MAX];
vector <pair<int, int>> graph[MAX];

void djikstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        long long cost = pq.top().first;
        long long now = pq.top().second;
        pq.pop();
    
        if (visited[now]) continue;
        visited[now] = true;
        
        for (int i = 0; i < graph[now].size(); i++) {
            long long next = graph[now][i].first;
            long long nCost = graph[now][i].second;
            if(cost + nCost < dist[next]) {
                dist[next] = cost + nCost;
                pq.push(make_pair(cost + nCost, next));
            }
        }
    }
}

int n, m;
int s, e;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    cin >> s >> e;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    djikstra(s);

    cout << dist[e] << "\n";

    return 0;
}