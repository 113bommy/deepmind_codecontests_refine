# Description of the problem can be found at http://codeforces.com/problemset/problem/633/A

a, b, c = map(int, input().split())

for i in range(c // a + (1 if c % a == 0 else 0)):
    for j in range((c - i * a) // b + (1 if (c - i * a) % b == 0 else 0)):
        if (c - i * a - j * b) == 0:
            print("Yes")
            quit()

print("No")