#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);

int n;
vector<pair<int, string>> people;

bool cmp(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        people.push_back({age, name});
    }    

    stable_sort(people.begin(), people.end(), cmp);
    
    for (auto person : people) {
        cout << person.first << " "
            << person.second << endl;
    }



    return 0;
}