for _ in[0]*int(input()):
 a,b=map(int,input().split());d=abs(a-b);i=int((2*d)**.5-1);s=i*(i+1)//2
 while(s^d)%2or s<d:i+=1;s+=i
 print(i)