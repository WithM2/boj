n=int(input())
c=list(map(int,input().split()))

ans=0

if sum(c)!=0:
   while c[0]==0:
       d=c.pop(0)
       c.append(d)
else :
    ans += n // 2
    print(ans)
    exit()

a=[0]*n
b=0
for i in c:
   if i==0:
       a[b]+=1
   else:
       b+=1
   ans+=i
for i in a:
       ans+=i//2+i%2
       
print(ans)