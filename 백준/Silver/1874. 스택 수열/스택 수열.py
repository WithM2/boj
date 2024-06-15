from collections import deque

q = deque()
ans = []

n = int(input())

i = 1
for j in range(n):
    num = int(input())
    if i <= num:
        while i <= num:
            q.append(i)
            ans.append('+')
            i += 1
        q.pop()
        ans.append('-')
    else :
        if q[-1] != num:
            print('NO')
            exit()
        else :
            ans.append('-')
            q.pop()

for i in ans:
    print(i)
    