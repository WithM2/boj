a = int(input())
b = list(map(int,input().split()))
c = int(input())
cnt = 0

for i in b:#1 4 1 2 4 2 4 2 3 4 4
	if i==c:
		#cnt=cnt+1
		cnt+=1
print(cnt)
	