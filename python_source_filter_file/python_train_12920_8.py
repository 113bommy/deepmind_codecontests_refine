from sys import stdin
input = stdin.readline

def is_good(arr):
    digit = False
    upper = False
    lower = False
    for c in arr:
        if c.isdigit():
            digit = True
        elif c.isupper():
            upper = True
        else:
            lower = True
    return (digit and upper and lower)

def solve():
    s = list(input().rstrip())
    
    # length 0
    if is_good(s):
        print(*s, sep="")
        return
    
    # length 1
    for i in range(len(s)):
        x = s[i]
        s[i] = "1"
        if is_good(s):
            print(*s, sep="")
            return
        s[i] = "a"
        if is_good(s):
            print(*s, sep="")
            return
        s[i] = "A"
        if is_good(s):
            print(*s, sep="")
            return
        s[i] = x
        
    # length 2
    for i in range(len(s)-1):
        x = s[i]
        y = s[i+1]
        s[i] = "1"
        s[i] = "a"
        if is_good(s):
            print(*s, sep="")
            return
        s[i] = "1"
        s[i] = "A"
        if is_good(s):
            print(*s, sep="")
            return
        s[i] = "a"
        s[i] = "A"
        if is_good(s):
            print(*s, sep="")
            return
        s[i] = x
        s[i] = y

t = int(input())
for _ in range(t):
    solve()