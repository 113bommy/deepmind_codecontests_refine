N = int( input())
A = list( map( int, input().split()))
ans = 10**15
for i in [1, -1]:
    ansi, sums = 0, 0
    for a in A:
        sums += A
        if sums*i <= 0:
            ansi += abs(sums-s)
            sums = s
        s *= -1
    ans = min( ans, ansi)
print(ans)