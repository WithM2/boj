k, n = map(int, input().split())
a = [int(input()) for _ in range(k)]

start = 0
end = sum(a) // n

if end == 1 :
    print(1)
    exit()

while start <= end:
    now = (start + end) // 2
    cnt = 0
    for i in a:
        cnt += i // now
    
    if cnt < n :
        end = now - 1
    else :
        start = now + 1
    
print(end)