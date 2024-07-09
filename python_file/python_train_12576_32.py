n = int(input())
ss = [input() for i in range(n)]
ans = 0
a,b,ab = 0,0,0
for s in ss:
    ans += s.count('AB')
    if s[0] is 'B' and s[-1] is 'A':
        ab += 1
    elif s[0] is 'B':
        a += 1
    elif s[-1] is 'A':
        b += 1
m = min(a,b)
if ab != 0:
    if a+b>0:
        print(ans+ab+m)
    else:
        print(ans+ab-1)
else:
    print(ans+m)
