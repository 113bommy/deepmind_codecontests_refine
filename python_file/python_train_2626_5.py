import math, sys
from collections import defaultdict, Counter, deque

INF = float('inf')
MOD = int(1e9) + 7
MAX = int(2e5) + 1

def solve():
	n, p, k = vars()
	arr = array()
	arr.sort()

	cost = [0 for i in range(n + 1)]
	ans = 0
	pre = 0
	i = 0

	while i < n and pre + arr[i] <= p:
		pre += arr[i]
		i += 1

	ans = i

	for i in range(0, n):
		cost[i + 1] = arr[i]

		if i - k + 1 >= 0:
			cost[i + 1] += cost[i - k + 1]
			if cost[i + 1] <= p:
				ans = max(ans, i + 1)

	print(ans)



def main():
	t = 1 
	t = int(input())
	for _ in range(t):
		solve()
















def gcd(a, b):
	while b:
		a, b = b, a%b
	return a

def input():
	return sys.stdin.readline().rstrip('\n').strip()

def print(*args, sep=' ', end='\n'):
	first = True
	for arg in args:
		if not first:
			sys.stdout.write(sep)
		sys.stdout.write(str(arg))
		first = False 

	sys.stdout.write(end)

def vars():
	return map(int, input().split())
 
def array():
	return list(map(int, input().split()))

if __name__ == "__main__":
	main()
