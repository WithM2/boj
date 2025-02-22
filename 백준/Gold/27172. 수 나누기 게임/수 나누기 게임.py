import sys
def input():return sys.stdin.readline().rstrip()

a = int(input())
b = list(map(int,input().split()))
s = set(b)
check = [0 for i in range(1000001)]
for i in range(a):
    x = 1
    while True:
        
        x+=1
        now = x*b[i]
        if now>1000001:
            break
        if now in s:
            check[now] -=1
            check[b[i]] += 1
        
            
for i in b:
    print(check[i],end=" ")
    
