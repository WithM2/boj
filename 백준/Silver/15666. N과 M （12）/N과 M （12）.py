import sys
input = sys.stdin.readline

def backtracking(depth) :
    if depth == m :
        print(" ".join(map(str, arr)))
        return
    
    for i in range(len(numbers)) :
        if depth == 0 or arr[-1] <= numbers[i] :
            arr.append(numbers[i])
            backtracking(depth + 1)
            arr.pop()
        

n, m = map(int, input().split())
numbers = list(set(map(int, input().split())))
numbers.sort()
arr = []

backtracking(0)