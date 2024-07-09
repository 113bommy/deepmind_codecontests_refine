n, p, k, arr, pref = [None]*5

def solve(ind):
	curr = p if ind == -1 else p - pref[ind]
	ans = 0 if ind == -1 else 1
	for i in range(ind+k, n, k):
		if arr[i] <= curr:
			curr -= arr[i]
			ans += k
			if i+k >= n and i+1 < n:
				if arr[i+1] <= curr:
					ans += 1
		else:
			if arr[i-k+1] <= curr:
				curr -= arr[i-k+1]
				ans += 1
			elif i+k >= n and i+1 < n:
				if arr[i+1] <= curr:
					ans += 1
			break
	return ans

def main():
	global n, p, k, arr, pref
	for _ in range(int(input())):
		n, p, k = map(int, input().split())
		arr = list(map(int, input().split()))
		arr.sort()
		pref = [0]*n
		pref[0] = arr[0]
		for i in range(1, n):
			pref[i] = pref[i-1] + arr[i]
		
		ans = 0
		for i in range(-1, k-1):
			if arr[i] > p and i != -1:
				break
			ans = max(ans, solve(i))
		print(ans)
	
 
if __name__ == '__main__':
	main()