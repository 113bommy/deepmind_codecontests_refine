def divisors(M):#Mの約数列 O(n^(0.5+e))
    import math
    d=[]
    i=1
    while math.sqrt(M)>=i:
        if M%i==0:
            d.append(i)
            if i**2!=M:
                d.append(M//i)
        i=i+1
    d.sort()
    return d

def Ind(b,n):
    count=0
    while n%b==0:
        count+=1
        n//=b
    return count

N=int(input())
X=input()
x=0
for i in range(N):
    x=2*x+int(X[i])

a=Ind(2,N)
n=N//(2**a)
d=divisors(n)
data={i*2**(a+1):0 for i in d}
mod=998244353

for i in d:
    Q=((2**(i*2**a)+1)*(x+1))//(2**N+1)
    Q%=mod
    data[i*2**(a+1)]+=Q
    data[i*2**(a+1)]%=mod


for i in d:
    for j in d:
        if i>j and i%j==0:
            data[i*2**(a+1)]-=data[j*2**(a+1)]
            data[i*2**(a+1)]%=mod


ans=0
for i in data:
    ans+=data[i]*i
    ans%=mod
print(ans)