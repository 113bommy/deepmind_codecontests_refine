def main():
    n = int(input())
    a = list(map(int, input().split()))
    a = [((i-1)//n, (i-1) % n) for i in a]
    b = [[min(i, n-i-1, j, n-j-1) for j in range(n)] for i in range(n)]
    sit = [[True for j in range(n)] for i in range(n)]
    ans = 0
    for i, j in a:
        sit[i][j] = False
        ans += b[i][j]
        q = [(i, j, b[i][j])]
        while q:
            x, y, z = q.pop()
            if x != 0:
                if b[x-1][y] > z:
                    b[x-1][y] = z
                    q.append((x-1, y, z+sit[x-1][y]))
            if x != n-1:
                if b[x+1][y] > z:
                    b[x+1][y] = z
                    q.append((x+1, y, z+sit[x+1][y]))
            if y != 0:
                if b[x][y-1] > z:
                    b[x][y-1] = z
                    q.append((x, y-1, z+sit[x][y-1]))
            if y != n-1:
                if b[x][y+1] > z:
                    b[x][y+1] = z
                    q.append((x, y+1, z+sit[x][y+1]))
    print(ans)


main()
