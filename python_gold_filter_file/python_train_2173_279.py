n, l = map(int, input().split())
s = [input() for i in range(n)]
print(*sorted(s), sep="")