s=')'+input()+'('
i,j=0,1000
a=[]
while i<j:a+=i,j;i=s.find('(',i+1);j=s.rfind(')',0,j)
a=a[2:]
print(int(a>[]),*a and[len(a)]+sorted(a))