a, b, k = map(int, input().split())

for i in range(a, b+1):
    if a <= i <= a + k - 1 or b - k + 1 <= i <= b:
        print(i)