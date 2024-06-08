a=list(map(str, input()))
b=[-1]*26
c='abcdefghijklmnopqrstuvwxyz'
for i in range(len(a)):
   for j in range(26):
       if a[i]==c[j]:
           if b[j]==-1:
               b[j]=i


for i in range(26):
   print(b[i], end=" ")
