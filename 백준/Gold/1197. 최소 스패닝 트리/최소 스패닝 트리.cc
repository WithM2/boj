#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int v,e;
// cost, node
vector <pair<int,int>> gr[10005];
bool visited[10005];
int prim(int start){
    visited[start] = true;
    //  cost, node
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int sum = 0;

    for (auto i : gr[start]) pq.push(i);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (visited[now]) continue;
        sum += cost;
        for (auto i : gr[now]) {
            if (visited[i.second]) continue;
            pq.push(i);
        }
        visited[now] = true;
    }
    return sum;
}
int main(){
    fastio;
    cin>>v>>e;
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back({c,b});
        gr[b].push_back({c,a});
    }
    cout<<prim(1);
    return 0;
}