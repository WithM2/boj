a = [0 for i in range(30)]
for i in range(28):
    a[int(input())-1] = 1

for i in range(30):
    if a[i]!=1:
        print(i+1)
    