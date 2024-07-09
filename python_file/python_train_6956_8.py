from collections import defaultdict

N = int(input())
S = str(input())

dic = defaultdict(int)

for i in range(2 ** N):
    a = str()
    b = str()
    for j in range(N):
        if (i >> j) & 1:
            a += S[j + N]
        else:
            b += S[j + N]
    
    dic[(a, b)] += 1

count = 0
for i in range(2 ** N):
    a = str()
    b = str()
    for j in range(N):
        if (i >> j) & 1:
            a += S[j]
        else:
            b += S[j]
    count += dic[b[::-1], a[::-1]]

print (count)