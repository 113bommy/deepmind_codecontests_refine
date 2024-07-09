N, M = map(int, input().split())

for i in range(M//N, 0, -1):
  if M % i == 0:
    ans = i
    break
    
print(ans)