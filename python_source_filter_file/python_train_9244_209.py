n = int(input())
l = [int(input()) for _ in range(5)]

print(ceil(n%min(l)) + 4)