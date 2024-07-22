n = int(input())

cnt = 0
top = 0

stack = [int(input()) for _ in range(n)]

for _ in range(n) :
    now = stack.pop()
    if now > top :
        cnt += 1
        top = now

print(cnt)