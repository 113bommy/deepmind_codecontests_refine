import sys
input = sys.stdin.buffer.readline

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
cnt = [0] * (m + 1)
cur = [0] * n
done = [0] * (m + 1)
for i in range(n):
	cnt[a[i][0]] += 1
	cur[i] = a[i][0]
ans = max(cnt)
for _ in range(m - 1):
	col = cnt.index(max(cnt))
	done[col] = 1
	for i in range(n):
		if cur[i] == col:
			j = 0
			while done[a[i][j]]:
				j += 1
			t = a[i][j]
			cur[i] = t
			cnt[t] += 1
	cnt[col] = 0
	ans = min(ans, max(cnt))
print(ans)
