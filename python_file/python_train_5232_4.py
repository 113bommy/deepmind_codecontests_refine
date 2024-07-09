test_case = int(input())
for _ in range(test_case):
    input()
    arr = list(map(int, input().split()))
    brr = sorted(arr)
    crr = [0]*(len(arr)+1)
    for i in arr:
        index = brr.index(i)
        crr[index] = 1 + crr[index-1]
    print(len(arr)-max(crr))
