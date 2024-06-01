n = int(input())

cnt = 0

for i in range(1, n):
    for j in range(i, n):
        k = n - i - j
        if k < j:
            break
        if i + j > k:
            cnt += 1

print(cnt)