n = int(input())
s = input()
count = 0
for i in range(0, n):
    if s[i] == s[i-1]:
        count += 1
print(count)
