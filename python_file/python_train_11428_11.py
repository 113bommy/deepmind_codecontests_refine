n, x, m = [int(x) for x in input().split()]
A = [x]
while len(A) < n:
    a = (A[-1] * A[-1]) % m
    if a not in A:
        A.append(a)
    else:
        i = A.index(a)
        loop_len = len(A) - i
        print(sum(A[:i]) + sum(A[i:]) * ((n - i) // loop_len) + sum(A[i:i + ((n - i) % loop_len)]))
        break
else:
    print(sum(A))
