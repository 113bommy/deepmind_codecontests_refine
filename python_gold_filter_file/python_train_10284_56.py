K=int(input())
A,B=map(int,input().split())
print("OK" if B-A >= B%K else "NG")