#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k, n;
    long long start = 1, end, mid, sum = 0, total, max = -1;
    cin >> k >> n;

    vector<int> length;

    for(int i = 0 ; i < k ; i++){
        int tmp;
        cin >> tmp;
        length.push_back(tmp);
        sum += tmp;
    }

    end = sum / n;

    while(start <= end){
        total = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < k ; i++){
            total += length[i] / mid;
        }

        if(total >= n){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else{
            end = mid - 1;
        }
    }

    cout << max;
    
    return 0;
}