A, B, C, D = [int(input()) for i in range(4)]
print(sum([500*a+100*b+50*c == D for a in range(A+1) for b in range(B+1) for c in range(C+1)]))