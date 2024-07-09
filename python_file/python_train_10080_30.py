s,n=input(),int(input())
ss=[s[i:i+j+1] for i in range(len(s)) for j in range(5)]
print(sorted(set(ss), key=sorted(ss).index)[n-1])