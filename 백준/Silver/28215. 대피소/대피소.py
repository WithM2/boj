import sys
input = sys.stdin.readline

n, K = map(int, input().split())

home = [list(map(int, input().split())) for _ in range(n)]

ans = sys.maxsize

for i in range(n):
    if K > 1 :
        for j in range(i+1, n):
            # print(f"i is {i}, j is {j}")
            if K > 2:
                for k in range(j+1, n):
                    max_dist = 0
                    for x in range(n):
                        min_dist = sys.maxsize
                        min_dist = min(min_dist, abs(home[i][0] - home[x][0]) + abs(home[i][1] - home[x][1]))
                        min_dist = min(min_dist, abs(home[j][0] - home[x][0]) + abs(home[j][1] - home[x][1]))
                        min_dist = min(min_dist, abs(home[k][0] - home[x][0]) + abs(home[k][1] - home[x][1]))
                        max_dist = max(max_dist, min_dist)
                    ans = min(max_dist, ans)
            else :
                max_dist = 0
                for x in range(n):
                    min_dist = sys.maxsize
                    min_dist = min(min_dist, abs(home[i][0] - home[x][0]) + abs(home[i][1] - home[x][1]))
                    min_dist = min(min_dist, abs(home[j][0] - home[x][0]) + abs(home[j][1] - home[x][1]))
                    max_dist = max(max_dist, min_dist)
                ans = min(max_dist, ans)
                    
                    # print(f"x is {x}")
                    # # print(f"max_dist: {max_dist}")
                    # print(f"min_dist: {min_dist}")
                    # print()

    else :
        max_dist = 0
        for x in range(n): 
            min_dist = sys.maxsize
            min_dist = min(min_dist, abs(home[i][0] - home[x][0]) + abs(home[i][1] - home[x][1]))
            max_dist = max(max_dist, min_dist)
        ans = min(max_dist, ans)
    

print(ans)