n = int(input())
pieces = list(map(int, input().split()))
pieces.sort()
done = False
for i in range(0, len(pieces)-2):
    if (pieces[i+2] < pieces[i+1] + pieces[i]):
        print("YES")
        done = True
        break
if not done:
    print("NO")

