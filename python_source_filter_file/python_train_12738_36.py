n=int(input())
lst=list(range(1,n+1))
i=0
if n!=1:
    while i<len(lst)-1:
        temp=str(lst[i])
        lst[i]=str(lst[i+1])
        lst[i+1]=temp
        i+=1
    print(" ".join(lst))
else:
    print('-1')