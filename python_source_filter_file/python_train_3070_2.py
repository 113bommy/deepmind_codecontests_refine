S=input()
T=input()
k=0
for i in range(len(S)) :
    if S[i]!=T[i] :
        k=k+1
if k%2!=0 :
    print('impossible')
else :
    t=1
    P=''
    for i in range(len(S)) :
        if S[i]==T[i] :
            P=P+S[i]
        else :
            if t==1 :
                P=P+'1'
                t=t+1
            else :
                P=P+'0'
                t=t-1
    print(P)
    
    
