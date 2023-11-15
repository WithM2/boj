#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1000000
#define MAX 1001

int n, m, x;
int dist[MAX];
int ans[MAX];
vector <pair<int, int>> graph[MAX]; //도착지점, 시간
int s, e, t;

void djikstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int nCost = graph[now][i].second;
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

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        graph[s].push_back(make_pair(e, t));
    }

    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[j] = INF;
        }
        djikstra(i);
        ans[i] = dist[x];
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    djikstra(x);

    for (int i = 1; i <= n; i++) {
        ans[i] += dist[i];
    }

    cout << *max_element(ans+1, ans+1+n);

    return 0;
}