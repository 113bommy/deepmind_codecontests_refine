def code(a,b):
    print(((a+b)//3),min(a,b))
	
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        a,b = list(map(int,input().rstrip().split()))
        code(a,b)