while True:
 h,w=map(int,input().split())
 if h==0:break
 for _ in range(h):
  print("".join([*]**w))
 print()