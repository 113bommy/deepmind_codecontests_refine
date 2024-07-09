#
import sys
import math

# ひとつ入力
n = int(input())

# initial state
a = [int(i) for i in input().split()] 
# last state
b = [int(i) for i in input().split()] 

answer = 0
answer_p = -1
while answer >= 0:
    answer_p = answer
    for i in range(n):
        tmp = b[(i-1)%n] + b[(i+1)%n]
        if 0 < tmp < b[i] and a[i] < b[i]:
            res = (b[i]-a[i]) // (b[(i+1)%n]+b[(i-1)%n])
            answer += res
            b[i] -= res * (b[(i+1)%n]+b[(i-1)%n])
        
    if answer == answer_p:
        break
#    print(a,b,answer)

for i in range(n):
    if a[i] != b[i]:
        print(-1)
        exit()
print(answer)
