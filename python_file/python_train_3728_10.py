X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))


AB = [a + b for a in A for b in B]
AB.sort()
AB = AB[-K:]

ans = [ab + c for ab in AB for c in C]
ans.sort()

for x in ans[-K:][::-1]:
    print(x)
