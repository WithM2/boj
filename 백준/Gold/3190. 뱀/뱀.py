import sys
input = sys.stdin.readline

from collections import deque

def show(board) :
    for x in range(len(board)) :
        for y in range(len(board[x])) :
            print(board[x][y], end = " ")
        print()

snake = deque()
snake.append([0, 0])
direction = deque([1, 2, 3, 4])     # right 1, down 2, left 3, up 4
menu = deque()
ans = 1

n = int(input())
k = int(input())
board = [[0]*n for _ in range(n)]
for _ in range(k) :
    x, y = map(int, input().split())
    board[x-1][y-1] = 1

# show(board)

l = int(input())
for _ in range(l) :
    t, dir = input().split()
    menu.append([int(t), dir])

x, y = 0, 0


if menu :
    time, turn = menu.popleft()
    
while True:
    if direction[0] == 1 :
        nx, ny = x, y+1
    elif direction[0] == 2 :
        nx, ny = x+1, y
    elif direction[0] == 3 :
        nx, ny = x, y-1
    elif direction[0] == 4 :
        nx, ny = x-1, y
    
    if nx > n-1 or ny > n-1 or nx < 0 or ny < 0 or [nx, ny] in snake :
        break
    
    snake.appendleft([nx, ny])
    if not board[nx][ny]:
        snake.pop()
    else :
        board[nx][ny] = 0
    
    # print("snake : ", snake)
    
    x, y = nx, ny

    if ans == time :
        if turn == 'D' :
            direction.rotate(-1)
        else :
            direction.rotate(1)
        if menu :
            time, turn = menu.popleft()
        else :
            time, turn = None, None
    
    ans += 1
      
print(ans)