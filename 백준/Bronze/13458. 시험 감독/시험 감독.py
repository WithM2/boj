import sys
input = sys.stdin.readline

n  = int(input())
people = list(map(int, input().split()))

main, sub = map(int, input().split())

ans = 0

for person in people :
    if main > person :
        ans += 1
        continue
    ans += ((person - main) // sub) + 1
    if (person - main) % sub != 0 :
        ans += 1 
        

print(ans)