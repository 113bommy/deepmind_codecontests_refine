def go():
    n = int(input())
    a = [ord(i) for i in input()]
    for i in range(1, n):
        if a[i] < a[i - 1]:
            output = "YES\n"
            output += "{} {}".format(i - 1, i)
            return output
    return "NO"

print(go())
