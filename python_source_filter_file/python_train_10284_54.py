K = int(input())
A, B = map(int, input().split())

if A // K == B // K:
  print("NG")
else:
  print("OK")