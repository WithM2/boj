b = int(input())
for i in range(b):
    n, m, k, d = map(int, input().split())
    a = m * n // 2 * ((m - 1) * k + (n - 1) * m)
    if d < a:
        print("-1")
    else:
        print(d - d % a)
