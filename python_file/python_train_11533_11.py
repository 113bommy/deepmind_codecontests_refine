import collections
h, w = map(int, input().split())
ch, cw = map(int, input().split())
dh, dw = map(int, input().split())
s = [input() for _ in range(h)]

ch -= 1
cw -= 1
dh -= 1
dw -= 1

d = collections.deque()
d.append((ch, cw))
visit = set()
x = ch
y = cw
cost = [[-1]*w for _ in range(h)]
cost[ch][cw] = 0

while len(d) > 0:
    x, y = d.popleft()
    if (x, y) not in visit:
        visit.add((x, y))
    else:
        continue
    for i in range(5):
        for j in range(5):
            x_n = x+i-2
            y_n = y+j-2
            if x_n >= 0 and x_n < h and y_n >= 0 and y_n < w:
                if s[x_n][y_n] == '.' and (x_n, y_n) not in visit:
                    if pow(i-2, 2)+pow(j-2, 2) == 1:
                            d.appendleft((x_n, y_n))
                            cost[x_n][y_n] = cost[x][y]
                    else:
                        d.append((x_n, y_n))
                        if cost[x_n][y_n] == -1:
                            cost[x_n][y_n] = cost[x][y]+1

print(cost[dh][dw])
