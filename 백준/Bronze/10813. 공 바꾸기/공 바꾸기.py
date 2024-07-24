import sys
input = sys.stdin.readline

n, m = map(int, input().split())

balls = [i for i in range(1, n+1)]

def swap(a:list):
    tmp = a[0]
    a[0] = a[1]
    a[1] = tmp
    return a

for _ in range(m):
    a, b = map(int, input().split())
    swapped = swap([balls[a-1], balls[b-1]])
    balls[a-1] = swapped[0]
    balls[b-1] = swapped[1]

for _ in range(n):
    print(balls[_], end=' ')