
a = int(input())
cnt = 1
if a==1:
	print(1)
	exit()
for i in range(1000000000):
	if cnt>=a:
		print(i)
		break
	cnt = cnt+6*i