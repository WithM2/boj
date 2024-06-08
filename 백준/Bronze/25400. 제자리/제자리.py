n = int(input())

a = map(int, input().split())

k = 1
ans = 0

for i in a:
    if i == k:
        k += 1
    else :
        ans += 1

print(ans)