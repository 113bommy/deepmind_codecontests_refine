n = int(input())

days = list(map(int, input().split()))
limit = sum(days) / 2

current = 0

for index, day in enumerate(days):
    current += day

    if current >= limit:
        print(index + 1)
        break
