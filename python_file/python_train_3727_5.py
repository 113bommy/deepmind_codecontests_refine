def main():
    N=int(input())
    A=list(map(int, input().split()))
    B=list(map(int, input().split()))

    count = 0
    prev_count = -1
    while count!=prev_count:
        prev_count = count
        for i in range(N):
            d = B[i-1 if i>=1 else N-1] + B[i+1 if i<N-1 else 0]
            c = (B[i]-A[i]) // d
            B[i] -= d * c
            count += c

    if A == B:
        print(count)
    else:
        print(-1)

if __name__ == '__main__':
    main()