a=list(map(int,input().split()))
b=int(input())
print(sum(a)-max(a)+(max(a)*2**b))