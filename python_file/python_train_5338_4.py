############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
    
n, l = inp(), inlt()

res = []
l.sort()

for i in range((n//2)):
    if i+(n//2) < n:
        res.append(l[i+(n//2)])
        res.append(l[i])

if n % 2:
    res.append(l[-1])
    print(n//2)
else:
    print((n//2) - 1)

print(" ".join([str(x) for x in res]))
