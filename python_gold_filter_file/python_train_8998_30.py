s=input()
val=int(s)
ans=1+2**(val%4)+3**(val%4)+4**(val%4)
print(ans%5)