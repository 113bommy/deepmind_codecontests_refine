n = int(input())
cnt = 0
c = 0
for i in range(1,n) :
    c += i
    if n - c >= 0 :
        cnt += 1
        n -= c
if n == 1:
    print(1)
else :
    print(cnt)