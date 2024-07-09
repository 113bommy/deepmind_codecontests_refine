import itertools

x,y,z,k = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))

AB = [a + b for (a,b) in list(itertools.product(A,B))]
AB.sort(reverse = True)
ans = [ab + c for (ab,c) in list(itertools.product(AB[:min(3000,x*y*z)],C))]
ans.sort(reverse = True)
for i in range(k):
    print(ans[i])