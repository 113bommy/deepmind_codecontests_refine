from math import sqrt, ceil

def main():
	n = int(input())
	if not n%2:
		print(n//2)
		return
	stan = False
	for i in range(3, ceil(sqrt(n)+1)):
		if not n%i:
			n -= i
			print(n//2 + 1)
			return
	print(1)
	return

main()
