from math import sqrt
def crosscircle(c1, c2):
    (x1, y1, r1) = c1
    (x2, y2, r2) = c2
    if (x1-x2)**2 + (y1-y2)**2 > (r1+r2)**2:
        return ()
    elif x1 == x2 and y1 == y2:
        return ()
    elif (x1-x2)**2 + (y1-y2)**2 == (r1+r2)**2:
        x = (x1*r2+x2*r1)/(r1+r2)
        y = (y1*r2+y2*r1)/(r1+r2)
        return ((x, y),)
    elif y1 == y2:
        x = (r1**2-r2**2-x1**2+x2**2)/(2*(x2-x1))
        if y1**2-(y1**2-r1**2+(x-x1)**2) >= 0:
            yans1 = y1+sqrt(y1**2-(y1**2-r1**2+(x-x1)**2))
            yans2 = y1-sqrt(y1**2-(y1**2-r1**2+(x-x1)**2))
            return ((x, yans1), (x, yans2))
        else:
            return ()
    elif x1 == x2:
        y = (r1**2-r2**2-y1**2+y2**2)/(2*(y2-y1))
        if x1**2-(x1**2-r1**2+(y-y1)**2) >= 0:
            xans1 = x1+sqrt(x1**2-(x1**2-r1**2+(y-y1)**2))
            xans2 = x1-sqrt(x1**2-(x1**2-r1**2+(y-y1)**2))
            return ((xans1, y), (xans2, y))
        else:
            return ()
    else:
        A = ((x1-x2)/(y1-y2))**2 + 1
        B = (x1-x2)*(r1**2-r2**2-x1**2+x2**2+(y1-y2)**2)/(y1-y2)**2 - 2*x1
        C = ((r1**2-r2**2-x1**2+x2**2+(y1-y2)**2)/(2*(y1-y2)))**2 + x1**2 - r1**2
        if B**2 - 4*A*C >= 0:
            xans1 = (-B+sqrt(B**2-4*A*C))/(2*A)
            xans2 = (-B-sqrt(B**2-4*A*C))/(2*A)
            yans1 = -((r1**2-r2**2-x1**2+x2**2-y1**2+y2**2))/(2*(y1-y2))-xans1*(x1-x2)/(y1-y2)
            yans2 = -((r1**2-r2**2-x1**2+x2**2-y1**2+y2**2))/(2*(y1-y2))-xans2*(x1-x2)/(y1-y2)
            return ((xans1, yans1), (xans2, yans2))
        else:
            return ()

N, K = map(int, input().split())
li = [tuple(map(int, input().split())) for i in range(N)]
eps = 1e-6
U = 2e05
L = 0
while U - L > 1e-6:
    T = (U+L)/2
    points = []
    for i in range(N-1):
        for j in range(i+1, N):
            c1 = (li[i][0],li[i][1],T/li[i][2])
            c2 = (li[j][0],li[j][1],T/li[j][2])
            p = crosscircle(c1,c2)
            if p == ():
                continue
            for a in p:
                points.append(a)
    for i in range(N):
        points.append((li[i][0], li[i][1]))
    Max = 0
    for p in points:
        cnt = 0
        for i in range(N):
            x,y,r = li[i][0],li[i][1],T/li[i][2]
            if (p[0]-x)**2+(p[1]-y)**2<= (r+eps)**2:
                cnt += 1
        Max = max(Max, cnt)
    if Max < K:
        L = T
    else:
        U = T
print(T)