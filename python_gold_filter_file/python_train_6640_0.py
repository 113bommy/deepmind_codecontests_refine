N=int(input())
A=list(map(int,input().split()))
print("APPROVED" if all([i%2!=0 or i%3==0 or i%5==0 for i in A]) else "DENIED")