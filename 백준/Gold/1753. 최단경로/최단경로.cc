#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 200000
#define MAX 20001

long long dist[MAX];
vector <pair<int, int>> graph[MAX];

void djikstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        long long cost = pq.top().first;
        long long now = pq.top().second;
        pq.pop();
    
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

int v, e;
int k;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e;
    int k;
    cin >> k;

    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= v; i++) dist[i] = INF;
    djikstra(k);
    for (int i = 1; i <= v; i++) {
        if (dist[i] >= INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}