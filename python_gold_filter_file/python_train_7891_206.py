s=input()
n=len(s)
print(min((abs(753-int(s[i:i+3])) for i in range(n-2))))
