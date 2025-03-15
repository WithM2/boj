#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int board[505][505];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //  1자블럭 가로
    if (m >= 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m-3; j++) {
                ans = max(ans, board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]);
            }
        }
    }
    //  1자블럭 세로
    if (n >= 4) {
        for (int i = 0; i < n-3; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]);
            }
        }
    }
    //  네모 블럭
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, board[i][j]+board[i][j+1]+board[i+1][j]+board[i+1][j+1]);
        }
    }
    //  6칸 중 2칸 구멍 가로 블록 (ㄴ, ㅗ, ㄹ 블럭)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            //  ㄴ
            ans = max(ans, board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+1][j+2]);
            ans = max(ans, board[i][j+1]+board[i+1][j]+board[i+1][j+1]+board[i+1][j+2]);
            ans = max(ans, board[i][j+2]+board[i+1][j]+board[i+1][j+1]+board[i+1][j+2]);
            //  ㅗ
            ans = max(ans, board[i+1][j]+board[i][j]+board[i][j+1]+board[i][j+2]);
            ans = max(ans, board[i+1][j+1]+board[i][j]+board[i][j+1]+board[i][j+2]);
            ans = max(ans, board[i+1][j+2]+board[i][j]+board[i][j+1]+board[i][j+2]);
            //  ㄹ
            ans = max(ans, board[i][j]+board[i][j+1]+board[i+1][j+1]+board[i+1][j+2]);
            ans = max(ans, board[i][j+1]+board[i][j+2]+board[i+1][j]+board[i+1][j+1]);
        }
    }
    //  6칸 중 2칸 구멍 세로 블록 (ㄴ, ㅗ, ㄹ 블럭)
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            //  ㄴ
            ans = max(ans, board[i][j]+board[i+1][j]+board[i+2][j]+board[i][j+1]);
            ans = max(ans, board[i][j]+board[i+1][j]+board[i+2][j]+board[i+1][j+1]);
            ans = max(ans, board[i][j]+board[i+1][j]+board[i+2][j]+board[i+2][j+1]);
            //  ㅗ
            ans = max(ans, board[i][j+1]+board[i+1][j+1]+board[i+2][j+1]+board[i][j]);
            ans = max(ans, board[i][j+1]+board[i+1][j+1]+board[i+2][j+1]+board[i+1][j]);
            ans = max(ans, board[i][j+1]+board[i+1][j+1]+board[i+2][j+1]+board[i+2][j]);
            //  ㄹ
            ans = max(ans, board[i][j]+board[i+1][j]+board[i+1][j+1]+board[i+2][j+1]);
            ans = max(ans, board[i][j+1]+board[i+1][j+1]+board[i+1][j]+board[i+2][j]);
        }
    }

    cout << ans;


    return 0;
}