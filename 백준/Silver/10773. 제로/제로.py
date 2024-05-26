k = int(input())

a = []

for i in range(k):
    b = int(input())
    if b == 0:
        if a:  # 리스트가 비어있지 않으면
            a.pop()  # 마지막 요소 제거
    else:
        a.append(b)

c = sum(a)  # 리스트의 합 계산

print(c)
