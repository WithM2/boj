n = int(input())
firstDoor = int(input())

if n > 5 :
    print("Love is open door")
else :
    for i in range(1, n):
        print((i+firstDoor)%2)