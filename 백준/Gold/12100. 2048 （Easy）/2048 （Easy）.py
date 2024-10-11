import sys
input = sys.stdin.readline

from collections import deque

def push_up(map, n) :
    new = [map[i][:] for i in range(n)]
    for y in range(n) :
        end = 0
        for x in range(1, n):
            if new[x][y] :
                tmp = new[x][y]
                new[x][y] = 0
                if not new[end][y] :
                    new[end][y] = tmp
                elif new[end][y] == tmp :
                    new[end][y] *= 2
                    end += 1
                else :
                    end += 1
                    new[end][y] = tmp
    return new

def push_down(map, n) :
    new = [map[i][:] for i in range(n)]
    for y in range(n) :
        end = n-1
        for x in range(n-2, -1, -1):
            if new[x][y] :
                tmp = new[x][y]
                new[x][y] = 0
                if not new[end][y] :
                    new[end][y] = tmp
                elif new[end][y] == tmp :
                    new[end][y] *= 2
                    end -= 1
                else :
                    end -= 1
                    new[end][y] = tmp
    return new

def push_left(map, n) :
    new = [map[i][:] for i in range(n)]
    for x in range(n) :
        end = 0
        for y in range(1, n):
            if new[x][y] :
                tmp = new[x][y]
                new[x][y] = 0
                if not new[x][end] :
                    new[x][end] = tmp
                elif new[x][end] == tmp :
                    new[x][end] *= 2
                    end += 1
                else :
                    end += 1
                    new[x][end] = tmp
    return new

def push_right(map, n) :
    new = [map[i][:] for i in range(n)]
    for x in range(n) :
        end = n-1
        for y in range(n-2, -1, -1):
            if new[x][y] :
                tmp = new[x][y]
                new[x][y] = 0
                if not new[x][end] :
                    new[x][end] = tmp
                elif new[x][end] == tmp :
                    new[x][end] *= 2
                    end -= 1
                else :
                    end -= 1
                    new[x][end] = tmp
    return new


def print_map(map) :
    for line in map :
        for num in line :
            print(num, end = " ")
        print()

def dfs(map, cnt) :
    global answer
    if cnt == 5 :
        for i in range(n) :
            answer = max(answer, max(map[i]))
        return
    
    dfs(push_down(map, n), cnt+1)
    dfs(push_up(map, n), cnt+1)
    dfs(push_left(map, n), cnt+1)
    dfs(push_right(map, n), cnt+1)


n = int(input())

MAP = [list(map(int, input().split())) for _ in range(n)]


if n == 1 :
    print(MAP[0][0])
    exit()

answer = 0

dfs(MAP, 0)
print(answer)
