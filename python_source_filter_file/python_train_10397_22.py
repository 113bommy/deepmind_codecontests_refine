N,K = map(int,input().split())
D = input().split()                  

for i in range(N,10001):
    for d in D:
        if d in str(i):
            break
    else:
        break
    continue
print(i)
