import sys
input = sys.stdin.readline

n = int(input().strip())
solution = list(map(int, input().strip().split()))

left = 0
right = n - 1
result = []

min_val = 2000000002

while left < right :
    sum = solution[left] + solution[right]
    if min_val > abs(sum) :
        min_val = abs(sum)
        result = [solution[left], solution[right]]
    
    if sum == 0 :
        break
    if sum < 0 :
        left += 1
    else :
        right -= 1

print(result[0], result[1])