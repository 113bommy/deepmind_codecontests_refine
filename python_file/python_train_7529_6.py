def main():
    n = int(input())
    data = []
    s = 0
    for i in range(n):
        vals = [int(v) for v in input().split()]
        data.append(vals)
        s+=sum(vals)
    added = []
    for i in range(1, n, 2):
        if i == n//2:
            continue
        added.append((0, i))
        added.append((n-1, i))
        added.append((i, 0))
        added.append((i,n - 1))
    for x,y in added:
        s-=data[x][y]
    print(s)


if __name__ == "__main__":
    main()
