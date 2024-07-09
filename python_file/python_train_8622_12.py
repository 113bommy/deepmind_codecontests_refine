def is_prime(n):
    if n == 1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n % i == 0:
            return False
    return True
a=[]
for i in range(3,10**5):
  if is_prime(i) and is_prime((i+1)//2):
    a.append(i)
q=int(input())
lr=[list(map(int,input().split())) for _ in range(q)]
for lri in lr:
  print(len([ai for ai in a if ai>=lri[0] and ai<=lri[1]]))