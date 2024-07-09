n,k = map(int,input().split())
a = [int(input()) for _ in range(n)]
"""
b := ruisekiwa
b[r]-b[l] >= (r-l)k
b[r]-rk >= b[l]-lk (1-indexed)
c := b[i]-ik
"""
b = [0 for _ in range(n)]
b[0] = a[0]
for i in range(1, n):
	b[i] = b[i-1] + a[i]

c = [b[i]-(i+1)*k for i in range(n)]

"""
cr >= cl なる ペア(l, r)の個数を求めたい.
for i in range(n), find (i,j)
"""

class BIT:
	"""
	<Attention> 0-indexed.
	query ... return the sum [0 to m]
	sum ... return the sum [a to b]
	sumall ... return the sum [all]
	add ... 'add' number to element (be careful that it doesn't set a value.)
	search ... the sum version of bisect.right
	output ... return the n-th element
	listout ... return the BIT list
	"""
	def query(self, m):
		res = 0
		while m > 0:
			res += self.bit[m]
			m -= m&(-m)
		return res
	
	def sum(self, a, b):
		return self.query(b)-self.query(a)
	
	def sumall(self):
		bitlen = self.bitlen-1
		return self.query(bitlen)

	def add(self, m, x):
		m += 1
		bitlen = len(self.bit)
		while m <= bitlen-1:
			self.bit[m] += x
			m += m&(-m)
		return
	
	def search(self, a):
		tmpsum = 0
		i = 0
		k = (self.bitlen-1).bit_length()
		while k >= 0:
			tmpk = 2**k
			if i+tmpk <= self.bitlen-1:
				if tmpsum + self.bit[i+tmpk] < a:
					tmpsum += self.bit[i+tmpk]
					i += tmpk
			k = k - 1
		return i+1
	
	def output(self, a):
		return self.query(a+1)-self.query(a)
	
	def listout(self):
		return self.bit
	
	def __init__(self, a):
		self.bitlen = len(a)+1
		self.bit = [0]*(len(a)+1)
		for i, j in enumerate(a):
			self.add(i, j)

def compress(arr):
	*XS, = set(arr)
	XS.sort()
	target = {e: i for i, e in enumerate(XS)}
	rtl = []
	for i in range(n):
		rtl.append(target[arr[i]])
	return rtl

d = compress(c)

bit = BIT([0 for _ in range(n)])
ans = 0
for i in range(n):
	bit.add(d[i], 1)
	ans += bit.sum(0, d[i]+1)
	if c[i] < 0:
		ans -= 1
print(ans)