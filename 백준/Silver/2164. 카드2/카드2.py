from collections import deque

n = int(input())
a = deque([i for i in range(1, n + 1)])

while len(a) != 1:
    a.popleft()
    a.rotate(-1)

print(a[0])