x = int(input())
m =0
for i in range(2,11):
    m=max(m,int(((x**(1/i)+0.000001)//1)**i))
print(m)
