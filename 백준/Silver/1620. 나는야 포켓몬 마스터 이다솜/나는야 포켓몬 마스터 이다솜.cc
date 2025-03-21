#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define endl "\n"

using namespace std;

int n, m;

vector<string> num2pocket;
map<string, string> pokcet2num;

bool isNumber(const string& str) {
    if(str[0]>='A' && str[0] <= 'Z'){
        return false;
    }
    return !str.empty();
}

int main(void){
    fastio;
    cin>>n>>m;
    rep(i, 1, n+1){
        string tmp;
        cin>>tmp;
        num2pocket.push_back(tmp);
        pokcet2num[tmp] = to_string(i);
    }
    while(m--){
        string tmp;
        cin>>tmp;
        if (isNumber(tmp)){
            
            cout<<num2pocket[stoi(tmp) - 1]<<endl;
        }
        else{
            cout<<pokcet2num[tmp]<<endl;
        }
    }
}