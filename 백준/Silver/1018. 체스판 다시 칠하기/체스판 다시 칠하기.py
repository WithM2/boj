n, m = map(int, input().split())
chess = [input() for _ in range(n)]

blackChessBoard = [
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB'
]

whiteChessBoard = [
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW'
]

ans = 32

for i in range(n - 8 + 1):
    for j in range(m - 8 + 1):
        cntBlack = 0
        cntWhite = 0
        for x in range(8):
            for y in range(8):
                if chess[i+x][j+y] != blackChessBoard[y][x]:
                    cntWhite += 1
                if chess[i+x][j+y] != whiteChessBoard[y][x]:
                    cntBlack += 1
        if min(cntBlack, cntWhite) < ans:
            ans = min(cntBlack, cntWhite)

print(ans)
        


