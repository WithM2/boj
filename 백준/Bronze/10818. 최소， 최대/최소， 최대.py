a = int(input())

b = list(map(int,input().split()))

min = 1000001
max = -1000001

for i in b:
    if min>i:
        min = i
    if max<i:
        max = i
print(min,max)