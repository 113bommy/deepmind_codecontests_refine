a, b = map(int, input().split())
print(0 if a < 6 else (b // 2) if a < 13 else a)