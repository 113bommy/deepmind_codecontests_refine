d1, d2, d3 = (int(num) for num in input().split())

print(min(2 * (d1+d2), d1 + d2 + d3, 2 * (d1+d2), 2 * (d2 + d3)))