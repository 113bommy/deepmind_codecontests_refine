x=input()
count=0
count1=0
for i in range (len(x)):
	if x[i]>'a' and x[i]<='z':
		count+=1
	else:
		count1+=1
if count>=count1:
	print(x.lower())
else:
	print(x.upper())
