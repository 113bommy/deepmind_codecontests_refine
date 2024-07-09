def is_ok(x):
    result = 0
    for i in range(N):
        a = A[i]
        t = x // F[i]
        if t < a:
            result += a - t
    return result <= K

N,K = map(int,input().split())
A=list(map(int,input().split()))
F=list(map(int,input().split()))
A.sort()
F.sort(reverse=True)
ok=A[-1]*F[0]
ng=-1
while(ng+1<ok):
  c=ng+(ok-ng)//2
  if is_ok(c):
    ok=c
  else:
    ng=c

print(ok)