n = int(input())
number = input()

zeros = number.count("1")
ones = number.count("0")
print(n - min(zeros, ones) * 2)
