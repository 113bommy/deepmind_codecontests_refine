n,a,b,c,d=map(int,input().split())
s=input()
if c<d:
    print("No" if "##" in s[a-1:d] else "Yes")
else:
    print("Yes" if "##" not in s[b-1:d] and "..." in s[a-1:c] else "No")