n = int(input())

ans = 1

while n!=1 :
    if n >= 2 :
        n //= 2
        ans *= 2
        
print(ans)