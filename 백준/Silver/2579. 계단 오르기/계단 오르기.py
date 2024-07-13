import sys
input = sys.stdin.readline

n = int(input())

stairs = []
stairs.append(0)
for _ in range(n) :
    stairs.append(int(input())) 
    

score = [0, stairs[1]]
if n >= 4:
    score.append(stairs[1] + stairs[2])
    score.append(max(stairs[1] + stairs[3], stairs[2] + stairs[3]))
    score.append(stairs[1] + stairs[4] + max(stairs[2], stairs[3]))
elif n == 3 :
    score.append(stairs[1] + stairs[2])
    score.append(stairs[3] + max(stairs[1], stairs[2]))
    print(score[-1])
    exit()
elif n == 2:
    score.append(stairs[1] + stairs[2])
    print(score[-1])
    exit()
else :
    print(stairs[1])
    exit()


for i in range(5, n+1): 
    max_score = max(score[i-5] + stairs[i-3] + stairs[i-2] + stairs[i], score[i-3] + stairs[i-1] + stairs[i], score[i-4] + stairs[i-2] + stairs[i])
    score.append(max_score)
    
# print(stairs)
print(score[-1])

