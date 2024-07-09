F=lambda:tuple(int(X)for X in input().split());H,W,N=F();S={F()for _ in[0]*N};T=set();Z=[0]*10
for Y,X in S:
	for A in range(9):
		P=A,B=X-A%3,Y-A//3
		if(0<A<W-1)*(0<B<H-1)*(P not in T):T.add(P);Z[sum((B+C//3,A+C%3)in S for C in range(9))]+=1
Z[0]+=(H-2)*(W-2)-sum(Z);print(*Z,sep='\n')