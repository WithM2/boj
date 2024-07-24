import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

n = [0] * 1601

for i in range(a) :
    for j in range(b) :
        for k in range(c) :
            n[i+j+k] += 1

print(n.index(max(n)) + 3)