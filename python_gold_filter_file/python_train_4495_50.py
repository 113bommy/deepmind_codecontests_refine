s=input()
t=""
k=['a','e','i','o','u','A','E','I','O','U','y','Y']
for i in s:
    if i in k:
        continue
    elif(i.isupper() or i.islower()) and i not in k:
        t=t+"."+i.lower()
        
print(t)        