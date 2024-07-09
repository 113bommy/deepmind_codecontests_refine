s = input()
l = input()
     
count = 0
ind = -1
if set(l).issubset(set(s)):
    for i in range(len(l)):
        ind = s.find(l[i], ind+1)
        if ind == -1:
            count += 1
            ind = s.find(l[i], ind+1)
    print(count*len(s) + ind+1)
 
else:
    print(-1)