s=input()
s=s[:-2].strip()
if s[-1] in ("a","e","i","o","u","A","E","I","O","U"):
    print("YES")
else:
    print("NO")