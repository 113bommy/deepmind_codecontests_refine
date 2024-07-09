import sys
input = sys.stdin.readline
input = sys.stdin.buffer.readline


def RD(): return sys.stdin.read()
def II(): return int(input())
def MI(): return map(int,input().split())
def LI(): return list(map(int,input().split()))
def TI(): return tuple(map(int,input().split()))

# mod=10**9+7
# rstrip().decode('utf-8')

#import numpy as np
from itertools import combinations

def main():
	n,k=MI()
	ans=10**18

	A=LI()
	A=[A[0]-1]+A

	for t in combinations(range(n),k):
		B=A.copy()
		tmp=0
		for i in t:
			i+=1
			B[i]=max(max(B[:i])+1,A[i])
			tmp+=B[i]-A[i]
		ans=min(ans,tmp)
	print(ans)

if __name__ == "__main__":
	main()
