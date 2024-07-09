n = int(input())
T = list(map(int, input().split()))
t = [0]
for i in range(n):
	t.append(t[-1] + T[i])
v = list(map(int, input().split()))

ans = 0
prev_spped = 0

for x in range(1, 2 * t[-1] + 1):
	time = x / 2
	speeds = [time, t[-1] - time]
	for i in range(n):
		if time <= t[i]:
			speeds.append(v[i] + t[i] - time)
		elif t[i] < time <= t[i + 1]:
			speeds.append(v[i])
		else:
			speeds.append(v[i] + time - t[i + 1])
	speed = min(speeds)
	ans += (speed + prev_spped) * 0.25
	prev_spped = speed

print(ans)