N, A, B, C, D = map(int, input().split())
S = input()

if "##" in S[A+1:C] or "##" in S[B+1:D]:
  print("No")
  exit()

if D - C < 0:
  if "..." not in S[B-1:D+2]:
    print("No")
    exit()
    
print("Yes")