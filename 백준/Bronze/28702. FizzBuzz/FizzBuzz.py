import sys
input = sys.stdin.readline

a = input().strip()
b = input().strip()
c = input().strip()

if a not in ['Fizz', 'Buzz', 'FizzBuzz'] :
    a = int(a)
if b not in ['Fizz', 'Buzz', 'FizzBuzz'] :
    b = int(b)
if c not in ['Fizz', 'Buzz', 'FizzBuzz'] :
    c = int(c)


if a != 'Fizz' and a != 'Buzz' and a != 'FizzBuzz' :
    if (int(a)+3) % 3 == 0 :
        if (int(a)+3) % 5 == 0 :
            print('FizzBuzz')
        else :
            print('Fizz')
    else :
        if (int(a)+3) % 5 == 0 :
            print('Buzz')
        else :
            print(int(a)+3)
    exit()

if b != 'Fizz' and b != 'Buzz' and b != 'FizzBuzz' :
    if (int(b)+2) % 3 == 0 :
        if (int(b)+2) % 5 == 0 :
            print('FizzBuzz')
        else :
            print('Fizz')
    else :
        if (int(b)+2) % 5 == 0 :
            print('Buzz')
        else :
            print(int(b)+2)
    exit()
    
if c != 'Fizz' and c != 'Buzz' and c != 'FizzBuzz' :
    if (int(c)+1) % 3 == 0 :
        if int(c+1) % 5 == 0 :
            print('FizzBuzz')
        else :
            print('Fizz')
    else :
        if (int(c)+1) % 5 == 0 :
            print('Buzz')
        else :
            print(int(c)+1)