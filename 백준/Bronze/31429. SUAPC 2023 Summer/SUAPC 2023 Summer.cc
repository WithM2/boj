#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> board;

int main() {
    board.push_back({12,1600});
    board.push_back({11,894});
    board.push_back({11,1327});
    board.push_back({10,1311});
    board.push_back({9,1004});
    board.push_back({9,1178});
    board.push_back({9,1357});
    board.push_back({8,837});
    board.push_back({7,1055});
    board.push_back({6,556});
    board.push_back({6,773});

    int n;
    cin >> n;
    cout << board[n-1].first << " " << board[n-1].second;

    return 0;
}