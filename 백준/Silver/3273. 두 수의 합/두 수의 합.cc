#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, target;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> target;

  sort(a.begin(), a.end());

  long long ans = 0;
  int l = 0, r = n - 1;
  while (l < r) {
    long long sum = (long long)a[l] + a[r];
    if (sum == target) {
      ans++;
      l++;
      r--;
    } else if (sum < target) {
      l++;
    } else {
      r--;
    }
  }

  cout << ans << '\n';
  return 0;
}
