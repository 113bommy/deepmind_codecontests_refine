a, b, c, d = list(map(int, input().split()))

print(max(a*c, a*d, b*d, b*c))