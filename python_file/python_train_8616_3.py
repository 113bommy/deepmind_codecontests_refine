def main():
	mod=10**9+7
	k=int(input())
	s=input()
	n=len(s)
	fac=[1]
	for i in range(k+n+1):
		fac.append(fac[-1]*(i+1)%mod)
	def c(x,y):
		r=fac[y]*fac[x-y]%mod
		return fac[x]*pow(r,mod-2,mod)%mod
	ans=0
	for i in range(n,k+n+1):#iはSnの位置
		r=c(i-1,n-1)*pow(25,i-n,mod)*pow(26,n+k-i,mod)%mod
		ans+=r
		ans%=mod
	print(ans)
if __name__ == '__main__':
	main()