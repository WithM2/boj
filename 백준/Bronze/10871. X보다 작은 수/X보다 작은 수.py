N, X = input().split()
N = int(N)
X = int(X)

A = input().split()

for i in range(N):
    A[i] = int(A[i])

for i in range(N):
    if A[i]<X:

        print(A[i],end=" ")
