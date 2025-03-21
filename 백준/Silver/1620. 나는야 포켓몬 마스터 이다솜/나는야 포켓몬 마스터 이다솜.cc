#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string>pokenums;
	map<string, int>pokemons;
	int N, M;
	cin >> N >> M;
	
	string pokemon;
	for(int i=0; i<N; i++) {
		cin >> pokemon;
		pokenums.push_back(pokemon);
		pokemons.insert(make_pair(pokemon, (i+1)));
	}
	
	string find;
	for(int i=0; i<M; i++) {
		cin >> find;
		if(find[0] >= '0' && find[0] <= '9') {
			cout << pokenums[stoi(find)-1] << "\n";
		}
		else {
			cout << pokemons[find] << "\n";
		}
	}
	
	return 0;
}



