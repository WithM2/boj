#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100001
#define INF 10000000

using namespace std;

long long dist[MAX];
bool visited[MAX];
int n, k;

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

        if (now + 1 <= MAX) {
            pq.push(make_pair(cost + 1, now+1));
            if (cost + 1 < dist[now+1]) {
                dist[now+1] = cost + 1;
            }
        }
        if (now - 1 >= 0) {
            pq.push(make_pair(cost + 1, now-1));
            if (cost + 1 < dist[now-1]) {
                dist[now-1] = cost + 1;
            }
        }
        if (now*2 <= MAX) {
            pq.push(make_pair(cost, now*2));
            if (cost < dist[now*2]) {
                dist[now*2] = cost;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    djikstra(n);
    cout << dist[k];


    

    return 0;
}