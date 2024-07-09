import bisect
import copy

def check(a, b, bar):
    sm = 0
    cnt = 0
    n = len(a)
    for x in a:
        i = bisect.bisect_left(a, bar - x)
        if i == n:
            continue

        cnt += n - i
        sm += b[i] + x * (n-i)
        
    return cnt, sm

n,m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

b = copy.deepcopy(a)
for i,_ in enumerate(b[:-1]):
    b[n-i-2] += b[n-i-1]
    
left = 0
right = b[0] * 2

while right - left > 1:
    middle = ( right + left ) // 2    
    if check(a, b, middle)[0] < m:
        right = middle
    else:
        left = middle
             
print(check(a, b, left)[1] - left * (check(a, b, left)[0]-m) ) 