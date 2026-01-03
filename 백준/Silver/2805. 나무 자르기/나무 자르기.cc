#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
long long n, m;

long long find_sum(long long k){
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        if(arr[i] > k) sum += (arr[i] - k);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);
    for(long long i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long start = 0;
    long long end = arr[n-1];
    long long ans = 0;

    while(start <= end){
        long long mid = (start + end) / 2;
        long long a = find_sum(mid);

        if(a >= m){
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans;
}
