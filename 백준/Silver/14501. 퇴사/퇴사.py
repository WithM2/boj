import sys
input = sys.stdin.readline

from collections import deque

worktime = deque()
pay = deque()
n = int(input())
ev = [0] * (n+1)

worktime.append(0)
pay.append(0)

for _ in range(n):
    day, money = map(int, input().split())
    worktime.append(day)
    pay.append(money)

for day in range(1, n+1) :
    if day + (worktime[day]-1) > n :
        continue
    if ev[day+worktime[day]-1] < max(ev[:day]) + pay[day] :
        ev[day+worktime[day]-1] = max(ev[:day]) + pay[day]



print(max(ev))
# print(ev)
