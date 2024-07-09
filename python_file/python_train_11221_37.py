H, N = map(int, input().split())

magic = [tuple(map(int, input().split())) for _ in range(N)]

DP = [0] + [10**9]*H

for h in range(H):
  for damage, mp in magic:
    DP[min(h + damage, H)] = min(DP[min(h + damage, H)], DP[h] + mp)
print(DP[H])