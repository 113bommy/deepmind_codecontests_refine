n = int(input())

for i in range(n):
    x = int(input())
    found = False
    for a in range(10):
        for b in range(10):
            if (3*a) + (7*b) == x:
                found = True
                break
        if found:
            print("YES")
            break
    if not found:
        print("NO")
            
