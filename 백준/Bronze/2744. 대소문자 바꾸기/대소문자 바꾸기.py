a = input()
ans = []
for i in a:
	if(ord('A')<= ord(i) and ord(i) <=ord('Z')):
		ans.append(chr(ord(i)+32))
	else:
		ans.append(chr(ord(i)-32))
print(''.join(ans))