def main():
    a, b, c, d = map(int, input().split())
    x = max(3 * a // 10, a * c // 250)
    y = max(3 * b // 10, b * d // 250)
    print(('Misha', 'Vasya', 'Tie')[(x < y) + (x == y) * 2])


if __name__ == '__main__':
    main()