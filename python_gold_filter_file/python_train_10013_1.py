a = int(input())
b = int(input())
c = int(input())
if min(a,b,c)==c:
    print(c+1)
else:
    print(min(b,c)-c+min(a,c)+1)
