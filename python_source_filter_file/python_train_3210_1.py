a, b, k = map(int, input().split())

for i in range(a, b+1):
    if i <= a+k or b-k+1 <= i:
        print(i)
