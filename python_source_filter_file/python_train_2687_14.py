import re

S=input()
ans = sorted((re.findall("[AGCT]*", S), reverse=True, key=len)
print(ans[0])