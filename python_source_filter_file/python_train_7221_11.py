for i in range(5):
    c=input().split()
    for j in range(5):
        if c[j]=="1":
            print(abs(i-3)+abs(j-3))
