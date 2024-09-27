a = int(input());b = int(input())

ans = 0

if a>0:
	if b>0:
		#1사분면
		ans=1	
	else:
		#4사분면
		ans=4
else:
	if b>0:
		#2사분면
		ans =2
		
	else:
		ans = 3
		#3사분면
print(ans)