s = input()
m = ord('a')
for i in range(len(s)):
    c = ord(s[i])
    if c > m + 1:
        print("NO")
        exit()
    m = max(m, c)
print("YES")

