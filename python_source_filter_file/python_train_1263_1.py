b, k = [int(t) for t in input().split(' ')]
a = [int(t) for t in input().split(' ')]

sum2 = 0
ki = 1

for i in range(k):
    sum2 = (sum2 + a[-i-1] * ki) % 2
    ki = (ki * k) % 2

print('odd' if sum2 % 2 == 1 else 'even')