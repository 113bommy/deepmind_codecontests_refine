n,l = map(int,input().split())
S = [input() for i in range(n)]
S.sort()
print(''.join(S))