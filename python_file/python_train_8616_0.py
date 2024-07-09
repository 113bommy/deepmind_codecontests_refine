k=int(input())
s,m,c,a=input(),10**9+7,1,1
for i in range(k):c*=25*(k+len(s)-i)*pow(i+1,m-2,m)%m;c%=m;a+=c
print(a%m)