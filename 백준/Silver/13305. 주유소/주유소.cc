#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll road[100001];
ll cost[100001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) cin >> road[i];
	for (int i = 1; i <= n; i++) cin >> cost[i];

	ll oil = cost[1];
	ll pay = 0;
	for (int i = 1; i < n; i++) {
		pay += oil * road[i];
		oil = min(oil, cost[i+1]);
	}

	cout << pay;

	return 0;
}