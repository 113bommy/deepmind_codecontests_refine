N = int(input())
a = list(map(int, input().split()))
b = [((i + 1) * ai) % 2 for i, ai in enumerate(a)]
print(sum(b))