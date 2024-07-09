n = int(input())
x = input()
ans = [0]*(n+1)

for i in range(1,n+1):
    s = format(i, 'b')
    c = s.count('1')
    a = i%c
    ans[i] += 1
    ans[i] += ans[a] 

one_cnt = x.count('1')
numx = int(x,2)

for i in range(n):
    temp = one_cnt
    if x[i]=='0':
        temp += 1
        num = numx%temp + pow(2,n-1-i,temp)
    else:
        if temp>1:
            temp -= 1
            num = numx%temp - pow(2,n-1-i,temp)
        else:
            print(0)
            continue
    print(ans[num%temp]+1)
