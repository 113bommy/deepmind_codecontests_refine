'''input
5
1000000000 1000000000 1000000000 1000000000 1000000000

'''
mod = 998244353
def cal(a,b,n):
	arr_a = list(map(int,str(a)))
	arr_b = list(map(int,str(b)))
	ans_a = ""
	for i in range(len(arr_a)):
		ans_a+= str(arr_a[i])+"0"
	ans_b = ""
	for i in range(len(arr_b)):
		ans_b+= "0"+str(arr_b[i])
	ans_a = int(ans_a)%mod
	ans_b = int(ans_b)%mod
	return (ans_a+ans_b)%mod
if __name__=="__main__":
	n = int(input())
	arr = list(map(int,input().split()))
	ans = 0
	for i in range(n):
		ans = (cal(arr[i],arr[i],n)+ans)%mod
	ans = (ans*(n%mod))%mod
	print(ans)