text = input()

pallin = True

for i in range(len(text)//2) :
    if text[i] != text[-i-1] :
        pallin = False

if pallin == True :
    print(1)
else :
    print(0)