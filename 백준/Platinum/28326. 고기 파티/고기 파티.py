n, m = map(int, input().split())
dish = [list(map(int, input().split())) for _ in range(n)]
people = [list(map(int, input().split())) for _ in range(m)]

for person in people:
    taste = 0
    for meat in dish:
        leftOK = (meat[0] <= person[0] < meat[1])
        rightOK = (meat[0] <= person[1] < meat[1])
        if leftOK or rightOK:
            if leftOK and rightOK:
                taste += meat[2]
            meat[0] = -1
            meat[1] = -1
    print(taste)
