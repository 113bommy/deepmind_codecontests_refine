N,M,K = map(int,input().split())
ans = 'No'
for n in range(N+1):
    for m in range(M+1):
        tmp = ((N-n)*m + (M-m)*n)
        if tmp==K:
            ans = 'Yes'
print(ans)