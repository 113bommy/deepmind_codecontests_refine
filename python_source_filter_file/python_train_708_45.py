a,b=map(int,input().split())
s=input()
print("Yes" if s[a]=="-" and s.replace("-","").isdigit() else "No")