n, a, b, c, d = map(int, input().split())
s = input()

if '##' in s[a - 1:max(c, d) - 1]:
    print('No')
elif c < d or ('...' in s[b - 2:d]):
    print('Yes')
else:
    print('No')
