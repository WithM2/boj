for _ in range(int(input())):
    k, n = int(input()), int(input())
    a = [i for i in range(1, n+1)]
    for _ in range(k):
        for j in range(1, n):
            a[j] += a[j-1]
    print(a[-1])