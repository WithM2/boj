import sys
input = sys.stdin.readline

dice = {"top": 0, "bottom": 0, "front": 0, "left": 0, "back": 0, "right": 0}

n, m, x, y, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
menu = list(map(int, input().split()))

for task in menu :
    if task == 1 :
        nx, ny = x, y+1
        if nx > n-1 or ny > m-1 or nx < 0 or ny < 0 :
            continue
        tmp = dice["bottom"]
        dice["bottom"] = dice["right"]
        dice["right"] = dice["top"]
        dice["top"] = dice["left"]
        dice["left"] = tmp
    
    if task == 2 :
        nx, ny = x, y-1
        if nx > n-1 or ny > m-1 or nx < 0 or ny < 0 :
            continue
        tmp = dice["bottom"]
        dice["bottom"] = dice["left"]
        dice["left"] = dice["top"]
        dice["top"] = dice["right"]
        dice["right"] = tmp
        
    if task == 3 :
        nx, ny = x-1, y
        if nx > n-1 or ny > m-1 or nx < 0 or ny < 0 :
            continue
        tmp = dice["bottom"]
        dice["bottom"] = dice["back"]
        dice["back"] = dice["top"]
        dice["top"] = dice["front"]
        dice["front"] = tmp
        
    if task == 4 :
        nx, ny = x+1, y
        if nx > n-1 or ny > m-1 or nx < 0 or ny < 0 :
            continue
        tmp = dice["bottom"]
        dice["bottom"] = dice["front"]
        dice["front"] = dice["top"]
        dice["top"] = dice["back"]
        dice["back"] = tmp
        
    print(dice["top"])
        
    if board[nx][ny] == 0 :
        board[nx][ny] = dice["bottom"]
    else :
        dice["bottom"] = board[nx][ny]
        board[nx][ny] = 0
    
    x, y = nx, ny
        