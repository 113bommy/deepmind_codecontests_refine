N, X = map(int, input().split())
m = [int(input()) for _ in range(N)]
print(N + (X - m) // min(m))