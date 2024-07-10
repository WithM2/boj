import sys
input = sys.stdin.readline

w, h = map(int, input().split())
area = w * h / 2
print(f"{area:.1f}")