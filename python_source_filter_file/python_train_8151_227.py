n, k, l, c, d, p, nl, np = map(int, input().strip().split())

print(min((k*l)//n, c*d, p//np)//n)