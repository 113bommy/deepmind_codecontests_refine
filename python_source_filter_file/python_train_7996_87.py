S = input()
K = int(input())
ans = "1"
for i in range(K):
  if S[i] != "1":
    ans = i
    break
print(ans)