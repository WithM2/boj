import sys
input = sys.stdin.readline

def show(board) :
    for x in range(len(board)) :
        for y in range(len(board[x])) :
            print(board[x][y], end = " ")
        print()

n, m = map(int, input().split())

board = [[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1) :
    tmp = list(map(int, input().split()))
    for j in range(n) :
        board[i][j+1] = board[i][j] + tmp[j]

for Testcase in range(m):
    ans = 0
    x1, y1, x2, y2 = map(int, input().split())
    
    for x in range(x1, x2+1):
        ans += board[x][y2] - board[x][y1-1]
    print(ans)