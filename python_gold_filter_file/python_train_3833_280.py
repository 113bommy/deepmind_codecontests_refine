a, b, c = map(int, input().split())
print(b+c if a+b+1>=c else a+2*b+1)