num = input()
num = int(num)
lst = []
i = 1
count = 0
index = -1

while (count<num):
    strI = str(i)
    strI = list(strI)
    for n in range(0,len(strI)):
        lst.append(strI[n])
    if(i>=1000):
        count+=4
    elif(i>=100):
        count+=3
    elif(i>=10):
        count+=2
    else:
        count+=1
    i+=1

if count != num:
    diff = count - num
    index -= diff

ans = (lst[index])
finalAns = ''.join(ans)
print(finalAns)
