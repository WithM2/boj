import sys
input = sys.stdin.readline

n = int(input())
stolen = [str(input()) for _ in range(n)]

m = int(input())
check = [str(input()) for _ in range(m)]

stolen = set(stolen)

ans = 0

for i in check :
    if i in stolen :
        ans += 1
        
print(ans)