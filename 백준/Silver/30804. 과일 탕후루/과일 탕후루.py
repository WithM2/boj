import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**6)

n = int(input())
tang = list(map(int, input().split()))
num = [0] * 10

def solve(start, end, max_num, kind) :
    global n

    if end == n :
        return max_num

    num[tang[end]] += 1
    if num[tang[end]] == 1 :
        kind += 1
    
    if kind > 2 :
        num[tang[start]] -= 1
        if num[tang[start]] == 0 :
            kind -= 1
        start += 1

    max_num = max(max_num, end - start + 1)
    
    return solve(start, end + 1, max_num, kind)

print(solve(0, 0, 0, 0))
