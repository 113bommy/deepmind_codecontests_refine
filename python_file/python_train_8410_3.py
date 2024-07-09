import sys
input = sys.stdin.readline

N, K = map(int,input().split())
A = list(map(int, input().split()))
sumA = sum(A)

yakusu = []
for i in range(1,int(sumA**0.5)+1):
    if sumA%i==0:
        yakusu.append(i)
        if sumA//i!=i:
            yakusu.append(sumA//i)
yakusu.sort(reverse=True)

for x in yakusu:
    tmp = list(map(lambda y: y%x, A))
    tmp.sort()
    for i in range(N):
        minuscnt = sum(tmp[:i+1])
        pluscnt = x*(N-i-1)-sum(tmp[i+1:])
        if minuscnt%x == pluscnt%x and K >= max(minuscnt,pluscnt):
            print(x)
            sys.exit()
