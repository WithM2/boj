#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> home;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        home.push_back({x, y});
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (k > 1) {
            for (int j = i+1; j < n; j++) {
                if (k > 2) {
                    for (int k = j+1; k < n; k++) {
                        int max_dist = 0;
                        for (int x = 0; x < n; x++) {
                            int min_dist = INT_MAX;
                            min_dist = min(min_dist, abs(home[i].first - home[x].first) + abs(home[i].second - home[x].second));
                            min_dist = min(min_dist, abs(home[j].first - home[x].first) + abs(home[j].second - home[x].second));
                            min_dist = min(min_dist, abs(home[k].first - home[x].first) + abs(home[k].second - home[x].second));
                            max_dist = max(max_dist, min_dist);
                        }
                    }
                }
                else {
                    int max_dist = 0;
                    for (int x = 0; x < n; x++) {
                        int min_dist = INT_MAX;
                        min_dist = min(min_dist, abs(home[i].first - home[x].first) + abs(home[i].second - home[x].second));
                        min_dist = min(min_dist, abs(home[j].first - home[x].first) + abs(home[j].second - home[x].second));
                        max_dist = max(max_dist, min_dist);
                    }
                    ans = min(max_dist, ans);
                }
            }
        }
        else {
            int max_dist = 0;
            for (int x = 0; x < n; x++) {
                int min_dist = INT_MAX;
                min_dist = min(min_dist, abs(home[i].first - home[x].first) + abs(home[i].second - home[x].second));
                max_dist = max(max_dist, min_dist);
            }
            ans = min(max_dist, ans);
        }
    }

    cout << ans;


    return 0;
}