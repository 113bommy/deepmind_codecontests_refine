for t in range(int(input())):
    c=0
    for i in range(1,10):
        st=input()
        newst=st[0:c]+str(int(st[c])%9+1)+st[c+1:9]
        print(newst)
        if i%3==0:
            c = c%3+1
        else:
            c = c + 3
