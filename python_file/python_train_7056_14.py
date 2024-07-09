S=input()
q=int(input())
rev=False
pre=''
for i in range(q):
    inp=input()
    if inp[0]=="1":
        rev=not rev
    else:
        t,f,c=inp.split()
        if (f=='1' and rev) or (f=='2' and not rev):
            S+=c
        else:
            pre+=c
if not rev:
    print(pre[::-1]+S)
else:
    print(S[::-1]+pre)