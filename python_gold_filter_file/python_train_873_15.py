n,k = map(int,input().split())
res = 0
for i in range(n):
    inp = input()
    ss = 0
    for i in range(k+1):
        if inp.count(str(i)) > 0:
            ss+=1
    if ss >= k+1:
        res+=1
print(res)
