n,a,b,c,d = map(int, input().split())
S = input()
if "##" in S[a-1:max(c,d)]:
  print('No')
elif c > d and "..." not in S[b-2:min(c,d)+1]:
  print('No')
else:
  print("Yes")