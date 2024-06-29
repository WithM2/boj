n=int(input())
c=list(map(int,input().split()))
if sum(c)!=0:
   while c[0]==0:
       d=c.pop(0)
       c.append(d)
ans=0
a=[0]*n
b=0
for i in c:
   if i==0:
       a[b]+=1
   else:
       b+=1
   ans+=i
for i in a:
   if sum(c)==0:
       ans+=i//2
   else:
       ans+=i//2+i%2
print(ans)