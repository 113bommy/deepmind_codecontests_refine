a=int(input())
b=int(input())
c=int(input())
k=(a+b)*c
l=(a+b+c)
m=(b+c)*a
n=a*b*c
list=[]
list.append(k)
list.append(l)
list.append(m)
list.append(n)
list.sort()
print(list[3])