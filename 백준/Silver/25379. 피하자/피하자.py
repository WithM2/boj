n = int(input())
arr = list(map(int, input().split()))

odd_left = 0
even_left = 0

tmp_odd = 0
tmp_even = 0

for i in arr:
    if i % 2 == 0:
        tmp_odd += 1
        even_left += tmp_even
    else:
        tmp_even += 1
        odd_left += tmp_odd
        
print(min(odd_left, even_left))
        