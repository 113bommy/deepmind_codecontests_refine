x=int(input())
for a in range(150):
    for b in range(-100,100):
        if (a**5 - b**5) == x:
            print(a,b)
            exit()