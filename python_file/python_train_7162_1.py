from collections import defaultdict
def solve(points):
    N = len(points)
    X = defaultdict(list)
    Y = defaultdict(list)

    for i,(x,y) in enumerate(points):
        X[x].append(i)
        Y[y].append(i)
    
    res = 0
    visited = [False]*N
    for p0 in range(N):
        if visited[p0]:
            continue
        stack = [p0]
        visited[p0] = True
        xx = set()
        yy = set()
        while stack:
            p = stack.pop()
            x,y = points[p]
            xx.add(x)
            yy.add(y)

            for q in X[x]:
                if not visited[q]:
                    visited[q] = True
                    stack.append(q)
            for q in Y[y]:
                if not visited[q]:
                    visited[q] = True
                    stack.append(q)
        res += len(xx)*len(yy)
    return res-N




if __name__ == '__main__':
    N = int(input())
    points = [tuple(map(int,input().split())) for _ in range(N)]
    print(solve(points))