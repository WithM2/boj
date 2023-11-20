#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1600000
#define MAX 801

int n, e;
long long dist[MAX];
vector <pair<int, int>> graph[MAX]; //도착지점, 시간
int a, b, c;
int p, q;

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

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> p >> q;

    long long ans1 = 0;
    long long ans2 = 0;

    for (int i = 1; i <= n; i++) dist[i] = INF;
    djikstra(1);
    if (dist[p] > INF) ans1 += INF;
    if (dist[q] > INF) ans2 += INF;
    ans1 += dist[p];
    ans2 += dist[q];

    for (int i = 1; i <= n; i++) dist[i] = INF;
    djikstra(p);
    if (dist[q] > INF) ans1 += INF;
    if (dist[n] > INF) ans2 += INF;
    ans1 += dist[q];
    ans2 += dist[n];

    for (int i = 1; i <= n; i++) dist[i] = INF;
    djikstra(q);
    if (dist[n] > INF) ans1 += INF;
    if (dist[p] > INF) ans2 += INF;
    ans1 += dist[n];
    ans2 += dist[p];

    if (ans1 > ans2) ans1 = ans2;

    if (ans1 >= INF) cout << -1;
    else cout << ans1;

    return 0;
}