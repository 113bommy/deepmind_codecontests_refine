from collections import Counter
from collections import defaultdict
import math
t=int(input())
for _ in range(0,t):
    a,b,c=list(map(int,input().split()))
    i=1
    ans=9999999
    stop1=999999
    pairs=[0,0,0]
    while(i<12000):
        j=i
        while(j<12000):
            k=j
            stop1=9999999
            while(k<12000):
                diff=abs(a-i)+abs(b-j)+abs(c-k)
                if(stop1<diff):
                    break
                stop1=diff
                if(diff<ans):
                    stop=diff
                    ans=diff
                    pairs=[i,j,k]
                k=k+j
            j=j+i
        i=i+1
    print(ans)
    print(*pairs)    
