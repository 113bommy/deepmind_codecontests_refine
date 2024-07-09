# = int(input())
# = map(int, input().split())
# = list(map(int, input().split()))
# = list(input())
# = [tuple(map(int, input().split())) for _ in range(n)]

n = int(input())
ab = [tuple(map(lambda x:int(x)-1, input().split())) for _ in range(n-1)]
m = int(input())
uv = [tuple(map(lambda x:int(x)-1, input().split())) for _ in range(m)]

e = [[] for _ in range(n)]
i = 0
for a, b in ab:
    e[a].append([b, i])
    e[b].append([a, i])
    i += 1

def func(x, g, p):
    #print(x, g, p, e[x])
    if len(e[x]) == 1 and p != -1:
        return -1
    for edge in e[x]:
        if edge[0] == p:
            continue
        elif edge[0] == g:
            #print(edge)
            return 1 << edge[1]
        temp = func(edge[0], g, x)
        #print(temp, x, g, p)
        if temp >= 0:
            #print(edge[1])
            return temp + (1 << edge[1])
    return -1

p = []
for u, v in uv:
    p.append(func(u, v, -1))

#print(p)
flag = -1
ans = 2 ** (n-1)
#print(ans)
base = 2 ** (n-1)
for i in range(1, 1 << m):
    temp = list(reversed(list(str(bin(i)))[2:]))
    c = 0
    #print(temp)
    for j, x in enumerate(temp):
        if x == '1':
            c = c | p[j]
    #print(bin(base + c))
    hoge = str(bin(base + c)).count('0') - 1
    if temp.count('1') % 2 == 0:
        flag = 1
    else:
       flag = -1
    ans += flag * (2 ** hoge)
    #flag *= -1
print(ans)
