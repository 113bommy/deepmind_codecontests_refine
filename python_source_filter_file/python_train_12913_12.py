import sys

Target = ""
for line in sys.stdin:
    Target += line
for i in range(26):
    print(chr(i + 97), ":", Target.count(chr(i + 97)))