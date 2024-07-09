import sys
input = sys.stdin.readline

cost = int(input())
ans = 0 

if cost % 2 == 1 and cost < 5 :
    print(-1)
else :
    while cost >= 5 :
        cost -= 5
        ans += 1
    ans += cost // 2
    cost = cost % 2
    if cost != 0 :
        ans += 2
    print(ans)