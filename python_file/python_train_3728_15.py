X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = sorted(map(int, input().split()), reverse=True)

AB = [0]*(X*Y)
i = 0
for a in A:
  for b in B:
    AB[i] = a+b
    i += 1
AB.sort(reverse = True)

ans = [0]*(K*Z)
j = 0
for ab in AB[:K]:
  for c in C:
    ans[j] = ab+c
    j += 1

ans.sort(reverse=True)
print(*ans[:K], sep="\n")