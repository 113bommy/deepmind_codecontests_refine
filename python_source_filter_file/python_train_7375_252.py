n = int(input())
A = list(map(int,input().split()))
A.sort()
print(sum(A[n:-n]))