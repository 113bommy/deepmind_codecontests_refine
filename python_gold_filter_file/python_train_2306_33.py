def main():
    n = int(input())
    a = list(map(int, input().split()))

    res = 2 + (a[2] ^ min(a))
    print(res)


if __name__ == '__main__':
    main()
