for t in range(int(input())):
    r,c=map(int,input().split())
    if((r>2 and c>=2) or (c>2 and r>=2)): print("No")
    else: print("Yes")