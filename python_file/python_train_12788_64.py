a,b,c,d,e,f = map(int,input().split())
A =a* 100
B =b* 100
l = []
for i in range(f//A+1):
    for j in range(f//B+1):
        if i*A+j*B <=f:
            W = i*A+j*B
            s = (W//100)*e
            # print(s)
            r = f - W
            for I in range(s//c+1):
                for J in range(s//d+1):
                    if I*c + J*d<=s and I*c + J*d+W <= f and W>0:
                        S =I*c + J*d
                        l.append([100*S/(W+S),W+S,S])
l.sort()

l = l[::-1]
# print(l[:10])
print(l[0][1],l[0][2])