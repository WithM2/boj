import sys
input = sys.stdin.readline

n = int(input())

input = str(input().strip())
balls = [ball for ball in input]

cntB = 0
cntR = 0

ans = 500001
test = 0

for ball in balls :
    if ball == 'B' :
        cntB += 1
    else :
        cntR += 1

# gather B left
cnt = 0
for ball in balls :
    if ball == 'R' :
        ans = min(ans, cntB-cnt)
        test = 1
        break
    else :
        cnt += 1

# gather R left
cnt = 0
for ball in balls :
    if ball == 'B' :
        ans = min(ans, cntR-cnt)
        test = 2 
        break
    else :
        cnt += 1

# gather B right
cnt = 0
for i in range(n-1, -1, -1) :
    if balls[i] == 'R' :
        ans = min(ans, cntB-cnt)
        test = 3
        break
    else :
        cnt += 1

# gather R right
cnt = 0
for i in range(n-1, -1, -1) :
    # print(f"i : {i}")
    if balls[i] == 'B' :
        ans = min(ans, cntR-cnt)
        test = 4
        # print(f"cntR : {cntR}, cnt : {cnt}")
        break
    else :
        cnt += 1
        
print(ans)
# print(test)