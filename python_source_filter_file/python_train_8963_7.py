n = int(input())
dic = {}

left = 0
right = 1

for _ in range(n-1):
    pos, num = input().split()
    if pos =='L':
        dic[num] =left
        left -=1
    elif pos == 'R':
        dic[num] = right
        right +=1
    else:
        print("{}".format(min(dic[num]- (left+1) ,right-1-dic[num])))