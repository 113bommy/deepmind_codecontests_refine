def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        if n == 1 or m == 1 or (n == 2 and n == 2):
            print("YES")
        else:
            print("NO")
main()