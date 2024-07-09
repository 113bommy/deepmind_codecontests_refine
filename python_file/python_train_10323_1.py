import collections

N = int(input())

arr = input()
arr = [int(x) for x in arr.split(' ')]

freq = {}

f = collections.defaultdict(int)
#f[0] = 1

res = 1

for i in range(N):
    num = arr[i]
    if num not in freq:
        freq[num] = 1
    else:
        freq[num] += 1
    
    A = freq[num]
    if A==1:
        f[1] += 1
        f[0] += 1
    else:
        f[A] += 1
        f[A-2] -= 1
    
    
    j = i
    
    A = freq[arr[0]]
    B = f[A]
    #print(A,B)
    if A*B==j:
        res = i+1
    if A==1 and B==j+1:
        res = i+1
        
    A = freq[arr[0]]-1
    B = f[A]
    #print(A,B)
    if A*B==j:
        res = i+1
    
    #print(i,res,'...')
    

print(res)