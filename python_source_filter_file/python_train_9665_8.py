n=int(input())
s=set()

for i in range(n):
    a=int(input())
    if a in s:
        s.remove(a)
    else:
        s.append(a)

print(len(s))

