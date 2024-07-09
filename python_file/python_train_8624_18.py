N = int(input())
S = input()
S += S[0:2]

for ans in ['SS','SW','WS','WW']:
    for i in range(1,N+1):
        if (ans[-1] == 'S' and S[i] == 'o') or (ans[-1] == 'W' and S[i] == 'x'):
            ans += ans[-2]
        else:
            ans += ('S' if ans[-2] == 'W' else 'W')
    if ans[:2] == ans[N:]:
        print(ans[:N])
        exit()
print(-1)
