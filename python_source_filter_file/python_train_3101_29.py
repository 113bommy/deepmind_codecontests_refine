a, b, c = map(float, input().split())
print ("Yes" if 4*a*b < (c-a-b) **2 and c-a-b > 0 else "No")
