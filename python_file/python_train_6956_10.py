from collections import defaultdict

N = int(input())
S = input()
left = S[:N]
right = S[:N-1:-1]

# leftの(blue, red)のパターンを全列挙
br_pattern = defaultdict(int)

for bit in range(1<<N):
    blue = ""
    red = ""
    for isb in range(N):
        if bit & (1<<isb):
            blue = blue + left[isb]
        else:
            red = red + left[isb]
            
    br_pattern[(blue, red)] += 1

# rightの(red, blue)のパターンをひとつずつ調べ、br_patternに一致する数だけansに足す
ans = 0
for bit in range(1<<N):
    red = ""
    blue = ""
    for isr in range(N):
        if bit & (1<<isr):
            red = red + right[isr]
        else:
            blue = blue + right[isr]
            
    ans += br_pattern[(red, blue)]
        
print(ans)