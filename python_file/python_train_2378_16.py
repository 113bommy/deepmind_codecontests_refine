from collections import defaultdict, deque

N, M = map(int, input().split())

dic = defaultdict(set)
for _ in range(M):
    A, B = map(int, input().split())
    dic[A].add(B)
    dic[B].add(A)


colors = [0]*(N+1)

def dfs():
    que = deque([(1, 1)])

    while len(que):
        v, color = que.popleft()
        colors[v] = color
        for to in list(dic[v]):
            if (color == colors[to]):
                return False
            if (colors[to] == 0):
                que.append((to, -color))
                
    return True


flag = dfs()
b = colors.count(1)

print(b*(N-b) - M if (flag) else N*(N-1)//2 - M)
