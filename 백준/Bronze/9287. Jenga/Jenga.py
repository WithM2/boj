testcase = int(input())

for _ in range(testcase):
    print(f"Case {_+1}: ", end="")
    n = int(input())
    jenga = [input().strip() for _ in range(n)]
    standing = True
    for block in jenga:
        if block[1] == '1' :
            continue
        else :
            if block[0] == '0' or block[2] == '0' :
                print("Fallen")
                standing = False
                break
    if standing :
        print("Standing")
        
                
    