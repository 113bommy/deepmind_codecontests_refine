N = int(input())

a = int(N / 1.08 + 0.9)
b = int(a * 1.08)

if b == N:
   print(a)
else:
   print(":(")