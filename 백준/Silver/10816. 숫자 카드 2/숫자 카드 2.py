n = int(input())

a = {}
b = list(map(int, input().split()))

for i in range(n):
    if b[i] in a:
        a[b[i]] += 1
    else :
        a[b[i]] = 1

m = int(input())
c = list(map(int, input().split()))

for i in range(m):
    if c[i] in a:
        print(a[c[i]], end=' ')
    else :
        print(0, end=' ')

