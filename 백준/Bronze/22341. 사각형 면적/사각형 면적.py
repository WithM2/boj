n, c = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(c)]

width = n
height = n

for i in a:
    x = i[0]
    y = i[1]
    
    if x >= height:
        continue
    if y >= width:
        continue
    
    # print(f'width*x = {width*x}, height*y = {height*y}')
    
    if width * x < height * y:
        width = y
    else:
        height = x
        
    # print(f'change width = {width}, height = {height}')

print(width * height)

