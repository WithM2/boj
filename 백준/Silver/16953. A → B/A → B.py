from collections import deque

a, b = map(int, input().split())

visited = set()
visited.add(a)

queue = deque()
queue.append((a, 0))

while queue :
    now = queue.popleft()
    if now[0] == b :
        print(now[1]+1)
        exit(0)
    else :
        if now[0] >= 500000000 :
            continue
        elif now[0] * 2 not in visited :
            queue.append((now[0] * 2, now[1] + 1))
            visited.add(now[0] * 2)
        if now[0] >= 100000000 :
            continue
        elif now[0] * 10 + 1 not in visited :
            queue.append((now[0] * 10 + 1, now[1] + 1))
            visited.add(now[0] * 10 + 1)

print(-1)