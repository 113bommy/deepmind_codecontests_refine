def main():
    d, l, v1, v2 = map(int, input().split())
    left = 0
    right = l

    while right - left > 0.00000001:
        mi = (left + right) / 2
        if v1 * mi + v2 * mi >= l - d:
            right = mi
        else:
            left = mi

    print(right)

if __name__ == "__main__":
    main()