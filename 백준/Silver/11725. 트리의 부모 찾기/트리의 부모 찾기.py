import sys
input = sys.stdin.readline

from collections import deque

n  = int(input())

tree = [[] for _ in range(n+1)]
parent = [0] * (n+1)
parent[1] = 1

for i in range(n-1) :
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

q = deque()
q.append(1)

while q :
    start = q.popleft()
    for child in tree[start] :
        if not parent[child]:
            parent[child] = start
            q.append(child)

for i in range(2, n+1) :
    print(parent[i])
