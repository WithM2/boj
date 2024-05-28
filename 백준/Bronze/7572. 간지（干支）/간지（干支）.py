n = int(input()) - 2013

ten = '0123456789'
alphabet = 'ABCDEFGHIJKL'

print(f"{alphabet[(n+5)%12]}{ten[(n+9)%10]}")