I,O,_,J,L,_,_ = map(int,input().split())
ans1 = O + I-I%2 + J-J%2 + L-L%2
ans2 = 0
if I and J and K:
    I,J,K = I-1,J-1,K-1
    ans2 = 3 + O + I-I%2 + J-J%2 + L-L%2
print(max(ans1,ans2))