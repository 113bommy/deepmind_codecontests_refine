A,B=map(int,input().split());S=input()
print('Yes' if S[:A].isdigit() and S[A]=='-' and S[B:].isdigit() else 'No')