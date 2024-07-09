N = int(input())
S = input()
ans = 0
for i in range(1,N):
    c = 0
    cc = 0
    for j in range(N-i):
        if S[j] == S[i+j]:
            cc += 1
        else:
            c = max(cc,c)
            cc = 0
    c = max(cc,c)
    c = min(i,c)
    ans = max(ans,c)
print(ans)
