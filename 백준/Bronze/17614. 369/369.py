import sys
input = sys.stdin.readline

n = int(input())
ans = 0

for i in range(1, n+1) :
    letters = [i%10]
    tmp = i
    while (tmp>=10) :
        letters.append(tmp//10)
        tmp = tmp//10
    for letter in letters :
        if letter % 3 == 0 and letter != 0:
            ans += 1
    
print(ans)