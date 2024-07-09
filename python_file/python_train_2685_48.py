from fractions import gcd
def lcm(a, b):
    return a * b // gcd(a, b)
N, M = map(int, input().split())
B = set(map(lambda x: int(x)//2, input().split()))
power = 1
for b in B:
    power = lcm(power, b)

mn = min(B)
p2 = power // mn

if p2 % 2 == 0:
    print(0)
    exit()
ans1 = M // mn // p2
ans2 = M // mn // (p2 * 2)
print(ans1-ans2)
